/*
 * EEPROM_interface.h
 *
 *  Created on: sep 28, 2023
 *      Author: AhmedSamy
 *      Module : EEPROM 24C08
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "../../MCAL/I2C/I2C_interface.h"
#include <util/delay.h>

#define F_CPU 8000000
#define A2 			1


void EEPROM_WriteDataByte(uint8 DataByte, uint16 Address);

void EEPROM_ReadDataByte(uint8* DataByte, uint16 Address);


#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
