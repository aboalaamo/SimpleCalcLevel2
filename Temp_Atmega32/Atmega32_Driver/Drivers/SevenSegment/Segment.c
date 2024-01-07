/*************************************************************************************
* Module: 7 Segment Driver															 *
* File Name: Segment.c																 	 *
* Description: Source file for 7 Segment driver										 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


/* Includes */

#include "../../Library/Std_Types.h"
#include "../../GPIO/GPIO.h"
#include "Segment.h"


/* Storing Numbers */

static const uint8 Numbers[10] = { ZERO , ONE , TWO , THREE , FOUR ,
								   FIVE , SIX , SEVEN , EIGHT , NINE };


/* Functions Implementation */

/*
 * Description: This function is used to initialize the 7 Segment .
 * Arguments:
	 * Port_Id: port .
 * Return Value: no return ( void ) .
 */
void SEGMENT_Init( uint8 Port_id ){
	GPIO_SetPortDirction(Port_id,PORT_OUTPUT);
	GPIO_WritePortValue(Port_id,LOGIC_LOW);
}

/*************************************************************************************/

/*
 * Description: This function is used to Display Number on Segment .
 * Arguments:
	 * Port_Id: port .
	 * Number: Number will displayed .
 * Return Value: no return ( void ) .
 */
void SEGMENT_DisplayNumer( uint8 Port_id , uint8 Common , uint8 Number ){

	if( Number >=0 && Number <= 9 ){
		if( Common == COMMON_ANODE ){
			GPIO_WritePortValue(Port_id,~Numbers[Number]);
		}
		else{
			GPIO_WritePortValue(Port_id,Numbers[Number]);
		}
	}
	else{
		uint8 counter , flag = 0 ;
		for( counter = 0 ; counter < 10 ; ++counter ){
			if( Number == Numbers[counter] ){
				flag = 0 ;
				break ;
			}
			else{
				flag = 1 ;
				continue ;
			}
		}
		if( flag == LOGIC_LOW ){
			if( Common == COMMON_ANODE ){
				GPIO_WritePortValue(Port_id, ~Numbers[Number]);
			}
			else{
				GPIO_WritePortValue(Port_id, Numbers[Number]);
			}
		}
		else{
			/* Nothing Happened */
		}
	}
}



