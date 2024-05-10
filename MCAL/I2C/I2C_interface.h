/*
 * I2C_interface.h
 *
 *  Created on: Dec 20, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

/* Section : Includes */

#include "I2C_register.h"

/* Section: Data Type Declarations */
/*Error Status*/
typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr

} I2C_ErrStatus;

/* Section: Macro Declarations */


/* Section: Macro Functions Declarations */


/* Section: Function Declarations */


void I2C_voidMasterInit(void);
void I2C_voidSlaveInit(uint8 SlaveAddress);

I2C_ErrStatus I2C_SendStartCondition(void);
I2C_ErrStatus I2C_SendRepeatedStart(void);
I2C_ErrStatus I2C_SendSlaveAddress_Write(uint8 SlaveAddress);
I2C_ErrStatus I2C_SendSlaveAddress_Read(uint8 SlaveAddress);
I2C_ErrStatus I2C_MasterWriteDataByte(uint8 DataByte);
I2C_ErrStatus I2C_MasterReadDataByte(uint8 * DataByte);
void I2C_SendStopCondition(void);


#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
