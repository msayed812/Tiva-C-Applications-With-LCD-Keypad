/****************************************************
*  @file    LCD.c
*
*  LCD library to send both commands and data to an LCD.
*  generalized library could be used in diffrent types of LCDs.
*
*  @author  Group Alpha
*
*  @date    2/12/2018 6:00 PM
*
****************************************************/   
/*  @Hardware Connentions
*
*  [PB0 - PB7] ->   [BD0 - BD7]   I/O Data Bus.
*  PA5         ->   RS            Register Select.
*  PA6         ->   RW            Read / Write Register.
*  PA7         ->   E             Enable Pin. 
*  
****************************************************/
/*  @important Commands List

*
*    Command  *  Discription         
*  ***********************************
*     0x01    *  Clear display screen
*     0x02    *  Return to home position
*     0x04    *  Shift cursor to left
*     0x06    *  Shift cursor to right
*     0x05    *  Shift display right
*     0x07    *  Shift display left
*     0x08    *  Display off, Cursor off
*     0x0A    *  Display off, Cursor on
*     0x0C    *  Display on , Cursor off
*     0x0E    *  Display on , Cursor on 
*     0x0F    *  Display on , Cursor blinking
*     0x10    *  Shift cursor position to left
*     0x14    *  Shift cursor position to right
*     0x18    *  Shift entire display to left
*     0x1C    *  Shift entire display to right
*     0x20    *  Function set : 4-bit, 1 lines, 5x7 matrix
*     0x28    *  Function set : 4-bit, 2 lines, 5x7 matrix
*     0x30    *  Function set : 8-bit, 1 lines, 5x7 matrix
*     0x38    *  Function set : 8-bit, 2 lines, 5x7 matrix
*     0x80    *  Force cursor to start from 1st line
*     0xC0    *  Force cursor to start from 2nd line
*     0x90    *  Force cursor to start from 3rd line
*     0xD0    *  Force cursor to start from 4th line
*  
****************************************************/
#include "LCD.h"

/**
*  @detailed  This function initialize Port A & B to
*             control a 16x2 LCD.
*
*  @param     All used register names are predefined in the TM4C123GH6PM file.
*/
void LCD_Init(void)
{
// LCD ports' Initialization:
SYSCTL_RCGCGPIO_R |= 0x03;              // enable clock to port A & B
while ((SYSCTL_RCGCGPIO_R&0x03)==0);    //wait for clock to be enabled
GPIO_PORTA_CR_R  |= 0xE0;               // allow changes to all the bits in port A
GPIO_PORTA_DIR_R |= 0xE0;               // set PORTA pin 7-5 as output for control
GPIO_PORTA_DEN_R |= 0xE0;               // set PORTA pin 7-5 as digital pins 
GPIO_PORTB_CR_R  |= 0xFF;                // allow changes to all the bits in port B
GPIO_PORTB_DIR_R |= 0xFF;               // set all PORTB pins as output for data
GPIO_PORTB_DEN_R |= 0xFF;               // set all PORTB pins as digital pins

// LCD Initialization Commands:
delay_ms(20);
LCD_command(FUNC_SET_8BIT_2LINE);
delay_ms(5);
LCD_command(FUNC_SET_8BIT_2LINE);
delay_us(100);
LCD_command(FUNC_SET_8BIT_2LINE);
LCD_command(DISPLAY_OFF_CURSOR_OFF); 
LCD_command(CLEAR_DISPLAY);            
LCD_command(SHIFT_CURSOR_RIGHT) ;   
LCD_command(DISPLAY_ON_CURSOR_ON);         
}


/**
*  @detailed  This function, First allow data pins of the LCD to accept command
*                            then it send this command.
*                            Previously calculated delay periods are used to wait
*                            untill a specific action had been written to the LCD successfully.
*
*  @param     command   varible contains the command to be sent.
*  @param               All used register names are predefined in the TM4C123GH6PM file.
*/
void LCD_command(unsigned int command)
{
  GPIO_PORTA_DATA_R = 0x20;               //set RS to 1 to enable Command Register and RW to low to write to the LCD
  GPIO_PORTB_DATA_R = command;
  GPIO_PORTA_DATA_R = 0x80;
  delay_us(1);
  GPIO_PORTA_DATA_R = 0x00;                  //High to Low pulse to push the command to the LCD
  if (command < 4) 
    delay_ms(2);                          // command 1 and 2 needs up to 1.64ms 
  else             
    delay_us(40);                         // all others 40 us
}


/**
*  @detailed  This function, First allow data pins of the LCD to accept data
*                            then it send this data.
*                            Previously calculated delay periods are used to wait
*                            untill a specific action had been written to the LCD successfully.
*
*  @param     data      varible contains the data to be sent.
*  @param               All used register names are predefined in the TM4C123GH6PM file.
*/
void LCD_data(unsigned char data)
{ 
  GPIO_PORTA_DATA_R = 0x20;               //set RS to 1 to enable Data Register and RW to low to write to the LCD
  GPIO_PORTB_DATA_R = data;
  GPIO_PORTA_DATA_R = 0x80 | 0x20;
  delay_us(1);
  GPIO_PORTA_DATA_R = 0;                  //High to Low pulse to push the data to the LCD
  delay_us(40);
}


void LCD_printInt(int no)
{
  char toprint[4] = {0};
  sprintf(toprint, "%d", no);
  int i = 0;
  while(toprint[i] != '\0')
  {
    LCD_data(toprint[i]);
    i++;
  }
}


void LCD_printFloat(float no)
{
//  char toprint[10];
//  sprintf(toprint, "%f", no);
//  itoa(no, toprint);
  
  int len = snprintf('\0', 0, "%f", no);
  char* toprint = (char *)malloc(len + 1);
  snprintf(toprint, len + 1, "%f", no);
  int j = 0;
  while (j < len - 3 )
  {
    LCD_data(toprint[j]);
    j++;
  }
  free(toprint);
}


void LCD_printString(char* str)
{
  LCD_command(DISPLAY_ON_CURSOR_OFF);
  int i = 0;
  while (str[i] != '\0')
  {
    LCD_data(str[i]);
    i++;
  }
}


void LCD_errormsg(void)
{
  LCD_command(CURSOR_START_3RD_LINE);
  LCD_printString("Math ERROR");
}


//void LCD_cursorblink(void)
//{
//  LCD_command(CURSOR_START_1ST_LINE );
//  LCD_command(DISPLAY_ON_CURSOR_BLINK);
//}


void LCD_setcursorRowCol(unsigned int row, unsigned int col)
{
  int command = 0x00;
  if( row == 0)
  {
    command = 0x80;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }
    if( row == 1)
  {
    command = 0xC0;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }
/*************** Uncomment the following when using 16x4 LCD ****************/
    if( row == 2) 
  {
    command = 0x90;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }
    if( row == 3)
  {
    command = 0xD0;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }
}


void displayTime(int h,int m,int s,int ss)
{
  //LCD_command(CLEAR_DISPLAY);
  LCD_setcursorRowCol(0, 3);
  LCD_printInt(h);
  LCD_setcursorRowCol(0, 4);
  LCD_data(':');
  LCD_setcursorRowCol(0, 5);
  LCD_printInt(m);
  LCD_setcursorRowCol(0, 7);
  LCD_data(':');
  LCD_setcursorRowCol(0, 8);
  LCD_printInt(s);
  LCD_setcursorRowCol(0, 10);
  LCD_data(':');
  LCD_setcursorRowCol(0, 11);
  LCD_printInt(ss);
}


void loading(void)
{
  LCD_command(DISPLAY_ON_CURSOR_OFF);
  for(int i = 9; i < 12; i++)
  {
    LCD_command(CLEAR_DISPLAY);
    LCD_setcursorRowCol(1,2);
    LCD_printString("Loading");
    LCD_setcursorRowCol(1,i);
    LCD_data('.');
    delay_ms(time);
  }
  LCD_command(CLEAR_DISPLAY);
}

/***********************************************/
//char* itoa(int i, char b[])
//{
//    char const digit[] = "0123456789";
//    char* p = b;
//    if(i<0){
//        *p++ = '-';
//        i *= -1;
//    }
//    int shifter = i;
//    do{ //Move to where representation ends
//        ++p;
//        shifter = shifter/10;
//    }while(shifter);
//    *p = '\0';
//    do{ //Move back, inserting digits as u go
//        *--p = digit[i%10];
//        i = i/10;
//    }while(i);
//    return b;
//}