/*
 * led.h
 *
 * Created: 06-Nov-22 2:43:39 PM
 *  Author: Ghost
 */ 


#ifndef LED_H_
#define LED_H_

// Including Files
#include "../../EUCAL/DIO Driver/DIO.h"

//Define Modules
#define LED_GREEN PIN0			// Green Led
#define LED_YELLOW PIN1			// Yellow Led
#define LED_RED PIN2			// Red Led

#define LED_CAR PORT_A			// Led For Cars
#define LED_PEDESTRIANS PORT_B	// Led For Pedestrians

// Functions prototypes
void LED_Init(uint8_t portNumber, uint8_t pinNumber);
void LED_ON(uint8_t ledPort, uint8_t ledPin);
void LED_OFF(uint8_t ledPort, uint8_t ledPin);
void LED_Toggle(uint8_t ledPort, uint8_t ledPin);

#endif /* LED_H_ */