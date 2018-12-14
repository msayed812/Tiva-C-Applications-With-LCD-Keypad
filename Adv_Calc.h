/**************************************************
*  @file     Adv_Calc.h
*
*  @author   Group Alpha
*
*  @date     11/12/2018 10:30 PM
*
**************************************************/
#ifndef __ADV_CALC_H__
#define __ADV_CALC_H__
#include <math.h>
#include "Calculator_Base.h"
#include "LCD.h"
#include "Keypad.h"
#include "LEDs.h"
#include "delay.h"

void trig         (void);
void trig_menu    (void);
void start_trig   (void);
void do_trig      (char);
void fini_trig    (float);
void clear_data1   (void);

#endif