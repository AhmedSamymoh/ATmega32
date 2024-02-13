/*
 * hal_ir.h
 *
 *  Created on: Feb 9, 2024
 *      Author: AhmedSamy
 */

#ifndef HAL_IR_SENSOR_HAL_IR_H_
#define HAL_IR_SENSOR_HAL_IR_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"

#define EXTI0	0
#define EXTI1	1
#define EXTI2	2

#define obstacle_detected		0x01
#define obstacle_not_detected	0x00

void IR_Init_Pin(uint8 PortNo , uint8 PinNo );
uint8 IR_Read_Pin(uint8 PortNo , uint8 PinNo );
void IR_Init_ExtI_Pin(uint8 EXTIn);


#endif /* HAL_IR_SENSOR_HAL_IR_H_ */
