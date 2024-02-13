/*
 * ADC_program.c
 *
 *  Created on: Sep 30, 2023
 *      Author: AhmedSamy
 */
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_privete.h"
#include "ADC_register.h"
#include "../../MCAL/DIO/DIO_interface.h"





void ADC_Init(uint8 Channel){
	/*Initialize the pin's Direction to be input*/
	DIO_SetPinDirection(PORT_A,Channel,PIN_INPUT);

	/*Set Prescaler to be divided by 128 */
	SET_BIT(ADCSRA , ADCSRA_ADPS0);
	SET_BIT(ADCSRA , ADCSRA_ADPS1);
	SET_BIT(ADCSRA , ADCSRA_ADPS2);


	/*AVCC as reference Voltage*/
	SET_BIT(ADMUX , ADMUX_REFS0);
	CLR_BIT(ADMUX , ADMUX_REFS1);

	/* No Interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	/*Activate the Result*/
	CLR_BIT(ADMUX , ADMUX_ADLAR);

	/*Enable ADC Peripheral*/
	SET_BIT(ADCSRA , ADCSRA_ADEN);

}

uint16 ADC_GetChannelReading(uint8 Channel){
	/*Clear the MUX bits in ADMUX register */
	if(Channel >= 0 && Channel <=7){
		ADMUX &= 0b11100000;
		ADMUX |= Channel;
	}else{/*Nothing*/}

	/*Start Conversion*/
	SET_BIT(ADCSRA , ADCSRA_ADSC);

	/*Polling until the conversion complete*/
	while(!GET_BIT(ADCSRA , ADCSRA_ADIF));

	/*Clear the conversion complete flag*/
	SET_BIT(ADCSRA , ADCSRA_ADIF);

	return ADC;
}

uint32 ADC_Mapping(uint32 Range_X_Minimum ,uint32 Range_X_Maximum ,uint32 Range_Y_Minimum ,uint32 Range_Y_Maximum , uint32 X_Reading){

	uint32 ratio = (Range_Y_Maximum - Range_Y_Minimum)  / (Range_X_Maximum - Range_X_Minimum);

	uint32 Y ;

	Y = (( (X_Reading - Range_X_Minimum) * ratio) + Range_Y_Minimum);

	return Y;
}
