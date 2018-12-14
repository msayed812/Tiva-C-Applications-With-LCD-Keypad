/****************************************************
*  @file    LEDs.c
*
*  LEDs interface for better user experience.
*
*  @author  Group Alpha
*
*  @date    4/12/2018 9:00 AM
*
****************************************************/  
#include "LEDs.h"

void portF_Init(void)
{
  SYSCTL_RCGCGPIO_R |= 0x20;            //enable clc for port C & D  
  while ((SYSCTL_RCGCGPIO_R&0x20)==0);  //wait for clock to be enabled
  GPIO_PORTF_LOCK_R = 0x4C4F434B;                    //unlock PORTF
  GPIO_PORTF_CR_R  |= 0x0E;             //allow changes to all the bits in port F
  GPIO_PORTF_DIR_R |= 0x0E;             //set directions cols are o/ps
  GPIO_PORTF_DEN_R |= 0x0E;             //digital enable pins in port F
}

void LED_red(void)
{
  GPIO_PORTF_DATA_R = red;
  delay_ms(delay/4);
  GPIO_PORTF_DATA_R = 0x00;
  delay_ms(delay/4);
  GPIO_PORTF_DATA_R = red;
  delay_ms(delay/4);
  GPIO_PORTF_DATA_R = 0x00;
  delay_ms(delay/4);
  GPIO_PORTF_DATA_R = red;
  delay_ms(delay/4);
  GPIO_PORTF_DATA_R = 0x00;
  delay_ms(delay/2);
  GPIO_PORTF_DATA_R = blue; 
}

void LED_blue(void)
{
  GPIO_PORTF_DATA_R = blue;
}

void LED_green(void)
{
  GPIO_PORTF_DATA_R = green;
  delay_ms(delay);
  GPIO_PORTF_DATA_R = blue;
}

//void LED_blueData(