/*************************************************************************************
* Module: Calculator Driver															 *
* File Name: Calculator.h														 	 *
* Description: Header file for Calculator driver									 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


#ifndef PROJECTS_CALCULATOR_CALCULATOR_H_
#define PROJECTS_CALCULATOR_CALCULATOR_H_


/* Functions Prototypes */

void CalculatorL2_Run( uint8 LCD_DataPort_id , uint8 LCD_ControlPort_id , uint8 Keypad_Port_id , uint8 LCD_Mode_id , uint8 Keypad_Mode_id );

static void CalculatorL2_StartStatement(void);


#endif /* PROJECTS_CALCULATOR_CALCULATOR_H_ */
