/*
 * hal_keyad_program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: AhmedSamy
 */


#include "hal_keyad_interface.h"
#include <avr/delay.h>
#define u8 uint8

uint8 btn_values[4][4] = {
									{'7', '8', '9', '/'},
									{'4', '5', '6', '*'},
									{'1', '2', '3', '-'},
									{'#', '0', '=', '+'}
                                 };
void KEYPAD_init(){

	uint8 i;
	for(i = OUTPUT_START; i <= OUTPUT_END ; i++)
	{
		/*Initialize Columns as an Output pins*/
		DIO_SetPinDirection(KEYPAD_PORT , i , PIN_OUTPUT);
		DIO_SetPinValue(KEYPAD_PORT , i , PIN_HIGH);
	}
	for(i = INPUT_START; i <= INPUT_END ; i++)
	{
		/*Initialize Rows Pins as Internal Pull Up*/
		DIO_SetPinDirection(KEYPAD_PORT , i , PIN_INPUT);
		DIO_SetPinValue(KEYPAD_PORT , i , PIN_HIGH);
	}
//		DDRA = 0b11110000;
//		PORTA = 0b11111111;
//		PINA = 0b11111111;
}

//uint8 KEYPAD_GetPressedKey(void)
//{
//	uint8  L_PressedKey = KEY_NOT_PRESSED , L_State;
//	uint8 L_ColumnIndex = 0 , L_RowIndex = 0;
//	static uint8 L_ColumnArr[4] = {COLUMN0_PIN ,COLUMN1_PIN ,COLUMN2_PIN ,COLUMN3_PIN};
//	static uint8 L_RowArr[4] = {ROW0_PIN ,ROW1_PIN ,ROW2_PIN ,ROW3_PIN};
//
//	for(L_ColumnIndex = 0 ; L_ColumnIndex < 4 ; L_ColumnIndex++)
//	{
//		/*Activate the Current Column*/
//		DIO_SetPinDirection(KEYPAD_PORT, L_ColumnArr[L_ColumnIndex] ,PIN_LOW);
//		_delay_ms(10);
//		for(L_RowIndex = 0 ; L_RowIndex < 4 ; L_RowIndex++)
//		{
//			/*Read the Current Row*/
//			L_State = DIO_GetPinValue(KEYPAD_PORT , L_RowArr[L_RowIndex]);
//
//			/*Check if switch is pressed*/
//			if(PIN_LOW == L_State)
//			{
//				L_PressedKey = btn_values[L_RowIndex][L_ColumnIndex];
//				 /* Polling Wait until the switch is released*/
//				while (PIN_LOW == L_State){
//					L_State = DIO_GetPinValue(KEYPAD_PORT , L_RowArr[L_RowIndex]);
//				}
//				/*avoid bouncing*/
//				_delay_ms(10);
//
//				return L_PressedKey;
//
//			}
//		}
//	}
//
//	return L_PressedKey;
//}

//uint8 KPD_u8GetPressedKey(void)
//{
//
//	uint8 LOC_u8Column;
//
//  uint8 LOC_u8Row;
//
//  /* Initialize the switch status to NOT Pressed                                                                     */
//  uint8 LOC_u8Retrun = KEY_NOT_PRESSED;
//
//  /* Looping on columns of the Key Pad                                                                               */
//  for (LOC_u8Column = 0 + OUTPUT_START; LOC_u8Column < OUTPUT_END; LOC_u8Column++)
//  {
//    /* Activate the Column                                                                                           */
//	  DIO_SetPinValue(KEYPAD_PORT, LOC_u8Column, PIN_LOW);
//
//    /* Loop on the rows of the Key Pad                                                                               */
//    for (LOC_u8Row = 0 + INPUT_START; LOC_u8Row < INPUT_END; LOC_u8Row++)
//    {
//      /* Check the status of the switch                                                                              */
//      if (!DIO_GetPinValue(KEYPAD_PORT, LOC_u8Row))
//      {
//        /* Get the value of the currently pressed switch                                                             */
//        LOC_u8Retrun = btn_values[LOC_u8Column - OUTPUT_START][LOC_u8Row - INPUT_START];
//
//        /* Wait until the switch is released (Single Press)                                                          */
//        while (!Dio_u8GetPinValue(KEYPAD_PORT, LOC_u8Row))
//          ;
//
//        /* Delay to avoid bouncing                                                                                   */
//        _delay_ms(10);
//
//      }
//    }
//
//    /* Deactivate the Column                                                                                         */
//    Dio_vidSetPinValue(KEYPAD_PORT, LOC_u8Column, PIN_HIGH);
//  }
//
//  return LOC_u8Retrun;
//}



//
//
u8 KEYPAD_GetPressedKey(void){

	u8 KEY=KEY_NOT_PRESSED;

	u8 row=0; //input
	u8 column=0; //output
	u8 i=0; //iterator


	for(column=OUTPUT_START;column<=OUTPUT_END;column++){
		//deactivate all columns
		for(i=OUTPUT_START;i<=OUTPUT_END;i++){
			DIO_SetPinValue(KEYPAD_PORT,i,PIN_HIGH);
		}
		//column number is activated;
		DIO_SetPinValue(KEYPAD_PORT,column,PIN_LOW);
		//SCAN ROWs
		for(row=INPUT_START;row<=INPUT_END;row++){
			if(DIO_GetPinValue(KEYPAD_PORT,row)==PIN_LOW){
				KEY=btn_values[row-INPUT_START][column-OUTPUT_START];
				break;
			}
		}
	}


	return KEY;
}
