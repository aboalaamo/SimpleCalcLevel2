/*************************************************************************************
* Module: Buzzer Driver																 *
* File Name: Buzzer.h															 	 *
* Description: Header file for the Buzzer driver									 *
* Author: Mohamed Alaa																 *
**************************************************************************************/

#ifndef DRIVERS_BUZZER_BUZZER_H_
#define DRIVERS_BUZZER_BUZZER_H_

void BUZZER_BuzzerInit( uint8 Port_Id , uint8 Pin_Id );

void BUZZER_BuzzerOn( uint8 Port_Id , uint8 Pin_Id );

void BUZZER_BuzzerOff( uint8 Port_Id , uint8 Pin_Id );

#endif /* DRIVERS_BUZZER_BUZZER_H_ */
