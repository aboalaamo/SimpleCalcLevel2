/*************************************************************************************
* Module: Timers Driver																 *
* File Name: Timers.h															 	 *
* Description: Header file for the Timers driver									 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


#ifndef TIMERS_TIMERS_H_
#define TIMERS_TIMERS_H_

typedef enum {
	NORMAL , CTC , PCPWM , FPWM
}Mode_Type;

#define PS_1		1
#define PS_8		8
#define PS_64		64
#define PS_256		256
#define PS_1024		1024

#define NO_OUTPUT		0
#define TOGGLE_OC0		1
#define CLEAR_OC0		2
#define SET_OC0			3

#define CLEAR_UPCOUNTING_SET_DOWNCOUNTING	2
#define SET_UPCOUNTING_CLEAR_DOWNCOUNTING	3

#define CLEAR_COMPARE_SET_TOP	2
#define SET_COMPARE_CLEAR_TOP	3


void Timer0_Init( Mode_Type Mode , uint16 Prescaler , uint8 Output , uint8 Compare_Val);


#endif /* TIMERS_TIMERS_H_ */
