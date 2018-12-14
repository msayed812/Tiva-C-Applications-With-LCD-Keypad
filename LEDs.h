/**************************************************
*  @file     LEDs.h
*
*  @author   Group Alpha
*
*  @date     4/12/2018 9:00 AM
*
**************************************************/
#ifndef __LEDs_H__
#define __LEDs_H__
#include "tm4c123gh6pm.h"
#include "delay.h"
#define red   (1 << 1)
#define blue  (1 << 2)
#define green (1 << 3)
#define delay 1000

void portF_Init(void);
void LED_green (void);
void LED_green (void);
void LED_green (void);

#endif
