/*
 * interrupt.h
 *
 * Created: 07-Nov-22 10:45:07 PM
 *  Author: Ghost
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// Including Files
#include "registers.h"

// Enable interrupt
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")

// External Interrupt Request 0
#define INT0_vect  __vector_1

// Rising edge
#define RISING_EDGE() MCUCR |= (1<<ISC01) | (1<<ISC00)

// Setup use INT0
#define SETUP_INT0() SET_BIT(GICR,INT0)

// ISR
#define ISR(vector1)\
	void vector1 (void) __attribute__ ((signal,used));\
	void vector1 (void)


#endif /* INTERRUPT_H_ */