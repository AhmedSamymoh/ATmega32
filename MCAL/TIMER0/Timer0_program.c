/*
 * Timer0_Program.c
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedSamy
 */

#include "Timer0_interface.h"

static void (*GlobalCallBackPtrCTC)() = NULL;
static void (*GlobalCallBackPtrOVF)() = NULL;
static void PWM_SetMode(void);

void TIMER0_Init(void){

#if TIMER_MODE == NORMAL_MODE
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);
#elif TIMER_MODE == CTC_MODE
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

#else
#error
	("WRONG CHOICE OF TIMER MODE");

#endif

#if INT_SRC == OVF_INT
	SET_BIT(TIMSK , TIMSK_TOIE0);
#elif INT_SRC == CTC_MODE
	SET_BIT(TIMSK , TIMSK_OCIE0);

#else
#error
	("WRONG CHOICE OF TIMER SRC");

#endif

#if PRESCALER == DIV_BY_1
	/*0B11111000*/
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
#error
	("WRONG CHOICE OF TIMER FREQ");

#endif

}

void TIMER0_PWM_Init(uint8 OCRvalue){
	/*OC0 Pin -> PB3*/
	DIO_SetPinDirection(PORT_B , PIN_3 , PIN_OUTPUT);

	/*FastPWM Mode*/
	SET_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	PWM_SetMode();

#if INT_SRC == OVF_INT
	SET_BIT(TIMSK , TIMSK_TOIE0);
#elif INT_SRC == CTC_MODE
	SET_BIT(TIMSK , TIMSK_OCIE0);

#else
#error
	("WRONG CHOICE OF TIMER SRC");

#endif

#if PRESCALER == DIV_BY_1
	/*0B11111000*/
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
#error
	("WRONG CHOICE OF TIMER FREQ");

#endif

	TIMER0_SetOCRvalue(OCRvalue);
}

static void PWM_SetMode(void){

#if FAST_PWM_MODE == INVERTED_MODE
	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif FAST_PWM_MODE == NON_INVERTED_MODE
	CLR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error
	("WRONG CHOICE OF TIMER FAST PWM");

#endif
}

void TIMER0_SetOCRvalue(uint8 Value){
	OCR0 = Value;
}

void TIMER0_SetPreloadValue(uint8 value){
	TCNT0 = value;
}


uint8 TIMER0_SetCallBackCTC( void (*Ptr2Fun)(void) ){

	uint8 Local_error = 1;
	if(NULL == Ptr2Fun){
		Local_error = 0;
	}else{
		GlobalCallBackPtrCTC = Ptr2Fun;
		Local_error = 1;
	}
	return Local_error;
}
uint8 TIMER0_SetCallBackOVF( void (*Ptr2Fun)(void) ){

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

/*ISR OVF MODE*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	GlobalCallBackPtrOVF();
}
