/*
 * TIMER1_program.c
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedSamy
 */
#include "TIMER1_interface.h"

static void (*GlobalPtrToFunction)() = NULL ;

void TIMER1_init(void){

	/*Mode 14 : Fast PWM , Top Value = OCR1A/B*/
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);

	/*Setting Top Value*/
	ICR1 = 20000;

#if TIMER1_FAST_PWM_MODE == INVERTED_MODE
	SET_BIT(TCCR1A , TCCR1A_COM1A0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);
#elif TIMER1_FAST_PWM_MODE == NON_INVERTED_MODE
	CLR_BIT(TCCR1A , TCCR1A_COM1A0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);
#endif

#if TIMER1_PRESCALER == DIV_BY_1

	TCCR1B &= (MASK_VALUE);
	TCCR1B |= DIV_BY_1;
#elif TIMER1_PRESCALER == DIV_BY_8
	TCCR1B &= MASK_VALUE;
	TCCR1B |= DIV_BY_8;
#elif TIMER1_PRESCALER == DIV_BY_64
	TCCR1B &= MASK_VALUE;
	TCCR1B |= DIV_BY_64;
#elif TIMER1_PRESCALER == DIV_BY_256
	TCCR1B &= MASK_VALUE;
	TCCR1B |= DIV_BY_256;
#elif TIMER1_PRESCALER == DIV_BY_1024
	TCCR1B &= MASK_VALUE;
	TCCR1B |= DIV_BY_1024;
#else

#endif

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


