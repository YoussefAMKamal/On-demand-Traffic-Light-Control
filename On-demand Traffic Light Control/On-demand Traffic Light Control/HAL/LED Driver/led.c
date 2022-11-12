/*
 * led.c
 *
 * Created: 06-Nov-22 2:43:29 PM
 *  Author: Ghost
 */ 

#include "led.h"

// Initializing Led
void LED_Init(uint8_t ledPort, uint8_t ledPin) 
{
	DIO_Init(ledPin, ledPort, OUT);
}

// Turn Led On
void LED_ON(uint8_t ledPort, uint8_t ledPin)
{
	DIO_Write(ledPin, ledPort, HIGH);
}

// Turn Led Off
void LED_OFF(uint8_t ledPort, uint8_t ledPin)
{
	DIO_Write(ledPin, ledPort, LOW);
}

// Toggling Led
void LED_Toggle(uint8_t ledPort, uint8_t ledPin)
{
	DIO_Toggle(ledPin, ledPort);
}
