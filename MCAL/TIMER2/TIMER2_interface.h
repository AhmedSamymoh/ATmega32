/*
 * TIMER2_interface.h
 *
 *  Created on: Feb 28, 2024
 *      Author: AhmedSamy
 */

#ifndef MCAL_TIMER2_TIMER2_INTERFACE_H_
#define MCAL_TIMER2_TIMER2_INTERFACE_H_

#include "TIMER2_register.h"
#include "TIMER2_config.h"

#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"



void  TIMER2_Init(void);
uint8 TIMER2_SetCallBackCTC( void (*Ptr2Fun)(void) );
uint8 TIMER2_SetCallBackOVF( void (*Ptr2Fun)(void) );

void  TIMER2_PWM_Init(uint8 OCRvalue);
void  TIMER2_SetOCRvalue(uint8 Value);
void  TIMER2_SetPreloadValue(uint8 Value);



#endif /* MCAL_TIMER2_TIMER2_INTERFACE_H_ */
