/*
 * PWM_interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_PWM_PWM_INTERFACE_H_
#define MCAL_PWM_PWM_INTERFACE_H_

#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "../TIMER0/Timer0_interface.h"
#include "PWM_config.h"


void PWM_Init(void);
void PWM_SetMode(uint8 Mode);
void PWM_SetOCRvalue(uint8 Value);





#endif /* MCAL_PWM_PWM_INTERFACE_H_ */
