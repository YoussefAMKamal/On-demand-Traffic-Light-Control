/*
 * DIO.c
 *
 * Created: 06-Nov-22 2:19:47 PM
 *  Author: Ghost
 */ 

// Include .h
#include "DIO.h"

// function definitions
void DIO_Init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	switch (portNumber)
	{
		case PORT_A:
			if (direction == IN)
			{
				// DDRA &= ~(1 << pinNumber); // Input -> clear bit
				CLEAR_BIT(DDRA, pinNumber);
			}
			else if (direction == OUT)
			{
				// DDRA |= ~(1 << pinNumber); // Output -> clear bit
				SET_BIT(DDRA, pinNumber);
			}
			else
			{
				//Error handling
			}
			break;
			case PORT_B:
			if (direction == IN)
			{
				// DDRB &= ~(1 << pinNumber); // Input -> clear bit
				CLEAR_BIT(DDRB, pinNumber);
			}
			else if (direction == OUT)
			{
				// DDRB |= ~(1 << pinNumber); // Output -> clear bit
				SET_BIT(DDRB, pinNumber);
			}
			else
			{
				//Error handling
			}
			break;
			case PORT_C:
			if (direction == IN)
			{
				// DDRC &= ~(1 << pinNumber); // Input -> clear bit
				CLEAR_BIT(DDRC, pinNumber);
			}
			else if (direction == OUT)
			{
				// DDRC |= ~(1 << pinNumber); // Output -> clear bit
				SET_BIT(DDRC, pinNumber);
			}
			else
			{
				//Error handling
			}
			break;
			case PORT_D:
			if (direction == IN)
			{
				// DDRD &= ~(1 << pinNumber); // Input -> clear bit
				CLEAR_BIT(DDRD, pinNumber);
			}
			else if (direction == OUT)
			{
				// DDRD |= ~(1 << pinNumber); // Output -> clear bit
				SET_BIT(DDRD, pinNumber);
			}
			else
			{
				//Error handling
			}
			break;
	}
}

void DIO_Write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	switch (portNumber)
	{
		case PORT_A:
		if(value == LOW)
		{
			// PORTA &= ~(1<<pinNumber); // write 0 -> clear bit
			CLEAR_BIT(PORTA, pinNumber);
		}
		else if (value == HIGH)
		{
			// PORTA |= (1<<pinNumber); // write 1 -> set bit
			SET_BIT(PORTA, pinNumber);
		}
		else
		{
			// Error handling
		}
		break;
		case PORT_B:
		if(value == LOW)
		{
			// PORTB &= ~(1<<pinNumber); // write 0 -> clear bit
			CLEAR_BIT(PORTB, pinNumber);
		}
		else if (value == HIGH)
		{
			// PORTB |= (1<<pinNumber); // write 1 -> set bit
			SET_BIT(PORTB, pinNumber);
		}
		else
		{
			// Error handling
		}
		break;
		case PORT_C:
		if(value == LOW)
		{
			// PORTC &= ~(1<<pinNumber); // write 0 -> clear bit
			CLEAR_BIT(PORTC, pinNumber);
		}
		else if (value == HIGH)
		{
			// PORTC |= (1<<pinNumber); // write 1 -> set bit
			SET_BIT(PORTC, pinNumber);
		}
		else
		{
			// Error handling
		}
		break;
		case PORT_D:
		if(value == LOW)
		{
			// PORTD &= ~(1<<pinNumber); // write 0 -> clear bit
			CLEAR_BIT(PORTD, pinNumber);
		}
		else if (value == HIGH)
		{
			// PORTD |= (1<<pinNumber); // write 1 -> set bit
			SET_BIT(PORTD, pinNumber);
		}
		else
		{
			// Error handling
		}
		break;
	}
}

void DIO_Toggle(uint8_t pinNumber, uint8_t portNumber)
{
	switch (portNumber)
	{
		case PORT_A:
		// PORTA ^= (1<<pinNumber); // toggle bit
		TOGGEL_BIT(PORTA, pinNumber);
		break;
		case PORT_B:
		// PORTB ^= (1<<pinNumber); // toggle bit
		TOGGEL_BIT(PORTB, pinNumber);
		break;
		case PORT_C:
		// PORTC ^= (1<<pinNumber); // toggle bit
		TOGGEL_BIT(PORTC, pinNumber);
		break;
		case PORT_D:
		// PORTD ^= (1<<pinNumber); // toggle bit
		TOGGEL_BIT(PORTD, pinNumber);
		break;
	}
}

uint8_t DIO_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value)
{
	switch (portNumber)
	{
		case PORT_A:
			// *value = (PINA & (1<<pinNumber))>>pinNumber; // get state -> read bit 0 or 1
			*value = GET_BIT(PINA, pinNumber);
		break;
		case PORT_B:
			// *value = (PINB & (1<<pinNumber))>>pinNumber; // get state -> read bit 0 or 1
			*value = GET_BIT(PINB, pinNumber);
		break;
		case PORT_C:
			// *value = (PINC & (1<<pinNumber))>>pinNumber; // get state -> read bit 0 or 1
			*value = GET_BIT(PINC, pinNumber);
		break;
		case PORT_D:
			// *value = (PIND & (1<<pinNumber))>>pinNumber; // get state -> read bit 0 or 1
			*value = GET_BIT(PIND, pinNumber);
		break;
	}
	return *value;
}