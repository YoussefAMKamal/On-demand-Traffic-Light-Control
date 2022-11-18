/*
 * Interrupt.c
 *
 * Created: 18-Nov-22 3:23:29 PM
 *  Author: Ghost
 */ 

#include "interrupt.h"

uint8_t Button = 0;

// Test
void Test_Interrupt(void)
{
	BUTTON_Init(BUTTON_PORT, BUTTON_PIN);
	LED_Init(LED_PEDESTRIANS, LED_RED);
	sei();
	RISING_EDGE();
	SETUP_INT0();
	LED_ON(LED_PEDESTRIANS, LED_RED);
	if (Button == HIGH)
		{
			LED_OFF(LED_PEDESTRIANS, LED_RED);
			Button = LOW;
		}
	Timer_ON(1000);
}

// ISR(INT0_vect)
// {
// 	Button = HIGH;
// }
