/****************************************************
*  @file    Calculator.c
*
*  Integration Function to call all needed subfunctions for inializing 
*  for better user frindly interface.
*
*  @author  Group Alpha
*
*  @date    3/12/2018 11:00 AM
*
****************************************************/  
#include "Calculator.h"

void calculator_Init(void)
{
  keypad_Init();
  LCD_Init();
  portF_Init();
}


void calculator_welcomeMsg(void)
{
  LCD_command(CLEAR_DISPLAY);
  LCD_setcursorRowCol(0,5);
  LCD_printString("WELCOME");
  
  LCD_setcursorRowCol(1,3);
  LCD_printString("Tiva C App");
 
  LCD_setcursorRowCol(2,2); 
  LCD_printString("Group Alpha");
  
  LCD_setcursorRowCol(3,0); 
  LCD_printString("ASU MCT * CSE318");
  
  delay_ms(3000);
  LCD_command(CLEAR_DISPLAY);
}


void calculator_menu(void)
{
  LCD_command(CLEAR_DISPLAY);
  LCD_command(DISPLAY_OFF_CURSOR_OFF);
  LCD_setcursorRowCol(0,0);
  LCD_printString("Please Select:");
  
  LCD_setcursorRowCol(1,0);
  LCD_printString("1 -> Basic Calc");
 
  LCD_setcursorRowCol(2,0); 
  LCD_printString("2 -> Trig Func");
  
  LCD_setcursorRowCol(3,0); 
  LCD_printString("3 -> Stop Watch");
}