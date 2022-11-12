/*
 * timer.c
 *
 * Created: 06-Nov-22 10:51:41 PM
 *  Author: Ghost
 */ 

#include "timer.h"
#include <math.h>

uint32_t initialTime,number_of_flags,number_of_countes;
double tickTime,maxDelay;

void Timer_Init(void)
{
		// Choose timer mode
		TIMER0_COUNTER = 0x00; // Normal mode
}

void Timer_ON(uint16_t mSec)
{
			// Reset counter
			number_of_countes = 0;
			
			tickTime = 256.0/1000.0;		// 256ms/1000 = prescaler/FCPU = time needed for 1 tick
			maxDelay = tickTime*pow(2,8);	// max delay time needed to make a timer of 256 ms
			
			// getting initial time and times of repetition
			if (maxDelay > mSec)
			{
				initialTime = (maxDelay - mSec)/tickTime;
				number_of_flags = 1;
			} 
			else if (maxDelay == mSec)
			{
				initialTime = 0;
				number_of_flags = 1;
			}
			else
			{
				number_of_flags = ceil((double)mSec/maxDelay);
				initialTime = (1 << 8) - ((double)mSec/tickTime)/number_of_flags;
			}
			
			//setting initial value
			TIMER0_CONTROL = initialTime;
			SET_BIT(TIMER0_COUNTER,2);
			
			// Counting the flags
			while(number_of_countes < number_of_flags)
			{
				// Timer start -> setting the clock source
				SET_BIT(TIMER_FLAG,0); // No prescaler
				// stop after one overflow -> 256 micro second
							
				// wait until the overflow flag to be set
				while (GET_BIT(TIMER_FLAG,0) == 0);
							
				// Clear the overflow flag
				SET_BIT(TIMER_FLAG,0);
				number_of_countes++;
			}
			// Timer stop
			TIMER0_COUNTER = 0x00;
}