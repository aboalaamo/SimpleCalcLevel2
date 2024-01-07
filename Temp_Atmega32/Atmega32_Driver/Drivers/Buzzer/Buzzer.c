/*************************************************************************************
* Module: LED Driver																 *
* File Name: Buzzer.c																 	 *
* Description: Source file for Led driver											 *
* Author: Mohamed Alaa																 *
**************************************************************************************/

/* Includes */

#include "../../Library/Std_Types.h"
#include "../../GPIO/GPIO.h"
#include "Buzzer.h"


/* Functions Implementation */


/*
 * Description: This function is used to initialize the Buzzer Port and Pin .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void BUZZER_BuzzerInit( uint8 Port_Id , uint8 Pin_Id ){
	GPIO_SetPinDirction(Port_Id,Pin_Id,PIN_OUTPUT);
	GPIO_WritePinValue(Port_Id,Pin_Id,LOGIC_LOW);
}

/*************************************************************************************/

/*
 * Description: This function is used to Turn on the Buzzer .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void BUZZER_BuzzerOn( uint8 Port_Id , uint8 Pin_Id ){
	GPIO_WritePinValue(Port_Id,Pin_Id,LOGIC_HIGH);
}

/*************************************************************************************/

/*
 * Description: This function is used to Turn off the Buzzer .
 * Arguments:
	 * Port_Id: port .
	 * Pin_Id: pin on the port .
 * Return Value: no return ( void ) .
 */
void BUZZER_BuzzerOff( uint8 Port_Id , uint8 Pin_Id ){
	GPIO_WritePinValue(Port_Id,Pin_Id,LOGIC_LOW);
}


