/**************************************************
*  @file     Basic_Calc.h
*
*  @author   Group Alpha
*
*  @date     11/12/2018 12:30 AM
*
**************************************************/
#ifndef __BASIC_CALC_H__
#define __BASIC_CALC_H__
#include "Calculator_Base.h"
#include "LCD.h"
#include "Keypad.h"
#include "LEDs.h"
#include "delay.h"

void calc         (void);
void start_calc   (void);
void fini_calc    (float);
void map          (void);
void add          (float, float);
void sub          (float, float);
void mult         (float, float);
void divi         (float, float);
void clear_data   (void);

#endif
