/*************************************************************************************
* Module: Application Program														 *
* File Name: main.c																 	 *
* Description: Runner For Program													 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


/* Includes */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Library/Std_Types.h"
#include "Library/Macros.h"
#include "GPIO/GPIO.h"
#include "Drivers/Led/Led.h"
#include "Drivers/Pushbutton/Pushbutton.h"
#include "Drivers/Buzzer/Buzzer.h"
#include "Drivers/Keypad/Keypad.h"
#include "Drivers/LCD/LCD.h"
#include "Drivers/SevenSegment/Segment.h"
#include "External_Interrupt/Ext_Int.h"
#include "Timers/Timers.h"
#include "Drivers/CalculatorL1/CalcL1.h"
#include "Drivers/CalculatorL2/CalcL2.h"

int main(void){

	GPIO_SetPortDirction(PORTA_ID,PORT_OUTPUT);
	GPIO_SetPortDirction(PORTB_ID,PORT_OUTPUT);
	GPIO_SetPortDirction(PORTC_ID,HALF_INPUT_OUTPUT);
	while(1){
		CalculatorL2_Run(PORTA_ID,PORTB_ID,PORTC_ID,MODE_8_BIT,HALF_INPUT_OUTPUT);
	}
	return 0 ;
}

/*
 * Led and Buzzer always output mode ,so In Initialization don't get Direction .
 * Push Button always input mode ,so In Initialization don't get Direction .
 * In Microcontroller There are Internal Pull Up Mode ( Internal Resistor which is Pull Up Resistor )
   Can Activated when Pin Direction is Input and Pin Value is One .
 * In Keypad , we work using Internal Pull Up Mode in Microcontroller .
 * We Make Debouncing Time To avoid Mechanical Error in Keypad Buttons .
 * Don't Assign The KeyState in Variable .
 * We Have Two Mode Connections in Keypad :
 	 - First Four Pins is Input , Second Four Pins is Output .
 	 - First Four Pins is Output , Second Four Pins is Input .
 * VDD : 5 V .
 * VSS : Ground .
 * VEE or VO : connected by Potentiometer .
 * Control Pins : RS , RW , E .
 * RS : Register Selection , Command or Character ( HIGH : Data Code , LOW : Instruction Code ) .
 * RW : Read/Write Selection , Direction of Data Transfer ( HIGH : Read , LOW : Write ) .
 * E : Enable Signal , ( HIGH : Read Data , Falling Edge : Write Data ) .
 * Data Pins : D0 -> D7 .
 	 - In 8-bit Mode : All Pins used .
 	 - In 4-bit Mode : Just D4 : D7 are used .
 * LCD Controller has Two 8-bit Registers :
 	 - IR : Instruction Register , work with Instructions and Commands .
 	 - DR : Data Register , work with Data and Characters displayed on Screen .
 * LCD Memories , behaves with Characters :
 	 - DD RAM ( Display Data RAM ) : used to store the characters or symbols that you want to display on the screen.
 	 - CG RAM ( Character Generator RAM ) : used for define custom character patterns or symbols that are not part of the standard character set.
 *-----------------------------------------------
 * X : Don't Care ( 0 or 1 ) .
 *
 * N ( Set Number of Lines ):
 	 - 0 : 1 Line Mode .
 	 - 1 : 2 Line Mode .

 * F ( Set Character Font ):
 	 - 0 : 5*7  Dots .
 	 - 1 : 5*10 Dots .

 * D ( Entire Display ):
 	 - 0 : Display OFF .
 	 - 1 : Display ON .

 * C ( Cursor Display ) Cursor is displayed in 8th line ( 5*7 Used + 5*1 Cursor ):
 	 - 0 : Not Display  .
 	 - 1 : Display .

 * B ( Cursor Blink ):
 	 - 0 : Not Blink  .
 	 - 1 : Blink .

 * I/D ( Cursor Direction ):
 	 - 0 : Decrease ( moves to Left )  .
 	 - 1 : Increase ( moves to Right )  .

 * SH ( Cursor Shift ):
 	 - 0 : Shift will not be seen  .
 	 - 1 : Shift will be seen  .
 *-----------------------------------------------
 * RS , R/W and E will be output .
 * To ensure action in LCD , Make Falling Edge for E .
 * itoa( Number , StringArray , Base ) => To Convert Number To String .
 * Assign The Key value in Variable to display on LCD .
 * You have only 8 Indexs in CGRAM To Save Custom Character .
 * We Start assigning in Start of First address in CGRAM .
 * You store character in only One Index .
 * After Storing in CGRAM , prepare DDRAM to Print if done .
 *-----------------------------------------------
 * Eternal Interrupts : INT0 ( PD2 ) , INT1 ( PD3 ) , INT2 ( PB2 ) .
 * I-bit is Global Interrupt .
 * We connect Interrupt Pins to Button to Send Trigger Signal TO Ensure That Interrupt Happen .
 * To Make Interrupt Happen :
 	 - SREG Pin-7 ( I-bit ) = 1
 	 - GICR Interrupt-pin = 1
 	 - GIFR Interrupt Flag-pin = 1
 * We have Two Techniques in Interrupt : Polling and IRS .
 * In Polling we have to check if GIFR Flag Enabled or Not to Make Interrupt .
 * In ISR , We don't have to Check GIFR as ISR do that .
 *
 *
 * */

