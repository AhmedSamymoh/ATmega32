/*
 * hal_ir.c
 *
 *  Created on: Feb 9, 2024
 *      Author: AhmedSamy
 */
#include "hal_ir.h"

void IR_Init_Pin(uint8 PortNo , uint8 PinNo ){
	DIO_SetPinDirection(PortNo , PinNo , PIN_INPUT);
}
void IR_Init_ExtI_Pin(uint8 EXTIn){
	switch(EXTIn){
		case EXTI0:	DIO_SetPinDirection(PORT_D , PIN_2 , PIN_INPUT);
			break;
		case EXTI1:	DIO_SetPinDirection(PORT_D , PIN_3 , PIN_INPUT);
			break;
		case EXTI2:	DIO_SetPinDirection(PORT_B , PIN_2 , PIN_INPUT);
			break;
		default:
			break;
	}
	//GLOBAL_Interrupt_ENABLE();
	EXTI_Interrupt_Init();
	EXTI_Interrupt_ENABLE(EXTIn);
	EXTI_Interrupt_Set_Mode(EXTI0 , RISING_EDGE_MODE);
}


/*if i don't use External Interrupt*/
uint8 IR_Read_Pin(uint8 PortNo , uint8 PinNo ){
	uint8 Pin_State = DIO_GetPinValue(PortNo,PinNo);
	uint8 IR_Sensor_s = obstacle_not_detected;
	if(Pin_State == PIN_LOW)
	{
		IR_Sensor_s = obstacle_detected;
	}
	else if(Pin_State == PIN_LOW)
	{
		IR_Sensor_s = obstacle_not_detected;
	}
	return IR_Sensor_s;

}
