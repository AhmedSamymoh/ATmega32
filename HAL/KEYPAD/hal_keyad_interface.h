/*
 * hal_keyad_interface.h
 *
 *  Created on: Sep 15, 2023
 *      Author: AhmedSamy
 */

#ifndef HAL_KEYPAD_HAL_KEYAD_INTERFACE_H_
#define HAL_KEYPAD_HAL_KEYAD_INTERFACE_H_


/* Section : Includes */
#include "hal_keyad_config.h"
#include "../../MCAL/DIO/DIO_interface.h"


/* Section: Macro Declarations */
#define KEY_NOT_PRESSED 	0xFF


/* Section: Function Declarations */
void KEYPAD_init();
uint8 KEYPAD_GetPressedKey();


#endif /* HAL_KEYPAD_HAL_KEYAD_INTERFACE_H_ */
