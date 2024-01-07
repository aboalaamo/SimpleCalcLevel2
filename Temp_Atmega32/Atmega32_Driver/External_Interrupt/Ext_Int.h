/*************************************************************************************
* Module: External Interrupts Driver												 *
* File Name: Ext_Int.h															 	 *
* Description: Header file for External Interrupts									 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


#ifndef EXTERNAL_INTERRUPT_EXT_INT_H_
#define EXTERNAL_INTERRUPT_EXT_INT_H_

#define I_BIT	PIN7_ID

typedef enum {
	LOW_LEVEL , LOGIC_change , FALLING_EDGE , RISING_EDGE
}Trigger_Type;


/* Functions Prototypes */

void EXT_INT0_Init( Trigger_Type trigger );

void EXT_INT1_Init( Trigger_Type trigger );

void EXT_INT2_Init( uint8 trigger );

void EXT_INT0_ExecuteFun( void (*PtrFun)(void) );

void EXT_INT1_ExecuteFun( void (*PtrFun)(void) );

void EXT_INT2_ExecuteFun( void (*PtrFun)(void) );

#endif /* EXTERNAL_INTERRUPT_EXT_INT_H_ */
