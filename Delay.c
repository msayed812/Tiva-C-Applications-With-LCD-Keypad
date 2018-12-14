/****************************************************
*  @file    Delay.c
*
*  Delay Functions by both MilliSecons and MicroSeconds.
*
*  @author  Group Alpha
*
*  @date    2/12/2018 3:30 PM
*
****************************************************/   
#include "delay.h"

/**
*  @detailed   This function delays the code by pooling on the micro controller 
*              for a specific period of time measured upon the fact that the controller
*              is running by speed 16MHZ.
*              Calculating the no cycles needed from the microcontroller to wait no of Milli seconds.
*              
*  @param     time   desired waiting period in MilliSeconds.
*/
void delay_ms(int time)
{
int i, j;
for(i = 0 ; i < time; i++)
  for(j = 0; j < 3180; j++){}
}
 

/**
*  @detailed   This function delays the code by pooling on the micro controller 
*              for a specific period of time measured upon the fact that the controller
*              is running by speed 16MHZ.
*              Calculating the no cycles needed from the microcontroller to wait no of Micro seconds.
*              
*  @param     time   desired waiting period in MicroSeconds.
*/
void delay_us(int time)
{
int i, j;
for(i = 0 ; i < time; i++)
  for(j = 0; j < 3; j++){}
}