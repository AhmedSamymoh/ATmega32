/*
 * Timer0_interface.h
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "RTOS_Timer0_config.h"
#include "RTOS_Timer0_register.h"



void RTOS_TIMER0_Init(void);
uint8 RTOS_TIMER0_SetCallBackCTC( void (*Ptr2Fun)(void) );
uint8 RTOS_TIMER0_SetCallBackOVF( void (*Ptr2Fun)(void) );
void RTOS_TIMER0_SetOCRvalue(uint8 Value);
void RTOS_TIMER0_SetPreloadValue(uint8 Value);



#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
