/*
 * USART_program.c
 *
 *  Created on: Feb 28, 2024
 *      Author: AhmedSamy
 */

#include "USART_interface.h"

static void (*GlobalCallBackPtr_RX)() = NULL;
static void (*GlobalCallBackPtr_TX)() = NULL;


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

	/*Adjusting Baud Rate 9600*/
	UCSRC = UCSRC_Buffer;

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

void USART_SetCallBack_RX( void (*Ptr2Fun)(void) ){
	GlobalCallBackPtr_RX = Ptr2Fun;
}
void USART_SetCallBack_TX( void (*Ptr2Fun)(void) ){
	GlobalCallBackPtr_TX = Ptr2Fun;
}


/*******RX_Interrupt******/
void __vector_13(void) __attribute__((signal));
void __vector_13(void){
	if(GlobalCallBackPtr_RX != NULL)
		GlobalCallBackPtr_RX();
}
/*******RX_Interrupt******/
void __vector_15(void) __attribute__((signal));
void __vector_15(void){
	if(GlobalCallBackPtr_TX != NULL)
		GlobalCallBackPtr_TX();
}

