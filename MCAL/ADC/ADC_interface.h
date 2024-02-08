/*
 * ADC_interface.h
 *
 *  Created on: Sep 30, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


/* Section : Includes */

#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_privete.h"
#include "ADC_register.h"
#include "../../STD_TYPES.h"

/* Section: Data Type Declarations */


/* Section: Macro Declarations */
#define ADMUX_Reg 	*((volatile uint8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile uint8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile uint8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile uint8*)0x24) 		// ADC Low Register


/* Section: Macro Functions Declarations */


/* Section: Function Declarations */
void ADC_Init (uint8 Channel);

uint16 ADC_GetChannelReading(uint8 Channel);

uint32 ADC_Mapping(uint32 Range_X_Minimum ,uint32 Range_X_Maximum ,uint32 Range_Y_Minimum ,uint32 Range_Y_Maximum , uint32 X_Reading);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
