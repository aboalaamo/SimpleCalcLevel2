/*************************************************************************************
* Module: LED Driver																 *
* File Name: Led.h																 	 *
* Description: Header file for the Led driver										 *
* Author: Mohamed Alaa																 *
**************************************************************************************/

#ifndef DRIVERS_LED_LED_H_
#define DRIVERS_LED_LED_H_


/* Functions Prototypes */

void LED_LedInit( uint8 Port_Id , uint8 Pin_Id );

void LED_LedOn( uint8 Port_Id , uint8 Pin_Id );

void LED_LedOff( uint8 Port_Id , uint8 Pin_Id );


#endif /* DRIVERS_LED_LED_H_ */
