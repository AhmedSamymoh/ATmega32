/*
 * ADC_register.h
 *
 *  Created on: Sep 30, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_

#include "../../STD_TYPES.h"

/*ADC multiplexer selection register*/
#define 	ADMUX			*((volatile uint8*)(0x27))
/*Reference selection bit0*/
#define 	ADMUX_REFS0		6
/*Reference selection bit1*/
#define 	ADMUX_REFS1		7
/*ADC left adjust result*/
#define		ADMUX_ADLAR		5

/* ADCSRA control and status register A*/
#define 	ADCSRA			*((volatile uint8*)(0x26))
/*ADC enable*/
#define 	ADCSRA_ADEN    		7
/*Start Conversion*/
#define 	ADCSRA_ADSC    		6
/*Auto trigger enable*/
#define 	ADCSRA_ADATE   		5
/*Interrupt Flag*/
#define 	ADCSRA_ADIF    		4
/*Interrupt enable*/
#define		ADCSRA_ADIE    		3
/*Prescaler bit2*/
#define 	ADCSRA_ADPS2   		2
/*Prescaler bit1*/
#define 	ADCSRA_ADPS1   		1
/*Prescaler bit1*/
#define 	ADCSRA_ADPS0   		0

/*ADC high register*/
#define 	ADCH			*((volatile uint8*)(0x25))
/*ADC low register*/
#define 	ADC				*((volatile uint16*)(0x24))

#endif /* MCAL_ADC_ADC_REGISTER_H_ */
