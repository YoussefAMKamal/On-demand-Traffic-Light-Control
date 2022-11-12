/*
 * button.h
 *
 * Created: 06-Nov-22 8:20:13 PM
 *  Author: Ghost
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

// Including Files
#include "../../EUCAL/DIO Driver/DIO.h"

// Macros
#define BUTTON_PIN	PIN2			// Button pin
#define BUTTON_PORT PORT_D			// Button port

// Functions Prototypes
void BUTTON_Init(uint8_t buttonPort, uint8_t buttonPin);
void BUTTON_Read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value);

#endif /* BUTTON_H_ */