/*
 * app.c
 *
 * Created: 06-Nov-22 2:37:11 PM
 *  Author: Ghost
 */ 

#include "app.h"

uint8_t normalMode = LOW;

void APP_Init(void)
{
	// Initialization of cars leds
	LED_Init(LED_CAR, LED_GREEN);
	LED_Init(LED_CAR, LED_YELLOW);
	LED_Init(LED_CAR, LED_RED);
	
	// Initialization of pedestrians leds
	LED_Init(LED_PEDESTRIANS, LED_GREEN);
	LED_Init(LED_PEDESTRIANS, LED_YELLOW);
	LED_Init(LED_PEDESTRIANS, LED_RED);
	
	// Initialization of the button
	BUTTON_Init(BUTTON_PORT, BUTTON_PIN);
	
	// Initialization of timer0
	Timer_Init();
	
	// Initialization of interrupt
	
		// Enable global interrupts - setting bit 7 in the status register to 1
		sei();
	
		// Choose the external interrupt sense - sense on rising edge
		RISING_EDGE();
	
		// Enable External interrupt 0 - INT0
		SETUP_INT0();
}

void APP_Start(void)
{
	// Car Green ON for 5 sec
	LED_ON(LED_CAR, LED_GREEN);
	LED_OFF(LED_CAR, LED_YELLOW);
	for(int i = 0;i < 20;i++)
	{
		Timer_ON(250);
		if (normalMode == HIGH)
		PEDESTRIAN_FLAG_AT_YELLOW_OR_GREEN(LOW);
	}

	// Car Yellow Toggle for 5 sec
	LED_OFF(LED_CAR, LED_GREEN);
	LED_OFF(LED_CAR, LED_RED);
	for(int i = 0;i < 20;i++)
	{
		LED_Toggle(LED_CAR, LED_YELLOW);
		Timer_ON(250);
		if (normalMode == HIGH)
			PEDESTRIAN_FLAG_AT_YELLOW_OR_GREEN(HIGH);
	}
		
	// Car Red ON for 5 sec
	LED_OFF(LED_CAR, LED_YELLOW);
	LED_ON(LED_CAR, LED_RED);
	for(int i = 0;i < 20;i++)
	{
		Timer_ON(250);
		if (normalMode == HIGH)
		PEDESTRIAN_FLAG_AT_RED();
	}
		
	// Car Yellow Toggle for 5 sec
	LED_OFF(LED_CAR, LED_RED);
	for(int i = 0;i < 20;i++)
	{
		LED_Toggle(LED_CAR, LED_YELLOW);
		Timer_ON(250);
		if (normalMode == HIGH)
		PEDESTRIAN_FLAG_AT_YELLOW_OR_GREEN(LOW);
	}
}

ISR(INT0_vect)
{
	normalMode  = HIGH;
}

void PEDESTRIAN_FLAG_AT_YELLOW_OR_GREEN(uint8_t isDown)
{
	// Pedestrian's and  the cars' yellow leds will blink for 5 sec
	LED_OFF(LED_CAR, LED_GREEN);
	LED_ON(LED_PEDESTRIANS, LED_RED);
	for(int i = 0;i < 20;i++)
	{
		LED_Toggle(LED_CAR, LED_YELLOW);
		LED_Toggle(LED_PEDESTRIANS, LED_YELLOW);
		Timer_ON(250);
	}
			
	// Pedestrian's green led and  the cars' red led will be on for 5 sec
	LED_OFF(LED_CAR, LED_YELLOW);
	LED_ON(LED_CAR, LED_RED);
			
	LED_OFF(LED_PEDESTRIANS, LED_YELLOW);
	LED_ON(LED_PEDESTRIANS, LED_GREEN); // Pedestrian's can cross the road
	LED_OFF(LED_PEDESTRIANS, LED_RED);
	Timer_ON(5000);
			
	// Cars' red led will be off
	LED_OFF(LED_CAR, LED_RED);
	
	// Pedestrian's and  the cars' yellow leds will blink for 5 sec
	for(int i = 0;i < 20;i++)
	{
		LED_Toggle(LED_CAR, LED_YELLOW);
		LED_Toggle(LED_PEDESTRIANS, LED_YELLOW);
		Timer_ON(250);
	}
	// Pedestrian green led will be off and both pedestrian red led and cars' green led will be on
	LED_OFF(LED_PEDESTRIANS, LED_GREEN);
	LED_OFF(LED_PEDESTRIANS, LED_YELLOW);
	LED_ON(LED_PEDESTRIANS, LED_RED);
	
	LED_ON(LED_CAR, LED_GREEN);
	LED_OFF(LED_CAR, LED_YELLOW);
	LED_OFF(LED_CAR, LED_RED);
	Timer_ON(5000);
	
	LED_OFF(LED_PEDESTRIANS, LED_RED);
	LED_OFF(LED_CAR, LED_GREEN);
	
	// At first car's led was green of yellow
	if(isDown == HIGH)
	{
		LED_OFF(LED_CAR, LED_RED);
		for(int i = 0;i < 20;i++)
		{
			LED_Toggle(LED_CAR, LED_YELLOW);
			Timer_ON(250);
		}
	}
	normalMode = LOW;
}

void PEDESTRIAN_FLAG_AT_RED(void)
{
	// Pedestrian's green led and  the cars' red led will be on for 5 sec
	LED_ON(LED_PEDESTRIANS, LED_GREEN); // Pedestrian's can cross the road
	Timer_ON(5000);
	LED_OFF(LED_PEDESTRIANS, LED_GREEN);
	normalMode = LOW;
}