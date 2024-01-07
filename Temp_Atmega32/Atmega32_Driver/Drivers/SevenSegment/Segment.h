/*************************************************************************************
* Module: 7 Segment Driver															 *
* File Name: Segment.h																 	 *
* Description: Header file for 7 Segment driver										 *
* Author: Mohamed Alaa																 *
**************************************************************************************/



#ifndef DRIVERS_SEVENSEGMENT_SEGMENT_H_
#define DRIVERS_SEVENSEGMENT_SEGMENT_H_


#define COMMON_ANODE	LOGIC_HIGH
#define COMMON_CATHODE	LOGIC_LOW

/* Numbers */

#define ZERO		0x3F
#define ONE			0x06
#define TWO			0x5B
#define THREE		0x4F
#define FOUR		0x66
#define FIVE		0x6D
#define SIX			0x7D
#define SEVEN		0x07
#define EIGHT		0x7F
#define NINE		0x6F
#define DISPLAY_OFF	0x00


/* Functions Prototypes */

void SEGMENT_Init( uint8 Port_id );

void SEGMENT_DisplayNumer( uint8 Port_id , uint8 Common , uint8 Number );



#endif /* DRIVERS_SEVENSEGMENT_SEGMENT_H_ */
