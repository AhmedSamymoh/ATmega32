/*
 * RTOS_program.c
 *
 *  Created on: Apr 13, 2024
 *      Author: AhmedSamy
 */

#include "RTOS_interface.h"


Task_t SystemTasks[TASK_NUM] = {{0}};


void voidScheduler(void){
	static uint16 TickCounter=0;
	uint8 TaskCounter;

	TickCounter++;

	/*Loop on all tasks to check their Periodicity*/
	for(TaskCounter = 0 ; TaskCounter < TASK_NUM ; TaskCounter++){
		/*Validate if the Task NOT Suspended*/
		if(SystemTasks[TaskCounter].State == TASK_ACTIVE){

			if(	(TickCounter % SystemTasks[TaskCounter].Periodicity) == 0 ){

				/*Invoke the task function*/
				if(SystemTasks[TaskCounter].TaskFunc != 0){
					SystemTasks[TaskCounter].TaskFunc();
				}else{
					/*Nothing*/
				}
			}
		}
		else{
			/*Task is Suspended*/
		}
	}

}
void RTOS_voidStart(){
	GIE_voidEnableGlobal();
	RTOS_TIMER0_Init();
	RTOS_TIMER0_SetCallBackCTC(&voidScheduler);
}

void RTOS_voidCreateTask(uint8 u8Priority,uint16 u16Periodicity, void (*pvTaskFunc)(void)){

	/*Check if the required priority is empty or used before with another task*/
	if(SystemTasks[u8Priority].TaskFunc == 0){
		SystemTasks[u8Priority].Periodicity = u16Periodicity;
		SystemTasks[u8Priority].TaskFunc = pvTaskFunc;
		SystemTasks[u8Priority].State = TASK_ACTIVE;
	}else{
		/*Nothing*/
	}
}

void RTOS_voidDeleteTask(uint8 u8Priority){

	SystemTasks[u8Priority].Periodicity = 0;
	SystemTasks[u8Priority].TaskFunc = 0;
	SystemTasks[u8Priority].State = TASK_ACTIVE;
}

void RTOS_voidSuspendTask(uint8 u8Priority){
	SystemTasks[u8Priority].State = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(uint8 u8Priority){
	SystemTasks[u8Priority].State = TASK_ACTIVE;
}
