/*
 * TIMER1_program.c
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedSamy
 */
#include "TIMER1_interface.h"

static void (*GlobalPtrToFunction)() = NULL ;

void TIMER1_init(void){
//
//	CLR_BIT(TCCR1A, TCCR1A_WGM10);
//	SET_BIT(TCCR1A, TCCR1A_WGM11);
//	SET_BIT(TCCR1B, TCCR1B_WGM12);
//	SET_BIT(TCCR1B, TCCR1B_WGM13);
//
//	CLR_BIT(TCCR1A , TCCR1A_COM1A0);
//	SET_BIT(TCCR1A , TCCR1A_COM1A1);
//
//	ICR1 = 20000;

	TCCR1B &= 0b11111000;
	TCCR1B |= 2;
}
void TIMER1_Set_OCR_Value(uint16 value){
	OCR1A = value;
}

void TIMER1_Set_TCNT_Value(uint16 value){
	TCNT1 = value;
}
uint16 TIMER1_Read_TCNT_Value(){
	return TCNT1;
}


void HWICU_Init(void){
	/*Set Initial Edge of interrupt*/
	SET_BIT(TCCR1B , TCCR1B_ICES1); //Rising Edge

	/*Enable Interrupt Source*/
	SET_BIT(TIMSK , TIMSK_TICIE1);

}

void HWICU_EdgeSelect(uint8 Edge){
	switch(Edge)
	{
		case FALLING_EDGE:
			CLR_BIT(TCCR1B , TCCR1B_ICES1);
		break;
		case RISING_EDGE:
			SET_BIT(TCCR1B , TCCR1B_ICES1);
		break;
	}
}

void HWICU_InterruptEnable(void){
	/*Enable Interrupt Source*/
	SET_BIT(TIMSK , TIMSK_TICIE1);
}

void HWICU_InterruptDisable(void){
	/*Disable Interrupt Source*/
	CLR_BIT(TIMSK , TIMSK_TICIE1);
}

void HWICU_SetCallBack(void (*ptr2fun)(void)){
	if(ptr2fun == NULL){
		asm("NOP");
	}else{
		GlobalPtrToFunction = ptr2fun;
	}
}

uint8 HWICU_ReadTicks(void){
	return ICR1;
}


void __vector_6(void)	__attribute__((signal));
void __vector_6(void){
	GlobalPtrToFunction();
}


