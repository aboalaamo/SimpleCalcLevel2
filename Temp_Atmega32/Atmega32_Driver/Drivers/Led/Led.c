/*************************************************************************************
* Module: LED Driver																 *
* File Name: Led.c																 	 *
* Description: Source file for Led driver											 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


/* Includes */

#include "../../Library/Std_Types.h"
#include "../../GPIO/GPIO.h"
#include "Led.h"


/* Functions Implementation */


/*
 * Description: This function is used to initialize the Led Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void LED_LedInit( uint8 Port_Id , uint8 Pin_Id ){
	GPIO_SetPinDirction(Port_Id,Pin_Id,PIN_OUTPUT);
	GPIO_WritePinValue(Port_Id,Pin_Id,LOGIC_LOW);
}

/*************************************************************************************/

/*
 * Description: This function is used to Turn on the Led .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void LED_LedOn( uint8 Port_Id , uint8 Pin_Id ){
	GPIO_WritePinValue(Port_Id,Pin_Id,LOGIC_HIGH);
}

/*************************************************************************************/

/*
 * Description: This function is used to Turn off the Led .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void LED_LedOff( uint8 Port_Id , uint8 Pin_Id ){
	GPIO_WritePinValue(Port_Id,Pin_Id,LOGIC_LOW);
}


