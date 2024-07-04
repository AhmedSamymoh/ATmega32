/*
 * EEPROM_program.c
 *
 *  Created on: sep 28, 2023
 *      Author: AhmedSamy
 *      Module : EEPROM 24C08
 */

#include "EEPROM_interface.h"


void EEPROM_WriteDataByte(uint8 DataByte, uint16 Address){
	/* Address : B1 B2 ByteAddress */


	/* Send Start Condition */
	I2C_SendStartCondition();

	/* Send Slave Address with write : 0b1010A2B1B2 */
	I2C_SendSlaveAddress_Write( 0b01010000 | (A2 << 2) | (Address >> 8) );

	/* Send ByteAddress to access with EEPROM */
	I2C_MasterWriteDataByte((uint8)Address);

	/* Master Write Data Byte */
	I2C_MasterWriteDataByte(DataByte);

	I2C_SendStopCondition();
	_delay_ms(20);
}

void EEPROM_ReadDataByte(uint8 * DataByte, uint16 Address){
	/* Address : B1 B2 ByteAddress */

	/* Send Start Condition */
	I2C_SendStartCondition();

	/* Send Slave Address with write : 0b1010A2B1B2 */
	I2C_SendSlaveAddress_Write( 0b01010000 | (A2 << 2) | (Address >> 8) );

	/* Send ByteAddress to access with EEPROM */
	I2C_MasterWriteDataByte((uint8)Address);

	/*to Read Data after sending ByteAddress */
	I2C_SendRepeatedStart();

	/* Send Slave Address with read : 0b1010A2B1B2 */
	I2C_SendSlaveAddress_Read( 0b01010000 | (A2 << 2) | (Address >> 8) );

	/* Master Write Data Byte */
	I2C_MasterReadDataByte(&DataByte);

	I2C_SendStopCondition();
	_delay_ms(20);

}

