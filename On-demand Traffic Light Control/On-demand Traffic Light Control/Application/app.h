/*
 * app.h
 *
 * Created: 06-Nov-22 2:36:58 PM
 *  Author: Ghost
 */ 


#ifndef APP_H_
#define APP_H_

// Including Files
#include "../HAL/LED Driver/led.h"
#include "../HAL/Button Driver/button.h"

// Functions Prototypes
void APP_Init(void);
void APP_Start(void);

void PEDESTRIAN_FLAG_AT_YELLOW_OR_GREEN(uint8_t isDown);
void PEDESTRIAN_FLAG_AT_RED(void);

#endif /* APP_H_ */