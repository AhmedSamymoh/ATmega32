/*
 * GIE_interface.h
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedSamy
 */

#ifndef RTOS_STACK_GIE_GIE_INTERFACE_H_
#define RTOS_STACK_GIE_GIE_INTERFACE_H_

#define SREG		*((volatile uint8*)0x5F)
#define SREG_I		7U

void GIE_voidEnableGlobal(void);

void GIE_voidDisableGlobal(void);


#endif /* RTOS_STACK_GIE_GIE_INTERFACE_H_ */
