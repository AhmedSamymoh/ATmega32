/*
 * Timer0_Program.c
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedSamy
 */

#include "RTOS_Timer0_interface.h"

static void (*GlobalCallBackPtrCTC)() = NULL;
static void (*GlobalCallBackPtrOVF)() = NULL;


void RTOS_TIMER0_Init(void){

#if TIMER_MODE == NORMAL_MODE
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);
#elif TIMER_MODE == CTC_MODE

	CLR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	OCR0 = TIMER0_COMP_MATCH_initVALUE;
#endif

#if INT_SRC == OVF_INT
	SET_BIT(TIMSK , TIMSK_TOIE0);
#elif INT_SRC == CTC_MODE
	SET_BIT(TIMSK , TIMSK_OCIE0);

#endif

#if PRESCALER == DIV_BY_1
	/*MASK_VALUE = 0B11111000*/
	TCCR0 &= (MASK_VALUE);
	TCCR0 |= DIV_BY_1;
#elif PRESCALER == DIV_BY_8
	TCCR0 &= MASK_VALUE;
	TCCR0 |= DIV_BY_8;
#elif PRESCALER == DIV_BY_64
	TCCR0 &= MASK_VALUE;
	TCCR0 |= DIV_BY_64;
#elif PRESCALER == DIV_BY_256
	TCCR0 &= MASK_VALUE;
	TCCR0 |= DIV_BY_256;
#elif PRESCALER == DIV_BY_1024
	TCCR0 &= MASK_VALUE;
	TCCR0 |= DIV_BY_1024;
#else
#endif

}



void RTOS_TIMER0_SetOCRvalue(uint8 Value){
	OCR0 = Value;
}

void RTOS_TIMER0_SetPreloadValue(uint8 value){
	TCNT0 = value;
}


uint8 RTOS_TIMER0_SetCallBackCTC( void (*Ptr2Fun)(void) ){

	uint8 Local_error = 1;
	if(NULL == Ptr2Fun){
		Local_error = 0;
	}else{
		GlobalCallBackPtrCTC = Ptr2Fun;
		Local_error = 1;
	}
	return Local_error;
}
uint8 RTOS_TIMER0_SetCallBackOVF( void (*Ptr2Fun)(void) ){

	uint8 Local_error = 1;
	if(NULL == Ptr2Fun){
		Local_error = 0;
	}else{
		GlobalCallBackPtrOVF = Ptr2Fun;
		Local_error = 1;
	}
	return Local_error;
}



void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	GlobalCallBackPtrCTC();
}

