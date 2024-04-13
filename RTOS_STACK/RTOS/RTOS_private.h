/*
 * RTOS_private.h
 *
 *  Created on: Apr 13, 2024
 *      Author: AhmedSamy
 */

#ifndef RTOS_STACK_RTOS_RTOS_PRIVATE_H_
#define RTOS_STACK_RTOS_RTOS_PRIVATE_H_

typedef struct{
	uint16 Periodicity;
	void (*TaskFunc)(void);
	uint8 State;
} Task_t;

void voidScheduler(void);

#endif /* RTOS_STACK_RTOS_RTOS_PRIVATE_H_ */
