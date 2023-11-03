/*
 * PWM_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: AhmedSamy
 */

#include "PWM_interface.h"


void PWM_Init(void){

#if PWM_TYPE == FAST_PWM
	SET_BIT(TCCR0 ,TCCR0_WGM00);
	SET_BIT(TCCR0 ,TCCR0_WGM01);
#elif PWM_TYPE == PH_COR
	SET_BIT(TCCR0 ,TCCR0_WGM00);
	CLR_BIT(TCCR0 ,TCCR0_WGM01);
#else
#error
	("WRONG CHOICE ");

#endif

#if PWM_PRESCALER == DIV_BY_1
	/*0B11111000*/
	TCCR0 &= (MASK_VALUE);
	TCCR0 |= DIV_BY_1;
#elif PWM_PRESCALER == DIV_BY_8
	TCCR0 &= MASK_VALUE;
	TCCR0 |= DIV_BY_8;
#elif PWM_PRESCALER == DIV_BY_64
	TCCR0 &= MASK_VALUE;
	TCCR0 |= DIV_BY_64;
#elif PWM_PRESCALER == DIV_BY_256
	TCCR0 &= MASK_VALUE;
	TCCR0 |= DIV_BY_256;
#elif PWM_PRESCALER == DIV_BY_1024
	TCCR0 &= MASK_VALUE;
	TCCR0 |= DIV_BY_1024;
#else
#error
	("WRONG CHOICE OF TIMER FREQ");

#endif



}


void PWM_SetMode(uint8 Mode){
	switch(Mode){
	case INVERTED_MODE:
		SET_BIT(TCCR0 , TCCR0_COM00);
		SET_BIT(TCCR0 , TCCR0_COM01);
		break;
	case NON_INVERTED_MODE:
		CLR_BIT(TCCR0 , TCCR0_COM00);
		SET_BIT(TCCR0 , TCCR0_COM01);
		break;
	default:
		break;
	}
}

void PWM_SetOCRvalue(uint8 Value){
	OCR0 = Value;
}
