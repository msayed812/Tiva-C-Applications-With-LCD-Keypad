/****************************************************
*  @file    Calclate.c
*
*  Functions that do mathematical calculations after getting
*  the input numbers from the keypad.
*
*  @author  Group Alpha
*
*  @date    4/12/2018 12:20 AM
*
****************************************************/ 
#include "Calculator_Base.h"


int memcount = 0;
float mem2[10]  = {0};
volatile unsigned char key;


/**
*  @detailed  
*
*  @param     
*/
void getStarted(void)
{
  calculator_menu();
  int c = 0;
  c = scanKeypad();
  switch (c)
  {
  case '1':                         ///Basic Calc
    loading();
    calc();
    break;
  case '2':                       ///Adv Calc
    loading();
    trig();
    break;
  case '3':                      ///Stop Watch
    loading();
    stopwatch();
    break;
  default:
    errorEntry();
    getStarted();
  }
}


/**
*  @detailed  
*
*  @param     
*/
char scanKeypad(void)
{ 
  key = keypad_getkey();
  return key;
}


/**
*  @detailed  
*
*  @param     
*/
void errorEntry(void)
{
  LCD_command(CLEAR_DISPLAY);
  LCD_setcursorRowCol(0,0);
  LCD_printString("WRONG ENTRY!!!");
  LCD_setcursorRowCol(2,0);
  LCD_printString("Try Again...");
  delay_ms(2000);
  LCD_command(CLEAR_DISPLAY);
}


/**
*  @detailed  
*
*  @param     
*/
void store(volatile float no, float* mem2)
{
  *(mem2 + memcount) = no;
  memcount++;
}


/**
*  @detailed  
*
*  @param     
*/
float memfinalize(float* mem2)
{
  const int mul[10] = {1 , 10, 100, 1000, 
                     10000, 100000, 1000000, 
                     10000000, 100000000, 1000000000};
  float memreturn = 0;
  for(int j = 0; j < 10; j++)
  {
    memreturn += ((mem2[j]) * mul[memcount-1]);
    memcount--;
    if(memcount == -1)
      break;
  }
  for(int k = 0; k < 10; k++)
    mem2[k] = 0;
  memcount = 0;
  return memreturn;
}