/****************************************************
*  @file    Stopwatch.c
*
*  Functions to
*
*  @author  Group Alpha
*
*  @date    9/12/2018 10:30 PM
*
****************************************************/ 
#include "Stopwatch.h"


void start_stopwatch (void)
{
  LCD_command(CLEAR_DISPLAY);
  LCD_setcursorRowCol(2, 0);
  LCD_printString("Start-> Hold Key");
  LCD_setcursorRowCol(3, 0);
  LCD_printString("Reset-> Press *");
}

/**
*  @detailed  
*
*  @param     
*/
void stopwatch(void)
{
  start_stopwatch();
  int h = 0, m = 0, s = 0, ss = 0;
  while(1)
  {
    while(h < 10)
    {
      while(m < 60)
      {
        while(s < 60)
        {
          while(ss < 100)
          {
            displayTime(h, m, s, ss);
            delay_ms(10);
            ss++;
            if(keypad_getkey() == '.')
              break;
          }
          s++;
          ss = 0;
//          LED_blueBlink(!x);
//          x = !x;
          if(keypad_getkey() == '.')
            break;
        }
        m++;
        s = 0;
        ss = 0;
        if(keypad_getkey() == '.')
          break;
      }
      h++;
      m = 0;
      s = 0;
      ss = 0;
      if(keypad_getkey() == '.')
        break;
    }
    h = 0;
    m = 0;
    s = 0;
    ss = 0;
    fini_stopwatch();
  }
}


void fini_stopwatch(void)
{
  LCD_command(CLEAR_DISPLAY);
  start_stopwatch();
}