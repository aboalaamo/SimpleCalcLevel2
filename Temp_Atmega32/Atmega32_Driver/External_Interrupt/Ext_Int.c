/*************************************************************************************
* Module: External Interrupts Driver												 *
* File Name: Ext_Int.c															 	 *
* Description: Source file External Interrupts										 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


/* Includes */


#include <avr/interrupt.h>
#include "../Library/Std_Types.h"
#include "../Library/Macros.h"
#include "../GPIO/GPIO.h"
#include "Ext_Int.h"


static volatile void ( *EXT_INT0_PtrFun )(void);
static volatile void ( *EXT_INT1_PtrFun )(void);
static volatile void ( *EXT_INT2_PtrFun )(void);



/* Functions Implementation */


/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void EXT_INT0_Init(Trigger_Type trigger){
	GPIO_SetPinDirction(PORTD_ID,PIN2_ID,PIN_INPUT);
	SET_BIT( SREG , I_BIT );
	switch(trigger){
		case LOW_LEVEL :
			CLR_BIT( MCUCR , ISC00 );
			CLR_BIT( MCUCR , ISC01 );
			break;
		case LOGIC_change :
			SET_BIT( MCUCR , ISC00 );
			CLR_BIT( MCUCR , ISC01 );
			break;
		case FALLING_EDGE :
			CLR_BIT( MCUCR , ISC00 );
			SET_BIT( MCUCR , ISC01 );
			break;
		case RISING_EDGE :
			SET_BIT( MCUCR , ISC00 );
			SET_BIT( MCUCR , ISC01 );
			break;
		default : return ;
	}
	SET_BIT( GICR , INT0 );
}

/*************************************************************************************/

/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void EXT_INT1_Init(Trigger_Type trigger){
	GPIO_SetPinDirction(PORTD_ID,PIN3_ID,PIN_INPUT);
	SET_BIT( SREG , I_BIT );
	switch(trigger){
		case LOW_LEVEL :
			CLR_BIT( MCUCR , ISC10 );
			CLR_BIT( MCUCR , ISC11 );
			break;
		case LOGIC_change :
			SET_BIT( MCUCR , ISC10 );
			CLR_BIT( MCUCR , ISC11 );
			break;
		case FALLING_EDGE :
			CLR_BIT( MCUCR , ISC10 );
			SET_BIT( MCUCR , ISC11 );
			break;
		case RISING_EDGE :
			SET_BIT( MCUCR , ISC10 );
			SET_BIT( MCUCR , ISC11 );
			break;
		default : return ;
	}
	SET_BIT( GICR , INT1 );
}

/*************************************************************************************/

/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void EXT_INT2_Init(Trigger_Type trigger){
	GPIO_SetPinDirction(PORTB_ID,PIN2_ID,PIN_INPUT);
	switch(trigger){
		case FALLING_EDGE :
			CLR_BIT( MCUCR , ISC2 );
			break;
		case RISING_EDGE :
			SET_BIT( MCUCR , ISC2 );
			break;
		default : return ;
	}
	SET_BIT( GICR , INT2 );
	SET_BIT( SREG , I_BIT );
}

/*************************************************************************************/

/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void EXT_INT0_ExecuteFun( void (*PtrFun)(void) ){
	EXT_INT0_PtrFun = PtrFun ;
}

/*************************************************************************************/

/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void EXT_INT1_ExecuteFun( void (*PtrFun)(void) ){
	EXT_INT1_PtrFun = PtrFun ;
}

/*************************************************************************************/

/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void EXT_INT2_ExecuteFun( void (*PtrFun)(void) ){
	EXT_INT2_PtrFun = PtrFun ;
}

/*************************************************************************************/

/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */

ISR(INT0_vect){
	EXT_INT0_PtrFun();
}

/*************************************************************************************/

/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */

ISR(INT1_vect){
	EXT_INT1_PtrFun();
}

/*************************************************************************************/

/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */

ISR(INT2_vect){
	EXT_INT2_PtrFun();
}




