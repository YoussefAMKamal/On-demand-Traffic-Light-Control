/*
 * DIO.h
 *
 * Created: 06-Nov-22 2:20:08 PM
 *  Author: Ghost
 */ 

#ifndef DIO_H_
#define DIO_H_

// Including Files
#include "../../Utlities/BIT_Math.h"
#include "../../Utlities/registers.h"

// Driver Macros
// Port defines
#define PORT_A 'A'
#define	PORT_B 'B'
#define	PORT_C 'C'
#define	PORT_D 'D'

// Direction defines
#define IN	0
#define OUT 1

// Value defines
#define LOW	 0
#define HIGH 1

// Driver Functions Prototypes
void DIO_Init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);	// Initialize dio direction
void DIO_Write(uint8_t pinNumber, uint8_t portNumber, uint8_t status);		// Write data to dio
void DIO_Toggle(uint8_t pinNumber, uint8_t portNumber);						// Toggle dio
uint8_t DIO_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value);	// Read dio

#endif /* DIO_H_ */