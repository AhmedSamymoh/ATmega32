/*
 * SPI_interface.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Ahmed Samy
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"

#include "SPI_register.h"
#include "SPI_config.h"

void SPI_voidMaster_Init(void);
void SPI_voidSlave_Init(void);
uint8 SPI_u8TransmitRecieve(uint8 Data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
