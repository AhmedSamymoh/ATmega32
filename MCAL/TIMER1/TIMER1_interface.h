/*
 * TIMER1_interface.h
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

/* Section : Includes */
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "TIMER1_register.h"
#include "Timer1_config.h"


/* Section: Data Type Declarations */


/* Section: Macro Declarations */
#define RISING_EDGE			1
#define FALLING_EDGE		0

#define MASK_VALUE		0b11111000
/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

void TIMER1_init(void);
void TIMER1_Set_OCR_Value(uint16 value);
void TIMER1_Set_TCNT_Value(uint16 value);
uint16 TIMER1_Read_TCNT_Value();

void HWICU_Init(void);
void HWICU_EdgeSelect(uint8 Edge);
void HWICU_InterruptEnable(void);
void HWICU_InterruptDisable(void);
void HWICU_SetCallBack(void (*ptr2fun)(void));
uint8 HWICU_ReadTicks(void);




#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
