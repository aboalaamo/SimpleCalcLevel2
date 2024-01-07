/*************************************************************************************
* Module: Timers Driver																 *
* File Name: Timers.c															 	 *
* Description: Source file for Timers driver										 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


/* Includes */

#include <avr/interrupt.h>
#include "../Library/Std_Types.h"
#include "../GPIO/GPIO.h"
#include "Timers.h"


/* Functions Implementation */


/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void Timer0_Init( Mode_Type Mode , uint16 Prescaler , uint8 Output ,uint8 Compare_Val ){
	GPIO_SetPinDirction(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	SREG |= (1<<7);
	TIMSK |= (1<<OCIE0);
	switch(Mode){
		case NORMAL :
			TCNT0 = Compare_Val;
			TCCR0 |= (1<<FOC0);
			TCCR0 &= ~(1<<WGM00);
			TCCR0 &= ~(1<<WGM01);
			break ;
		case CTC :
			OCR0 = Compare_Val ;
			TCCR0 |= (1<<FOC0);
			TCCR0 &= ~(1<<WGM00);
			TCCR0 |= (1<<WGM01);
			break ;
		case PCPWM :
			OCR0 = Compare_Val ;
			TCCR0 &= ~(1<<FOC0);
			TCCR0 |= (1<<WGM00);
			TCCR0 &= ~(1<<WGM01);
			break ;
		case FPWM :
			OCR0 = Compare_Val ;
			TCCR0 &= ~(1<<FOC0);
			TCCR0 |= (1<<WGM00);
			TCCR0 |= (1<<WGM01);
			break ;
		default : return;
	}

	switch(Prescaler){
		case PS_1 :
			TCCR0 |= (1<<CS00);
			TCCR0 &= ~(1<<CS01);
			TCCR0 &= ~(1<<CS02);
			break ;
		case PS_8 :
			TCCR0 &= ~(1<<CS00);
			TCCR0 |= (1<<CS01);
			TCCR0 &= ~(1<<CS02);
			break ;
		case PS_64 :
			TCCR0 |= (1<<CS00);
			TCCR0 |= (1<<CS01);
			TCCR0 &= ~(1<<CS02);
			break ;
		case PS_256 :
			TCCR0 &= ~(1<<CS00);
			TCCR0 &= ~(1<<CS01);
			TCCR0 |= (1<<CS02);
			break ;
		case PS_1024 :
			TCCR0 |= (1<<CS00);
			TCCR0 &= ~(1<<CS01);
			TCCR0 |= (1<<CS02);
			break ;
		default : return ;
	}

	if( Mode == NORMAL || Mode == CTC ){
		switch(Output){
			case NO_OUTPUT :
				TCCR0 &= ~(1<<COM00);
				TCCR0 &= ~(1<<COM01);
				break ;
			case TOGGLE_OC0 :
				TCCR0 |= (1<<COM00);
				TCCR0 &= ~(1<<COM01);
				break ;
			case CLEAR_OC0 :
				TCCR0 &= ~(1<<COM00);
				TCCR0 |= (1<<COM01);
				break ;
			case SET_OC0 :
				TCCR0 |= (1<<COM00);
				TCCR0 |= (1<<COM01);
				break ;
			default : return ;
		}
	}
	else if( Mode == PCPWM ){
		switch(Output){
			case NO_OUTPUT :
				TCCR0 &= ~(1<<COM00);
				TCCR0 &= ~(1<<COM01);
				break ;
			case CLEAR_UPCOUNTING_SET_DOWNCOUNTING :
				TCCR0 &= ~(1<<COM00);
				TCCR0 |= (1<<COM01);
				break ;
			case SET_UPCOUNTING_CLEAR_DOWNCOUNTING :
				TCCR0 |= (1<<COM00);
				TCCR0 |= (1<<COM01);
				break ;
			default : return ;
		}
	}
	else if( Mode == FPWM ){
		switch(Output){
			case NO_OUTPUT :
				TCCR0 &= ~(1<<COM00);
				TCCR0 &= ~(1<<COM01);
				break ;
			case CLEAR_COMPARE_SET_TOP :
				TCCR0 &= ~(1<<COM00);
				TCCR0 |= (1<<COM01);
				break ;
			case SET_COMPARE_CLEAR_TOP :
				TCCR0 |= (1<<COM00);
				TCCR0 |= (1<<COM01);
				break ;
			default : return ;
		}
	}
}

/*************************************************************************************/



