/*
 * On-demand Traffic Light Control.c
 *
 * Created: 06-Nov-22 2:00:12 PM
 * Author : Ghost
 */ 

// Including Files
#include "Application/app.h"

int main(void)
{
    //Initializing Application
	APP_Init();
	
    while (1) 
    {
		// Starting Application
		APP_Start();
    }
}

/*
// Test Function
int main(void)
{
	// Initializing App
	
	// initializing Leds
	LED_Init(LED_CAR, LED_RED);
	LED_Init(LED_PEDESTRIANS, LED_YELLOW);
	
	// initializing Button
	BUTTON_Init(BUTTON_PORT, BUTTON_PIN);
	
	// initializing Timer
	Timer_Init();
	
	// initializing Variables
	uint8_t* state = 0;
	
	while (1)
	{
			
		//	1. Read button input
		//	2. If button is pressed then:
		//		- Yellow led for pedestrians will toggle for 5 sec
		//		- Led off
		//	3- If button not pressed
		//		- Red led for cars will be on for 5 sec
		//		- Led off
			
		BUTTON_Read(BUTTON_PORT, BUTTON_PIN, state);
		if (*state == HIGH)
		{
			for (int i=0;i<20;i++)
			{
				LED_Toggle(LED_PEDESTRIANS, LED_YELLOW);
				Timer_ON(250);
			}
			LED_OFF(LED_PEDESTRIANS, LED_YELLOW);
		} 
		else
		{
			LED_ON(LED_CAR, LED_RED);
			Timer_ON(5000);
			LED_OFF(LED_CAR, LED_RED);
		}
		Timer_ON(3000);
	}
}
*/