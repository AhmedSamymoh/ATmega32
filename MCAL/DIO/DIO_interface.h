/*
 * DIO_interface.h
 *
 *  Created on: Sep 1, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/* Section : Includes */
#include "DIO_register.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Section: Data Type Declarations */


/* Section: Macro Declarations */
#define PORT_A		0
#define PORT_B		1
#define PORT_C		2
#define PORT_D		3

#define PIN_0		0
#define PIN_1		1
#define PIN_2		2
#define PIN_3		3
#define PIN_4		4
#define PIN_5		5
#define PIN_6		6
#define PIN_7		7

#define PORT_INPUT			0x00
#define PORT_OUTPUT			0xFF

#define PORT_LOW			0x00
#define PORT_HIGH			0xFF

#define PIN_INPUT			0x00
#define PIN_OUTPUT			0x01

#define PIN_LOW				0x00
#define PIN_HIGH			0x01


/* Section: Macro Functions Declarations */

/* Section: Function Declarations */

/*--------- PORT ---------*/
void  DIO_SetPortDirection(uint8 PortNo , uint8 Direction);
void  DIO_SetPortValue(uint8 PortNo , uint8 Value);
uint8 DIO_GetPortValue(uint8 PortNo);
/*--------- PIN ---------*/
void  DIO_SetPinDirection(uint8 PortNo , uint8 PinNo , uint8 Direction);
void  DIO_SetPinValue(uint8 PortNo , uint8 PinNo , uint8 Value);
void  DIO_SetPinInputPullup(uint8 PortNo , uint8 PinNo);
void DIO_TogPinValue(uint8 PortNo, uint8 PinNo);
uint8 DIO_GetPinValue(uint8 PortNo, uint8 PinNo);




#endif /* MCAL_DIO_DIO_INTERFACE_H_ */


