/**************************************************
*  @file     Calculate.h
*
*  @author   Group Alpha
*
*  @date     4/12/2018 10:30 PM
*
**************************************************/
#ifndef __CALCULATOR_BASE_H__
#define __CALCULATOR_BASE_H__
#include "Calculator.h"
#include "Basic_Calc.h"
#include "Adv_Calc.h"
#include "Stopwatch.h"
#include "LCD.h"
#include "Keypad.h"
#include "delay.h"

void  getStarted   (void);
char  scanKeypad  (void);
void  errorEntry   (void);
void  store        (volatile float, float*);
float memfinalize  (float*);

#endif