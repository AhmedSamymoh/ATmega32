/*
 * hal_stepper.h
 *
 *  Created on: Feb 13, 2024
 *      Author: AhmedSamy
 */

#ifndef HAL_STEPPER_MOTOR_HAL_STEPPER_H_
#define HAL_STEPPER_MOTOR_HAL_STEPPER_H_


#include "../../MCAL/DIO/DIO_interface.h"

/*28BYJI48 Stepper Motor*/

typedef struct{
	uint8 Blue_Pin;
	uint8 Pink_Pin;
	uint8 Yellow_Pin;
	uint8 Orange_Pin;
	uint8 Port;
} stepper_t;

void Stepper_Init(stepper_t * _stepper);
void Stepper_SetAngle(stepper_t * _stepper ,uint8 angle);
void Stepper_RotateCW(stepper_t * _stepper);
void Stepper_RotateCCW(stepper_t * _stepper);
void Stepper_Stop(stepper_t * _stepper);


#endif /* HAL_STEPPER_MOTOR_HAL_STEPPER_H_ */
