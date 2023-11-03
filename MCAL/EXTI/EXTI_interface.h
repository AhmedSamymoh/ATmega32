/*
 * EXTI_interface.h
 *
 *  Created on: Sep 22, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "EXTI_register.h"
#include "EXTI_config.h"


#define EXTI0	0
#define EXTI1	1
#define EXTI2	2

void GLOBAL_Interrupt_ENABLE();
void GLOBAL_Interrupt_DISABLE();
void EXTI_Interrupt_Init();
void EXTI_Interrupt_ENABLE(uint8 INT_no);
void EXTI_Interrupt_DISABLE(uint8 INT_no);
void EXTI_Interrupt_Set_Mode(uint8 INT_no , uint8 MODE);
void EXTI_Interrupt_Set_Callback(void (*ptr)(void) , uint8 INT_no);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
