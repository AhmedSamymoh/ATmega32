/*
 * LCD_Program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: AhmedSamy
 */

#include "LCD_Interface.h"

/*Helper Function*/
static void LCD_Send_Enable_Signal();

/*******************************************************************************
 * @brief Initialize The LCD in 8 bit mode - Cursor off
 ********************************************************************************/
void LCD_Init(void){
	/*Initialization of LCD Pins*/
	DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_OUTPUT);
	DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_OUTPUT);
	DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_OUTPUT);
	DIO_SetPortDirection(LCD_DATA_PORT,PORT_OUTPUT);

	_delay_ms(30);
	LCD_Send_Command(_LCD_8BIT_MODE_2_LINE);

	_delay_us(40);
	LCD_Send_Command(_LCD_CURSOR_OFF_DISPLAY_ON);

	_delay_us(40);
	LCD_Send_Command(_LCD_CLEAR);

	_delay_ms(2);
	LCD_Send_Command(_LCD_ENTRY_MODE);

	_delay_ms(30);
	LCD_Send_Command(_LCD_RETURN_HOME);
}


/*******************************************************************************
 * @brief Send a Command to LCD in the Instruction Register
 * @parameter u8command 		(uint8)command
 ********************************************************************************/
void LCD_Send_Command(uint8 u8command)
{
	/*Set RS "Register Select" Pin to 0 to write in Instruction Register (IR)*/
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_LOW);

	/*Set RW "Read Write" pin to 0 to write*/
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_LOW);

	/*Send Command*/
	DIO_SetPortValue(LCD_DATA_PORT,u8command);

	/*Enable Pulse*/
	LCD_Send_Enable_Signal();
}


/*******************************************************************************
 * @brief Send a Data 'Char' to LCD in the Data Register
 * @parameter u8Data 		(uint8)Data
 ********************************************************************************/
void LCD_Send_Data(uint8 u8Data)
{
	/*Set RS "Register Select" Pin to 0 to write in Data Register (DR)*/
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_HIGH);

	/*Set RW "Read Write" pin to 0 to write*/
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_LOW);

	/*Send Command*/
	DIO_SetPortValue(LCD_DATA_PORT,u8Data);

	/*Enable Pulse*/
	LCD_Send_Enable_Signal();
}

/*******************************************************************************
 * @brief Write a Number on LCD
 * @parameter *Copy_u16Num		(uint16)Number
 ********************************************************************************/
void LCD_Send_Number(uint16 Copy_u16Num)
{
	uint8 arr[10] , i = 0 , j = 0;
	if(Copy_u16Num==0)
	{
		LCD_Send_Data('0');
	}
	else
	{
		while (Copy_u16Num)
		{
			arr[i] = (Copy_u16Num % 10) +'0';
			Copy_u16Num = Copy_u16Num / 10;
			i++;
		}
	}
	for (j=i;j>0;j--)
	{
		LCD_Send_Data(arr[j-1]);
	}
}

/*******************************************************************************
 * @brief Write a String on LCD
 * @parameter *ptr		a pointer to char points to string (array of char)
 ********************************************************************************/
void LCD_Write_String(const uint8 *ptr){
	uint8 i=0 ;
	while('\0' != ptr[i])
	{
		LCD_Send_Data(ptr[i]);
		i++;
	}
}


void LCD_Write_String_Position(const uint8 *ptr , uint8 ROW , uint8 COL){
	LCD_Set_Cursor(ROW , COL);
	LCD_Write_String(ptr);
}

void LCD_Set_Cursor( uint8 ROW , uint8 COL ){
	COL--;

	switch(ROW)
	{				/*0x80 is the first address for DDRAM */
		case ROW1 : LCD_Send_Command( 0x80 + (COL) ); 	     break;
		case ROW2 : LCD_Send_Command( 0x80 + (COL + 0x40) ); break;
		default : ;
	}
}

/*Enable Signal to latch the data in DR or IR*/
static void LCD_Send_Enable_Signal(){
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_HIGH);
	_delay_ms(3);
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_LOW);
}





