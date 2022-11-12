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