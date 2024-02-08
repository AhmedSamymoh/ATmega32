/*
 * LCD_Program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: AhmedSamy
 */

#include "LCD_Interface.h"

uint8 LCD_4bit_Pins[4] = {LCD_4bit_D4, LCD_4bit_D5, LCD_4bit_D6 , LCD_4bit_D7};

/*Helper Function*/
static void LCD_Send_Enable_Signal();
static void LCD_4Bit_Send_Enable_Signal();
static void LCD_Send_4Bits(uint8 _data_command);


/*------------------------------------------------------------------------------*/
/*----------------------------    4 BIT MODE    --------------------------------*/
/*------------------------------------------------------------------------------*/


/*******************************************************************************
 * @brief Initialize The LCD in 4 bit mode - Cursor off
 ********************************************************************************/
void LCD_4Bit_Init(void){
    uint8 l_data_pins_counter = 0;

	/*Initialization of LCD Pins*/
	DIO_SetPinDirection(LCD_4bit_PORT,LCD_4bit_RS,PIN_OUTPUT);
	DIO_SetPinDirection(LCD_4bit_PORT,LCD_4bit_RW,PIN_OUTPUT);
	DIO_SetPinDirection(LCD_4bit_PORT,LCD_4bit_EN,PIN_OUTPUT);
    for(l_data_pins_counter=0; l_data_pins_counter<4; l_data_pins_counter++){
        DIO_SetPinDirection(LCD_4bit_PORT,LCD_4bit_Pins[l_data_pins_counter] ,PIN_OUTPUT );
    }

    _delay_ms(20);
	LCD_4Bit_Send_Command(_LCD_8BIT_MODE_2_LINE);
	_delay_ms(5);
	LCD_4Bit_Send_Command(_LCD_8BIT_MODE_2_LINE);
	_delay_us(150);
	LCD_4Bit_Send_Command(_LCD_8BIT_MODE_2_LINE);

	LCD_4Bit_Send_Command(_LCD_CLEAR);
	LCD_4Bit_Send_Command(_LCD_ENTRY_MODE);
	LCD_4Bit_Send_Command(_LCD_RETURN_HOME);
	LCD_4Bit_Send_Command(_LCD_CURSOR_OFF_DISPLAY_ON);
	LCD_4Bit_Send_Command(_LCD_4BIT_MODE_2_LINE);
	LCD_4Bit_Send_Command(_LCD_DDRAM_START);
	_delay_ms(5);
	LCD_4Bit_Send_Command(_LCD_CLEAR);
	_delay_ms(10);
}

void LCD_4Bit_Send_Command(uint8 u8Command){

	/*Set RS "Register Select" Pin to 0 to write in Instruction Register (IR)*/
	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_RS,PIN_LOW);

	/*Set RW "Read Write" pin to 0 to write*/
	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_RW,PIN_LOW);

	/*Send Command Higher 4 bits*/
	LCD_Send_4Bits( u8Command >> 4 );

	/*Enable Pulse*/
	LCD_4Bit_Send_Enable_Signal();

	/*Send Command lower 4 bits*/
	LCD_Send_4Bits(u8Command);

	/*Enable Pulse*/
	LCD_4Bit_Send_Enable_Signal();

}

void LCD_4Bit_Send_Data(uint8 u8Data){

	/*Set RS "Register Select" Pin to 1 to write in Data Register (DR)*/
	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_RS,PIN_HIGH);

	/*Set RW "Read Write" pin to 0 to write*/
	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_RW,PIN_LOW);

	/*Send Command Higher 4 bits*/
	LCD_Send_4Bits( u8Data >> 4 );

	/*Enable Pulse*/
	LCD_4Bit_Send_Enable_Signal();

	/*Send Command lower 4 bits*/
	LCD_Send_4Bits(u8Data);

	/*Enable Pulse*/
	LCD_4Bit_Send_Enable_Signal();

}

/*******************************************************************************
 * @brief Write a String on LCD 4 bit Mode
 * @parameter *ptr		a pointer to char points to string (array of char)
 ********************************************************************************/
void LCD_4Bit_Write_String(const uint8 *ptr){
	uint8 i=0 ;
	while('\0' != ptr[i])
	{
		LCD_4Bit_Send_Data(ptr[i]);
		i++;
	}
}


void LCD_4Bit_Set_Cursor( uint8 ROW , uint8 COL ){
	COL--;

	switch(ROW)
	{				/*0x80 is the first address for DDRAM */
		case ROW1 : LCD_4Bit_Send_Command( _LCD_DDRAM_START + (COL) ); 	      break;
		case ROW2 : LCD_4Bit_Send_Command( _LCD_DDRAM_START + (COL + 0x40) ); break;
		default : ;
	}
}

void LCD_4Bit_Write_String_Position(const uint8 *ptr , uint8 ROW , uint8 COL){
	LCD_4Bit_Set_Cursor(ROW , COL);
	LCD_4Bit_Write_String(ptr);
}

/*******************************************************************************
 * @brief Write a Number on LCD 4 bit Mode
 * @parameter *Copy_u16Num		(uint16)Number
 ********************************************************************************/
void LCD_4Bit_Send_Number(int32_t Copy_s32Num){
    char arr[11];
    uint8_t i = 0;

    // Handle negative numbers
    if (Copy_s32Num < 0) {
    	LCD_4Bit_Send_Data('-');
        Copy_s32Num *= -1; // Convert negative to positive
    }

    // Handle the case of 0 separately
    if (Copy_s32Num == 0) {
    	LCD_4Bit_Send_Data('0');
        return;
    }

    // Convert the number to an array of characters
    while (Copy_s32Num) {
        arr[i] = (Copy_s32Num % 10) + '0';
        Copy_s32Num /= 10;
        i++;
    }
    arr[i] = '\0'; // Null-terminate the string

    // Send the digits to the LCD in reverse order
    for (int8_t j = i - 1; j >= 0; j--) {
    	LCD_4Bit_Send_Data(arr[j]);
    }
}



/*------------------------------------------------------------------------------*/
/*----------------------------    8 BIT MODE    --------------------------------*/
/*------------------------------------------------------------------------------*/

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
void LCD_Send_Command(uint8 u8Command)
{
	/*Set RS "Register Select" Pin to 0 to write in Instruction Register (IR)*/
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_LOW);

	/*Set RW "Read Write" pin to 0 to write*/
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_LOW);

	/*Send Command*/
	DIO_SetPortValue(LCD_DATA_PORT,u8Command);

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
void LCD_Send_Number(int32_t Copy_s32Num){
    char arr[11];
    uint8_t i = 0;

    // Handle negative numbers
    if (Copy_s32Num < 0) {
        LCD_Send_Data('-');
        Copy_s32Num *= -1; // Convert negative to positive
    }

    // Handle the case of 0 separately
    if (Copy_s32Num == 0) {
        LCD_Send_Data('0');
        return;
    }

    // Convert the number to an array of characters
    while (Copy_s32Num) {
        arr[i] = (Copy_s32Num % 10) + '0';
        Copy_s32Num /= 10;
        i++;
    }
    arr[i] = '\0'; // Null-terminate the string

    // Send the digits to the LCD in reverse order
    for (int8_t j = i - 1; j >= 0; j--) {
        LCD_Send_Data(arr[j]);
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

static void LCD_4Bit_Send_Enable_Signal(){
	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_EN,PIN_HIGH);
	_delay_ms(3);
	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_EN,PIN_LOW);
}


static void LCD_Send_4Bits(uint8 _data_command){

	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_Pins[0] ,( (_data_command >> 0) & (uint8)0x01 ) );
	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_Pins[1] ,( (_data_command >> 1) & (uint8)0x01 ) );
	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_Pins[2] ,( (_data_command >> 2) & (uint8)0x01 ) );
	DIO_SetPinValue(LCD_4bit_PORT,LCD_4bit_Pins[3] ,( (_data_command >> 3) & (uint8)0x01 ) );
}



