/**************************************************
*  @file     Calculator.h
*
*  @author   Group Alpha
*
*  @date     3/12/2018 11:00 AM
*
**************************************************/
#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
#include "Calculator_Base.h"
#include "LCD.h"
#include "Keypad.h"
#include "LEDs.h"

void calculator_Init       (void);
void calculator_welcomeMsg (void);
void calculator_menu       (void);

#endif