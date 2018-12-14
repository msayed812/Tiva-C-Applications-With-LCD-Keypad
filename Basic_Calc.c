/****************************************************
*  @file    Basic_Calc.c
*
*  Functions that 
*
*  @author  Group Alpha
*
*  @date    11/12/2018 12:10 AM
*
****************************************************/ 
#include "Basic_Calc.h"

//int memcount = 0;
//const int mul[10] = {1 , 10, 100, 1000, 
//                     10000, 100000, 1000000, 
//                     10000000, 100000000, 1000000000};
float mem[10]  = {0};
float result   = 0;
//float num[10]  = {0};
//char sign[9]   = {0};
float num1 = 0;
float num2 = 0;
char opsympo  = '0';
char addition  = '0';
char subtract  = '0';
char multiply  = '0';
char division  = '0';
volatile unsigned char key1;
volatile float floatkey;



/**
*  @detailed  
*
*  @param     
*/
void start_calc (void)
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
  LCD_printString("Let's Go:");
  LCD_command(CURSOR_START_2ND_LINE);
  LCD_command(DISPLAY_ON_CURSOR_ON);
  LCD_command(DISPLAY_ON_CURSOR_BLINK);
}


/**
*  @detailed  
*
*  @param     
*/
//void calc(void)
//{ 
//  start_calc ();
//  int j = 0;
//  int k = 0;
//  while(1)
//  {
//    key1 = keypad_getkey();
//    if      (key1 != '.')
//    {
//      if      (addition == '1')
//      {
//        LCD_data(key1);
//        //sign[k] = '+'; k++;
//        //addition = '0';
//        if(key1 == '=')
//        {
//          num[j] = memfinalize(mem);
//          j++;
//          map();
//          clear_data();
//        }
//        else
//        {
//          floatkey = key1 - 48;       //////////ASCI Compensation
//          store(floatkey, mem);
//        }
//        delay_ms(500);
//      }
//      else if (subtract == '1')
//      {
//        LCD_data(key1);
//        //sign[k] = '-'; k++;
//        subtract = '0';
//        if(key1=='=')
//        {
//          num[j] = memfinalize(mem);
//          j++;
//          map();
//          clear_data();
//        }
//        else
//        {
//          floatkey = key1 - 48;      //////////ASCI Compensation
//          store(floatkey, mem);
//        }
//        delay_ms(500);  
//      }
//      else if (multiply == '1')
//      {
//        LCD_data(key1);
//        //sign[k] = '*'; k++;
//        multiply = '0';
//        if(key1 == '=')
//        {
//          num[j] = memfinalize(mem);
//          j++;
//          map();
//          clear_data();
//        }
//        else
//        {
//          floatkey = key1 - 48;     //////////ASCI Compensation
//          store(floatkey, mem);
//        }
//        delay_ms(500);
//      }
//      else if (division == '1')
//      {
//        LCD_data(key1);
//        //sign[k] = '/'; k++;
//        division = '0';
//        if(key1 == '=')
//        {
//          num[j] = memfinalize(mem);
//          j++;
//          map();
//          clear_data();
//        }
//        else
//        {
//          floatkey = key1 - 48;   //////////ASCI Compensation
//          store(floatkey, mem);
//        }
//        delay_ms(500); 
//      }
//      else 
//      {
//        LCD_data(key1);
//        switch (key1)
//        {         
//      case '=':
//            num[j] = memfinalize(mem);
//            map();
//            clear_data();
//            break;
//      case '+':
//            addition = '1';
//            sign[k] = '+'; k++;
//            num[j] = memfinalize(mem);
//            j++;
//            //delay_ms(500);
//            break;
//      case '-':
//            subtract = '1';
//            sign[k] = '-'; k++;
//            num[j] = memfinalize(mem);
//            j++;
//            //delay_ms(500);
//            break;
//      case '*':
//            multiply = '1';
//            sign[k] = '*';  k++;
//            num[j] = memfinalize(mem);
//            j++;
//            //delay_ms(500);
//            break;
//      case '/':
//            division = '1';
//            sign[k] = '/';  k++;
//            num[j] = memfinalize(mem);
//            j++;
//            //delay_ms(500);
//            break;
//      default:
//          floatkey = key1 - 48;   //////////ASCI Compensation
//          store(floatkey, mem);
//        }
//        delay_ms(500);
//      }
//    }
//    else if (key1 == '.')
//    {
//      start_calc();
//      clear_data();
//      delay_ms(50);
//      clear_data();
//      delay_ms(50);
//      clear_data();
//      delay_ms(50);
//      clear_data();
//    }
//    //delay_ms(500);
//  }
//}

void calc(void)
{ 
  start_calc ();
  while(1)
  {
    key1 = keypad_getkey();
    if      (key1 != '.')
    {
      if      (addition == '1')
      {
        LCD_data(key1);
        if(key1 == '=')
        {
          num2 = memfinalize(mem);
          add(num1,num2);
          clear_data();
        }
        else
        {
          floatkey = key1 - 48;       //////////ASCI Compensation
          store(floatkey, mem);
        }
        delay_ms(500);
      }
      else if (subtract == '1')
      {
        LCD_data(key1);
        if(key1=='=')
        {
          num2 = memfinalize(mem);
          sub(num1, num2);
          clear_data();
        }
        else
        {
          floatkey = key1 - 48;      //////////ASCI Compensation
          store(floatkey, mem);
        }
        delay_ms(500);  
      }
      else if (multiply == '1')
      {
        LCD_data(key1);
        if(key1 == '=')
        {
          num2 = memfinalize(mem);
          mult(num1,num2);
          clear_data();
        }
        else
        {
          floatkey = key1 - 48;     //////////ASCI Compensation
          store(floatkey, mem);
        }
        delay_ms(500);
      }
      else if (division == '1')
      {
        LCD_data(key1);
        if(key1=='=')
        {
          num2 = memfinalize(mem);
          divi(num1,num2);
          clear_data();
        }
        else
        {
          floatkey = key1 - 48;   //////////ASCI Compensation
          store(floatkey, mem);
        }
        delay_ms(500); 
      }
      else 
      {
        LCD_data(key1);
        switch (key1)
        {
      case '+':
            addition = '1';
            num1 = memfinalize(mem);
            break;
      case '-':
            subtract = '1';
            num1 = memfinalize(mem);
            break;
      case '*':
            multiply = '1';
            num1 = memfinalize(mem);
            break;
      case '/':
            division = '1';
            num1 = memfinalize(mem);
            break;
      default:
          floatkey = key1 - 48;   //////////ASCI Compensation
          store(floatkey, mem);
        }
        delay_ms(500);
      }
    }
    else if (key1 == '.')
    {
      start_calc();
      clear_data();
      delay_ms(50);
      clear_data();
      delay_ms(50);
      clear_data();
      delay_ms(50);
      clear_data();
    }
  }
}



/**
*  @detailed  
*
*  @param     
*/
void fini_calc(float result)
{
  LCD_command(DISPLAY_ON_CURSOR_OFF);
  LCD_command(CURSOR_START_3RD_LINE);
  LCD_printFloat(result);
  LED_green();
  LCD_command(CURSOR_START_4TH_LINE);
  LCD_printString("Press * to clear");
}


//void map(void)
//{
//  char isfirst = '1';
//  for(int i = 0; i < 9; i++)
//  {
//    switch(sign[i])
//    {
//    case '+':
//      if (isfirst == '1')
//      {
//        add(num[i], num[i+1]);
//        isfirst = '0';
//      }
//      else
//      {
//        add(result, num[i+1]);
//      }
//      break;
//    case '-':
//      if (isfirst == '1')
//      {
//        sub(num[i], num[i+1]);
//        isfirst = '0';
//      }
//      else
//      {
//        sub(result, num[i+1]);
//      }
//      break;
//    case '*':
//      if (isfirst == '1')
//      {
//        mult(num[i], num[i+1]);
//        isfirst = '0';
//      }
//      else
//      {
//        mult(num[i], num[i+1]);
//      }
//      break;
//    case '/':
//      if (isfirst == '1')
//      {
//        divi(num[i], num[i+1]);
//        isfirst = '0';
//      }
//      else
//      {
//        divi(num[i], num[i+1]);
//      }
//      break;
//    default:
//      fini_calc(result);
//    }
//  }
//  isfirst = '1';
//}


/**
*  @detailed  
*
*  @param     
*/
void add(float num1, float num2)
{
  //result = num[0] + num[1];
  result = num1 + num2;
  fini_calc(result);
}


/**
*  @detailed  
*
*  @param     
*/
void sub(float num1, float num2)
{
  //result = num[0] - num[1];
  result = num1 - num2;
  fini_calc(result);
}


/**
*  @detailed  
*
*  @param     
*/
void mult(float num1, float num2)
{
  //result = num[0] * num[1];
  result = num1 * num2;
  fini_calc(result);
}


/**
*  @detailed  
*
*  @param     
*/
void divi(float num1, float num2)
{
  if(num2 == 0)
  {
    LCD_command(DISPLAY_ON_CURSOR_OFF);
    LCD_command(CURSOR_START_3RD_LINE);
    LCD_errormsg();
    LED_red(); 
    LCD_command(CURSOR_START_4TH_LINE);
    LCD_printString("Press * to clear");
  }
  
  
  else if(num1 == 0)
  {
    LCD_command(DISPLAY_ON_CURSOR_OFF);
    LCD_command(CURSOR_START_3RD_LINE);
    LCD_data('0');
    LED_green();
    LCD_command(CURSOR_START_4TH_LINE);
    LCD_printString("Press * to clear");
  }
  
  
  else
  {
    //result = num[0] / num[1];
    result = num1 / num2;
    fini_calc(result);
  }
}

void clear_data()
{
//  for(int i = 0; i < 10; i++)
//    num[i] = 0;
  num1 = 0;
  num2 = 0;
  result    = 0;
  floatkey  = 0;
  addition  = '0';
  subtract  = '0';
  multiply  = '0';
  division  = '0';
}