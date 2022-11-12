/*
 * BIT_Math.h
 *
 * Created: 06-Nov-22 10:59:25 AM
 *  Author: Ghost
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

//Bit Math
#define SET_BIT(REG,BIT)	REG |= (1 << BIT)				// set state -> write bit 0 or 1
#define CLEAR_BIT(REG,BIT)	REG &= ~(1 << BIT)				// clear bit
#define TOGGEL_BIT(REG,BIT) REG ^= (1 << BIT)				// toggle bit between 0 and 1
#define GET_BIT(REG,BIT)	((REG & (1 << BIT)) >> BIT)		// get state -> read bit 0 or 1

#endif /* BIT_MATH_H_ */