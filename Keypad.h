/**************************************************
*  @file     Keypad.h
*
*  @author   Group Alpha
*
*  @date     29/11/2018 10:30 PM
*
**************************************************/
#ifndef __KEYPAD_H__
#define __KEYPAD_H__
#include "tm4c123gh6pm.h"
#include "Delay.h"
#define  padRows  4
#define  padCols  4

void keypad_Init       (void);
char keypad_getkey     (void);

#endif