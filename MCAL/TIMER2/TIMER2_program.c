/*
 * TIMER2_program.c
 *
 *  Created on: Feb 28, 2024
 *      Author: AhmedSamy
 */


#include "Timer2_interface.h"

static void (*GlobalCallBackPtrCTC)() = NULL;
static void (*GlobalCallBackPtrOVF)() = NULL;
static void PWM_SetMode(void);

void TIMER2_Init(void){

#if TIMER2_MODE == NORMAL_MODE
	CLR_BIT(TCCR2 , TCCR2_WGM20);
	CLR_BIT(TCCR2 , TCCR2_WGM21);
#elif TIMER2_MODE == CTC_MODE
	CLR_BIT(TCCR2 , TCCR2_WGM20);
	SET_BIT(TCCR2 , TCCR2_WGM21);

#endif

#if TIMER2_INT_SRC == TIMER2_OVF_INT
	SET_BIT(TIMSK , TIMSK_TOIE2);
#elif TIMER2_INT_SRC == TIMER2_CTC_MODE
	SET_BIT(TIMSK , TIMSK_OCIE2);
#endif

#if TIMER2_PRESCALER == DIV_BY_1
	/*0B11111000*/
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_1;
#elif TIMER2_PRESCALER == DIV_BY_8
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_8;
#elif TIMER2_PRESCALER == DIV_BY_64
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_64;
#elif TIMER2_PRESCALER == DIV_BY_256
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_256;
#elif TIMER2_PRESCALER == DIV_BY_1024
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_1024;

#endif
}

void TIMER2_PWM_Init(uint8 OCRvalue){
	/*OC2 Pin -> PD7*/
	DIO_SetPinDirection(PORT_D , PIN_7 , PIN_OUTPUT);

	/*FastPWM Mode*/
	SET_BIT(TCCR2 , TCCR2_WGM20);
	SET_BIT(TCCR2 , TCCR2_WGM21);

	PWM_SetMode();

#if TIMER2_PRESCALER == DIV_BY_1
	/*0B11111000*/
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_1;
#elif TIMER2_PRESCALER == DIV_BY_8
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_8;
#elif TIMER2_PRESCALER == DIV_BY_64
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_64;
#elif TIMER2_PRESCALER == DIV_BY_256
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_256;
#elif TIMER2_PRESCALER == DIV_BY_1024
	TCCR2 &= (0b11111000);
	TCCR2 |= DIV_BY_1024;

#endif

	TIMER2_SetOCRvalue(OCRvalue);
}



static void PWM_SetMode(void){

#if TIMER2_FAST_PWM_MODE == INVERTED_MODE
	SET_BIT(TCCR2 , TCCR2_COM21);
	SET_BIT(TCCR2 , TCCR2_COM20);

#elif TIMER2_FAST_PWM_MODE == NON_INVERTED_MODE
	CLR_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);
#endif
}

void TIMER2_SetOCRvalue(uint8 Value){
	OCR2 = Value;
}

void TIMER2_SetPreloadValue(uint8 value){
	TCNT2 = value;
}


uint8 TIMER2_SetCallBackCTC( void (*Ptr2Fun)(void) ){

	uint8 Local_error = 1;
	if(NULL == Ptr2Fun){
		Local_error = 0;
	}else{
		GlobalCallBackPtrCTC = Ptr2Fun;
		Local_error = 1;
	}
	return Local_error;
}
uint8 TIMER2_SetCallBackOVF( void (*Ptr2Fun)(void) ){

	uint8 Local_error = 1;
	if(NULL == Ptr2Fun){
		Local_error = 0;
	}else{
		GlobalCallBackPtrOVF = Ptr2Fun;
		Local_error = 1;
	}
	return Local_error;
}



void __vector_4(void) __attribute__((signal));
void __vector_4(void){
	GlobalCallBackPtrCTC();
}

/*ISR OVF MODE*/
void __vector_5(void) __attribute__((signal));
void __vector_5(void){
	GlobalCallBackPtrOVF();
}
