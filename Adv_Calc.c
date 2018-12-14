/****************************************************
*  @file    Adv_Calc.c
*
*  Functions to
*
*  @author  Group Alpha
*
*  @date    11/12/2018 11:00 PM
*
****************************************************/ 
#include "Adv_Calc.h"

float mem1[10]  = {0};
float result1   = 0;
float num11     = 0;
volatile unsigned char key2;
volatile float floatkey1;


/**
*  @detailed  
*
*  @param     
*/
void start_trig(void)
{
  LCD_command(DISPLAY_ON_CURSOR_ON);
  delay_ms(50);
  LCD_command(CLEAR_DISPLAY);
  delay_ms(50);
  LCD_command(CLEAR_DISPLAY);
  delay_ms(50);
  LCD_command(CLEAR_DISPLAY);
  delay_ms(50);
  LCD_command(CLEAR_DISPLAY);
  LED_blue();
  LCD_command(CURSOR_START_1ST_LINE);
  LCD_printString("Enter Value:");
  LCD_command(CURSOR_START_2ND_LINE);
  LCD_command(DISPLAY_ON_CURSOR_BLINK);
}


/**
*  @detailed  
*
*  @param     
*/
void trig_menu(void)
{
  LCD_command(CLEAR_DISPLAY);
  LCD_command(DISPLAY_OFF_CURSOR_OFF);
  LCD_setcursorRowCol(0,0);
  LCD_printString("Please Select:");
  
  LCD_setcursorRowCol(1,0);
  LCD_printString("1 -> Sin()");
 
  LCD_setcursorRowCol(2,0); 
  LCD_printString("2 -> Cos()");
  
  LCD_setcursorRowCol(3,0); 
  LCD_printString("3 -> Tan()");
}


/**
*  @detailed  
*
*  @param     
*/
void trig(void)
{
  char c = 0;
  trig_menu();
  c = scanKeypad();
  switch (c)
  {
  case '1':
    start_trig();
    do_trig('s');
    break;
  case '2':
    start_trig();
    do_trig('c');
    break;
  case '3':
    start_trig();
    do_trig('t');  
    break;
  default:
    errorEntry();
    trig();
  }
}


/**
*  @detailed  
*
*  @param     
*/
void do_trig(char c)
{
  while(1)
  {
    key2 = keypad_getkey();
    if(key2 != '.')
    {
      if( key2 == '=')
      {
        LCD_data(key2);
        num11 = memfinalize(mem1);
        num11 = ((float)num11 / 180 ) * ((float)22/7);
        switch(c)
        {
        case 's':
          result1 = sin(num11);
          fini_trig(result1);
          break;
        case 'c':
          result1 = cos(num11);
          fini_trig(result1);
          break;
        case 't':
          result1 = tan(num11);
          fini_trig(result1);
          break;
        }
        clear_data1();
      }
      else
      {
        LCD_data(key2);
        floatkey1 = key2 - 48;       //////////ASCI Compensation
        store(floatkey1, mem1);
      }
      delay_ms(500);
    }
    else if(key2 == '.')
    {
      clear_data1();
      delay_ms(50);
      clear_data1();
      delay_ms(50);
      clear_data1();
      delay_ms(50);
      clear_data1();
      delay_ms(500);
      trig();
    }        
  }
}


/**
*  @detailed  
*
*  @param     
*/
void fini_trig(float result1)
{
  LCD_command(DISPLAY_ON_CURSOR_OFF);
  LCD_command(CURSOR_START_3RD_LINE);
  LCD_printFloat(result1);
  LED_green();
  LCD_command(CURSOR_START_4TH_LINE);
  LCD_printString("Press * to back");
}

void clear_data1()
{
  num11      = 0;
  result1    = 0;
  floatkey1  = 0;
}