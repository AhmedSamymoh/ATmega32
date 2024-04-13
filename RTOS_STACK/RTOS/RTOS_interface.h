/*
 * RTOS_interface.h
 *
 *  Created on: Apr 13, 2024
 *      Author: AhmedSamy
 */

#ifndef RTOS_STACK_RTOS_RTOS_INTERFACE_H_
#define RTOS_STACK_RTOS_RTOS_INTERFACE_H_

#include "../GIE/GIE_interface.h"
#include "../TIMER0/RTOS_Timer0_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"



void RTOS_voidStart();
void RTOS_voidCreateTask(uint8 u8Priority,uint16 u16Periodicity, void (*pvTaskFunc)(void));
void RTOS_voidSuspendTask(uint8 u8Priority);
void RTOS_voidResumeTask(uint8 u8Priority);
void RTOS_voidDeleteTask(uint8 u8Priority);

#endif /* RTOS_STACK_RTOS_RTOS_INTERFACE_H_ */
