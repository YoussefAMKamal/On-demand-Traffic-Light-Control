/*
 * button.c
 *
 * Created: 06-Nov-22 8:20:25 PM
 *  Author: Ghost
 */ 

#include "button.h"

// Initializing Button
void BUTTON_Init(uint8_t buttonPort, uint8_t buttonPin)
{
	DIO_Init(buttonPin, buttonPort, IN);
}

// Reading Button Input
void BUTTON_Read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value)
{
	DIO_Read(buttonPin, buttonPort, value);
}

void Test_Button(void)
{
	uint8_t* state = 0;
	BUTTON_Init(BUTTON_PORT, BUTTON_PIN);
	LED_Init(LED_PEDESTRIANS, LED_YELLOW);
	BUTTON_Read(BUTTON_PORT, BUTTON_PIN, state);
	if (*state == HIGH)
	{
		LED_ON(LED_PEDESTRIANS, LED_YELLOW);
		Timer_ON(500);
		LED_OFF(LED_PEDESTRIANS, LED_YELLOW);
	} 
}