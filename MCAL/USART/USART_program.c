/*
 * USART_program.c
 *
 *  Created on: Feb 28, 2024
 *      Author: AhmedSamy
 */

#include "USART_interface.h"
#include "../../HAL/LCD/LCD_Interface.h"

static void (*GlobalCallBackPtr_RX)() = NULL;
static void (*GlobalCallBackPtr_TX)() = NULL;

void TX_Func(void);
void RX_Func(void);

static uint8 * Asynch_SendString;
static uint8 * Asynch_RecieveString;

void USART_Init(){
	uint8 UCSRC_Buffer = 0;
	SET_BIT(UCSRB , UCSRB_TXEN);
	SET_BIT(UCSRB , UCSRB_RXEN);

	/*8 Bit*/
	SET_BIT(UCSRC_Buffer , UCSRC_UCSZ0);
	SET_BIT(UCSRC_Buffer , UCSRC_UCSZ1);
	CLR_BIT(UCSRB , UCSRB_UCSZ2);

	/*Asynchronous Operation*/
	SET_BIT(UCSRC_Buffer , UCSRC_URSEL);
	CLR_BIT(UCSRC_Buffer , UCSRC_UMSEL);

	/*No Parity*/
	CLR_BIT(UCSRC_Buffer , UCSRC_UPM0);
	CLR_BIT(UCSRC_Buffer , UCSRC_UPM1);

	/*Stop Bit 1 bit*/
	CLR_BIT(UCSRC_Buffer , UCSRC_USBS);

	/*No DoupleSpeed*/
	CLR_BIT(UCSRA,UCSRA_U2X);

	UCSRC = UCSRC_Buffer;

	/*Adjusting Baud Rate 9600*/
	UBRRL = 51;
	UBRRH = 0;

}

uint8 USART_u8ReceiveData(){
	uint8 result;
	while(0 == GET_BIT(UCSRA , UCSRA_RXC));
	result = UDR;
	/* Clear Flag */
	SET_BIT(UCSRA,UCSRA_RXC);
	return result;
}

void USART_voidSendData(uint8 Data){

	while(0 == GET_BIT(UCSRA , UCSRA_UDRE));
	UDR = Data;
}

void USART_voidSendString(uint8 * str){
	uint8 i = 0;
	while(str[i] != '\0'){
		USART_voidSendData(str[i]);
		i++;
	}
}

void LCD_USART_write(uint8 RecievedData){
    static uint8 index = 0;
    uint8 data = RecievedData;
    static uint8 row = 1;
	   // Add the received data to the buffer
	index++;

	if (index == 16) {
		LCD_4Bit_Set_Cursor(2, 0);
		row = 2;
	}


	// Check for buffer overflow and reset
	if (index == 32) {
		//LCD_4Bit_Set_Cursor(1, 0);
		LCD_4Bit_Send_Command(_LCD_CLEAR);
		LCD_4Bit_Send_Command( _LCD_DDRAM_START);
		index = 0;
		LCD_4Bit_Set_Cursor(1, 1);
		row = 1;

	}

	// Handle newline character
	if (data == '\n' || data == '\r') {
		USART_voidSendData(data);
		if (row == 1) {
			row = 2;
			LCD_4Bit_Set_Cursor(2, 0);
		} else if(row == 2) {
			LCD_4Bit_Send_Command(_LCD_CLEAR);
			LCD_4Bit_Send_Command( _LCD_DDRAM_START);
			LCD_4Bit_Set_Cursor(1, 1);
			row = 1;
		}else{}
		index = 0;
	}else{
		LCD_4Bit_Send_Data(data);
	}
}

/***************************************************/

uint8 USART_ReceiveData_Asynch(){
	uint8 result;

	result = UDR;

	/* Clear Flag */
	SET_BIT(UCSRA,UCSRA_RXC);

	return result;
}
void USART_SendData_Asynch(uint8 Data){
	UDR = Data;
}


void USART_SendString_Asych(uint8 * str){

	USART_TX_InterruptEnable();
	USART_SetCallBack_TX(TX_Func);

	Asynch_SendString = str;
	USART_SendData_Asynch(str[0]);
}

void USART_ReceiveString_Asych(uint8 * str){

	USART_RX_InterruptEnable();
	USART_SetCallBack_RX(RX_Func);

	Asynch_RecieveString = str;
}

/***************************************************/

void TX_Func(void){
	static uint8 i = 1;

	if(Asynch_SendString[i] != '\0'){
		USART_SendData_Asynch(Asynch_SendString[i]);
		i++;
	}else{
		i = 1;
	}

}

void RX_Func(void){
	static uint8 i = 1;
	Asynch_RecieveString[i] = USART_ReceiveData_Asynch();
	i++;


}

/***************************************************/

void USART_RX_InterruptEnable(){
	SET_BIT(UCSRB , UCSRB_RXCIE);
	SET_BIT(UCSRB , UCSRB_RXEN);
}
void USART_RX_InterruptDisable(){
	CLR_BIT(UCSRB , UCSRB_RXCIE);
	CLR_BIT(UCSRB , UCSRB_RXEN);
}

void USART_TX_InterruptEnable(){
	SET_BIT(UCSRB , UCSRB_TXCIE);
	SET_BIT(UCSRB , UCSRB_TXEN);
}

void USART_TX_InterruptDisable(){
	CLR_BIT(UCSRB , UCSRB_TXCIE);
	CLR_BIT(UCSRB , UCSRB_TXEN);
}

/***************************************************/

void USART_SetCallBack_RX( void (*Ptr2Fun)(void) ){
	GlobalCallBackPtr_RX = Ptr2Fun;
}
void USART_SetCallBack_TX( void (*Ptr2Fun)(void) ){
	GlobalCallBackPtr_TX = Ptr2Fun;
}

/***************************************************/



/*******RX_Interrupt******/
void __vector_13(void) __attribute__((signal));
void __vector_13(void){
	if(GlobalCallBackPtr_RX != NULL)
		GlobalCallBackPtr_RX();
}
/*******TX_Interrupt******/
void __vector_15(void) __attribute__((signal));
void __vector_15(void){
	if(GlobalCallBackPtr_TX != NULL)
		GlobalCallBackPtr_TX();
}

