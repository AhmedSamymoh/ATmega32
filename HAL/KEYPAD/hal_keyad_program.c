/*
 * hal_keyad_program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: AhmedSamy
 */


#include "hal_keyad_interface.h"
#include <avr/delay.h>


/*uint8 btn_values[4][4] = {
									{'7', '8', '9', '/'},
									{'4', '5', '6', '*'},
									{'1', '2', '3', '-'},
									{'#', '0', '=', '+'}
                                 };
*/

uint8 btn_values[4][4] = {
							{ 7 , 8 , 9 , '/'},
							{ 4 , 5 , 6 , '*'},
							{ 1 , 2 , 3 , '-'},
							{'c', 0 ,'=', '+'}
};

uint8 L_ColumnArr[4] = {COLUMN0_PIN ,COLUMN1_PIN ,COLUMN2_PIN ,COLUMN3_PIN};
uint8 L_RowArr[4] = {ROW0_PIN ,ROW1_PIN ,ROW2_PIN ,ROW3_PIN};
void KEYPAD_init(void){

	uint8 i;
	for(i = 0; i < 4 ; i++)
	{
		/*Initialize Columns as an Output pins*/
		DIO_SetPinDirection(KEYPAD_PORT , L_ColumnArr[i] , PIN_OUTPUT);
	}
	for(i = 0; i < 4 ; i++)
	{
		/*Initialize Rows Pins as Internal Pull Up*/
		DIO_SetPinDirection(KEYPAD_PORT , L_RowArr[i] , PIN_INPUT);
		DIO_SetPinValue(KEYPAD_PORT ,L_RowArr[i], PIN_HIGH);
	}
}

uint8 KEYPAD_GetPressedKey(void)
{
	uint8  L_PressedKey = KEY_NOT_PRESSED , L_State;
	uint8 L_ColumnIndex = 0 , L_RowIndex = 0;

	static uint8 L_ColumnArr[4] = {COLUMN0_PIN ,COLUMN1_PIN ,COLUMN2_PIN ,COLUMN3_PIN};
	static uint8 L_RowArr[4] = {ROW0_PIN ,ROW1_PIN ,ROW2_PIN ,ROW3_PIN};


	for(L_ColumnIndex = 0 ; L_ColumnIndex < 4 ; L_ColumnIndex++)
	{

		/*Activate the Current Column*/
		DIO_SetPinDirection(KEYPAD_PORT, L_ColumnArr[L_ColumnIndex] ,PIN_HIGH);
		_delay_ms(10);

		for(L_RowIndex = 0 ; L_RowIndex < 4 ; L_RowIndex++)
		{
			/*Read the Current Row*/
			L_State = DIO_GetPinValue(KEYPAD_PORT , L_RowArr[L_RowIndex]);

			/*Check if switch is pressed*/
			if(PIN_LOW == L_State)
			{
				L_PressedKey = btn_values[L_RowIndex][L_ColumnIndex];

				 /* Polling Wait until the switch is released*/
				while (PIN_LOW == L_State){

					L_State = DIO_GetPinValue(KEYPAD_PORT , L_RowArr[L_RowIndex]);
				}
				/*avoid bouncing*/
				_delay_ms(50);
				/*Deactivate the Current Column*/
				DIO_SetPinDirection(KEYPAD_PORT, L_ColumnArr[L_ColumnIndex] ,PIN_LOW);

				return L_PressedKey;
			}
		}
		/*Deactivate the Current Column*/
		DIO_SetPinDirection(KEYPAD_PORT, L_ColumnArr[L_ColumnIndex] ,PIN_LOW);

	}

	return L_PressedKey;
}
