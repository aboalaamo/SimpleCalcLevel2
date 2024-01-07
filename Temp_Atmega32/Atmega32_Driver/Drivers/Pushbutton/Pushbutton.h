/*************************************************************************************
* Module: Push Button Driver														 *
* File Name: Pushbutton.h														 	 *
* Description: Header file for Pushbutton driver									 *
* Author: Mohamed Alaa																 *
**************************************************************************************/

#ifndef DRIVERS_PUSHBUTTON_PUSHBUTTON_H_
#define DRIVERS_PUSHBUTTON_PUSHBUTTON_H_


#define NO_INTERNAL_PULL_UP		LOGIC_LOW
#define INTERNAL_PULL_UP		LOGIC_HIGH

/* Functions Prototypes */

void PUSHBUTTON_ButtonInit( uint8 Port_Id , uint8 Pin_Id , uint8 Mode );
uint8 PUSHBUTTON_IsPressed( uint8 Port_Id , uint8 Pin_Id );

#endif /* DRIVERS_PUSHBUTTON_PUSHBUTTON_H_ */
