/*************************************************************************************
* Module: Push Button Driver														 *
* File Name: Pushbutton.c														 	 *
* Description: Source file for Pushbutton driver									 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


/* Includes */

#include "../../Library/Std_Types.h"
#include "../../GPIO/GPIO.h"
#include "Pushbutton.h"


/* Functions Implementation */


/*
 * Description: This function is used to initialize the Push Button Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
	 * Mode: Internal Pull up or Not .
 * Return Value: no return ( void ) .
 */

void PUSHBUTTON_ButtonInit( uint8 Port_Id , uint8 Pin_Id , uint8 Mode ){
	GPIO_SetPinDirction(Port_Id,Pin_Id,PIN_INPUT);
	if( Mode == INTERNAL_PULL_UP ){
		GPIO_WritePinValue(Port_Id,Pin_Id,LOGIC_HIGH);
	}
	else{
		GPIO_WritePinValue(Port_Id,Pin_Id,LOGIC_LOW);
	}
}

/*************************************************************************************/

/*
 * Description: This function is used to check is the Push Button pressed .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: returns is pressed or not .
 */
uint8 PUSHBUTTON_IsPressed( uint8 Port_Id , uint8 Pin_Id ){
	uint8 PinVal ;
	PinVal = GPIO_ReadPinValue(Port_Id,Pin_Id);
	return PinVal ;
}



