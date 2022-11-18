/*
 * timer.h
 *
 * Created: 06-Nov-22 10:51:51 PM
 *  Author: Ghost
 */ 

#ifndef TIMER_H_
#define TIMER_H_

// Including Files
#include "../../HAL/LED Driver/led.h"

// Macros
#define TIMER_FLAG TIFR
#define TIMER0_COUNTER TCCR0
#define TIMER0_CONTROL TCNT0

// Functions Prototypes
void Timer_Init(void);
void Timer_ON(uint16_t mSec);

// Test
void Test_Timer(void);

#endif /* TIMER_H_ */