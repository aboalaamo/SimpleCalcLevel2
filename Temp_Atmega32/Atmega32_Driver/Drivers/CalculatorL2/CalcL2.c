/*************************************************************************************
* Module: Calculator Driver															 *
* File Name: Calculator.c														 	 *
* Description: Source file for Calculator driver									 *
* Author: Mohamed Alaa																 *
**************************************************************************************/


/* Includes */



#include <util/delay.h>
#include "../../Library/Std_Types.h"
#include "../../GPIO/GPIO.h"
#include "../LCD/LCD.h"
#include "../Keypad/Keypad.h"
#include "CalcL2.h"
#include "MathCalc.h"
#include <string.h>
#include <ctype.h>

static uint8 LCD_DataPort , LCD_ControlPort , Keypad_Port ,  LCD_Mode , Keypad_Mode ;


/*
 * Description: This function is used to initialize and run the Calculator .
 * Arguments:
	 * LCD_DataPort_id : LCD Data Port .
	 * LCD_ControlPort_id : LCD Control Port .
	 * Keypad_Port_id : Keypad Port .
	 * LCD_Mode_id : LCD Connection Mode .
	 * Keypad_Mode_id : Keypad Connection Mode .
 * Return Value: no return ( void ) .
 */
void CalculatorL2_Run(uint8 LCD_DataPort_id, uint8 LCD_ControlPort_id, uint8 Keypad_Port_id, uint8 LCD_Mode_id, uint8 Keypad_Mode_id) {

    // Initialize global variables with provided values.
    LCD_DataPort = LCD_DataPort_id;
    LCD_ControlPort = LCD_ControlPort_id;
    Keypad_Port = Keypad_Port_id;
    LCD_Mode = LCD_Mode_id;
    Keypad_Mode = Keypad_Mode_id;

    // Initialize the LCD display and keypad.
    LCD_LcdInit(LCD_DataPort, LCD_ControlPort, MODE_8_BIT);
    KEYPAD_KeypadInit(Keypad_Port, HALF_INPUT_OUTPUT);

    // Display an introductory message and wait for a key press to start.
    CalculatorL2_StartStatement();

    // Main operation loop.
	uint8 disClick = 0 ;
	sint32 runningResult = 0 ;
	char OperationStatement[16], index = 0;
	uint8 KeyValue = 0xff ;
	uint8 resultStr[10];
	uint8 opAgain;
	sint32 result;
	uint8 zeroDivflag = 0 ;
	uint8 errExp = 0 ;
    Operation :
	resultStr[0] = '0';
	resultStr[1] = '\0';
	opAgain = '+' ;
	disClick = 0 ;
	zeroDivflag = 0 ;
	errExp = 0 ;
    while (1) {
        while (1) {
            KeyValue = KEYPAD_GetPressedKeyValue(Keypad_Port);
            if (KeyValue == 0xff) {
                continue;
            } else if (KeyValue == 'c') {
                // Clear the LCD and start over if 'c' is pressed.
                LCD_ClearLCD();
                disClick = 0 ;
                index = 0 ;
                OperationStatement[0] = '\0' ;
                goto Operation ;
            } else if ( KeyValue == '=' && disClick == 0 ) {
            	OperationStatement[index] = '\0';
            	uint8 newExp[40];
            	for( int i = 0 ; i < strlen(resultStr) ; ++i ){
            		newExp[i] = resultStr[i];
            	}
            	newExp[strlen(resultStr)] = opAgain ;
            	for( int i = strlen(resultStr)+1 ; i < (strlen(OperationStatement)+strlen(resultStr)+1) ; ++i ){
            		newExp[i] = OperationStatement[i-strlen(resultStr)-1];
            	}
            	newExp[(strlen(OperationStatement)+strlen(resultStr)+1)] = '\0' ;

            	for( int i = 0 ; newExp[i] != '\0' ; ++i ){
            		if( newExp[i] == '0' ){
            			if( newExp[i-1] == '/' ){
            				LCD_MoveCursor(2,0);
            				LCD_DisplayString("Error,Div By 0 !");
            				disClick = 1 ;
            				zeroDivflag = 1 ;
            				break;
            			}
            		}
            	}
            	if( zeroDivflag == 1 ){
            		break;
            	}
            	if( (newExp[0] == '+' || newExp[0] == '*' || newExp[0] == '/') ||
            			(newExp[(strlen(OperationStatement)+strlen(resultStr))] == '+' ||
						newExp[(strlen(OperationStatement)+strlen(resultStr))] == '*' ||
						newExp[(strlen(OperationStatement)+strlen(resultStr))] == '/' ||
						newExp[(strlen(OperationStatement)+strlen(resultStr))] == '-')){
            		LCD_ClearLCD();
            		LCD_MoveCursor(2,0);
            		LCD_DisplayString("Error Expression");
            		disClick = 1 ;
            		errExp = 1 ;
            		break;
            	}

                result = evaluateExpression(newExp);
                LCD_MoveCursor(2, 0);
            	LCD_DisplayString("Ans = ");
            	if( result == 0 ){
            		LCD_SendData('0');
            	} else {
            		LCD_DisplayNumber(result);
            	}
            	char temp[10];
            	sprintf(temp,"%d",result);
            	for( int i = 0 ; i < (10-strlen(temp)) ; ++i ){
            		LCD_SendData(' ');
            	}
                disClick = 1 ;
                break;
            } else if( disClick == 1 && (KeyValue == '+' ||KeyValue == '-' ||KeyValue == '*' ||KeyValue == '/') && zeroDivflag == 0 && errExp == 0 ){
            	LCD_ClearLCD();
            	LCD_MoveCursor(2,0);
            	LCD_DisplayString("Ans = ");
            	if( result == 0 ){
					LCD_SendData('0');
				} else {
					LCD_DisplayNumber(result);
				}
            	LCD_MoveCursor(1,0);
            	LCD_DisplayString("Ans");
            	resultStr[0] = '\0';
				sprintf(resultStr,"%d",result);
				opAgain = KeyValue ;
				index = 0 ;
				OperationStatement[0] = '\0' ;
				disClick = 0 ;
            } else if( disClick == 0 ){
                OperationStatement[index] = KeyValue;
                ++index;
            }
            // Display the pressed key on the LCD.
            if( KeyValue != '=' && disClick == 0 ){
            	LCD_SendData(KeyValue);
            }
        }
    }
}

/*************************************************************************************/

/*
 * Description: This function is used to print a start on LCD .
 * Arguments:
	 * No Arguments .
 * Return Value: no return ( void ) .
 */
static void CalculatorL2_StartStatement(void) {
    // Display "Simple" on the first line at column 5 of an LCD screen.
    LCD_MoveCursor(1, 5);
    LCD_DisplayString("Simple");

    // Display "Calculator" on the second line at column 3 of the same LCD screen.
    LCD_MoveCursor(2, 3);
    LCD_DisplayString("Calculator");

    // Delay for 2 seconds to show the "Simple Calculator" message.
    _delay_ms(1500);

    LCD_ClearLCD();
    LCD_MoveCursor(2, 0);
    LCD_DisplayString("    Level 2 ");
    for( int i = 0 ; i < 10 ; ++i ){
		LCD_MoveCursor(2, 12);
    	i % 2 == 0 ? LCD_SendData('!') : LCD_SendData(' ') ;
    	_delay_ms(100);
    }

    // Clear the LCD screen.
    LCD_ClearLCD();

    // Display "By :" on the first line at column 6 of the LCD screen.
    LCD_MoveCursor(1, 6);
    LCD_DisplayString("By :");

    // Display "Abo Alaa" on the second line at column 2 of the same LCD screen.
    LCD_MoveCursor(2, 4);
    LCD_DisplayString("Abo Alaa");

    // Delay for 2 seconds to show the "By: Mohamed Alaa" message.
    _delay_ms(2000);

    // Clear the LCD screen.
    LCD_ClearLCD();

    // Display "Press any" on the first line at column 3 of the LCD screen.
    LCD_MoveCursor(1, 3);
    LCD_DisplayString("Press any");

    // Display "key to Start..." on the second line at column 1 of the same LCD screen.
    LCD_MoveCursor(2, 1);
    LCD_DisplayString("key to Start...");

    // Wait indefinitely for any key press to clear the screen.
    while (1) {
        if (KEYPAD_GetPressedKeyValue(Keypad_Port) != 255) {
            LCD_ClearLCD();
            break;
        }
    }
}

