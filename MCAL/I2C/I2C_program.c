/*
 * I2C_program.c
 *
 *  Created on: Dec 20, 2023
 *      Author: AhmedSamy
 */

#include "I2C_interface.h"


void I2C_voidMasterInit(void){

/* To get standard Clock speed for i2c that equal 400kHz
 * @ assuming that TWPS = 0
 * so we can get TWBR from this Formula:
 *
 *  				CPU Clock Frequency
 * SCL Frequency = _______________________
 * 					16 + 2(TWBR)* 4^(TWPS)
 * we get that 	TWBR will be equal @2
 */

	TWDR = 2;
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);

	/*Enable TWI Peripheral (I2C)*/
	SET_BIT(TWCR, TWCR_TWEN);

}
void I2C_voidSlaveInit(uint8 SlaveAddress){

	/*Initialize the node address*/
	TWAR = SlaveAddress << 1;
	/*Enable TWI Peripheral (I2C)*/
	SET_BIT(TWCR, TWCR_TWEN);
}

I2C_ErrStatus I2C_SendStartCondition(void){
	I2C_ErrStatus Local_ErrStatus = NoError;

	/* Send Start Condition on the bus */
	SET_BIT(TWCR ,TWCR_TWSTA);

	/* Clear the interrupt flag to Start the Operation*/
	SET_BIT(TWCR ,TWCR_TWINT);

	/*Polling until the interrupt flag is raised again and the operation is complete*/
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if ((TWSR & 0xF8) != START_ACK)
		Local_ErrStatus = StartConditionErr;

	return Local_ErrStatus;
}


I2C_ErrStatus I2C_SendRepeatedStart(void){
	I2C_ErrStatus Local_ErrStatus = NoError;

	/* Send Start Condition on the bus */
	SET_BIT(TWCR ,TWCR_TWSTA);

	/* Clear the interrupt flag to Start the Operation*/
	SET_BIT(TWCR ,TWCR_TWINT);

	/*Polling until the interrupt flag is raised again and the operation is complete*/
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if ((TWSR & 0xF8) != REP_START_ACK)
		Local_ErrStatus = RepeatedStartErr;

	return Local_ErrStatus;
}


I2C_ErrStatus I2C_SendSlaveAddress_Write(uint8 SlaveAddress){
	I2C_ErrStatus Local_ErrStatus = NoError;

	/*Clear the start Condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR = SlaveAddress << 1;

	/* Configure to Write Data */
	CLR_BIT(TWCR ,TWCR_TWSTA);

	/* Clear the interrupt flag to Start the Operation*/
	SET_BIT(TWCR ,TWCR_TWINT);
	/*Polling until the interrupt flag is raised again and the operation is complete*/
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if ((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
		Local_ErrStatus = SlaveAddressWithWriteErr;


	return Local_ErrStatus;

}
I2C_ErrStatus I2C_SendSlaveAddress_Read(uint8 SlaveAddress){
	I2C_ErrStatus Local_ErrStatus = NoError;

	/*Clear the start Condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR = SlaveAddress << 1;

	/* Configure to Read Data */
	SET_BIT(TWCR ,TWCR_TWSTA);



	if ((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
		Local_ErrStatus = SlaveAddressWithReadErr;

	return Local_ErrStatus;

}
I2C_ErrStatus I2C_MasterWriteDataByte(uint8 DataByte){
	I2C_ErrStatus Local_ErrStatus = NoError;

	/*Write the Data Byte*/
	TWDR = DataByte;

	/* Clear the interrupt flag to Start the Operation*/
	SET_BIT(TWCR ,TWCR_TWINT);
	/*Polling until the interrupt flag is raised again and the operation is complete*/
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if ((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
		Local_ErrStatus = MasterWriteByteErr;


	return Local_ErrStatus;

}


I2C_ErrStatus I2C_MasterReadDataByte(uint8 * DataByte){
	I2C_ErrStatus Local_ErrStatus = NoError;

	/*Enable Master ACK*/
	SET_BIT(TWCR,TWCR_TWEA);

	/* Clear the interrupt flag to Allow the Slave to send Data*/
	SET_BIT(TWCR ,TWCR_TWINT);
	/*Polling until the interrupt flag is raised again and the operation is complete*/
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if ((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
		Local_ErrStatus = MasterReadByteErr;

	/* Read received data */
	*DataByte = TWDR;

	return Local_ErrStatus;

}
void I2C_SendStopCondition(void){

	/*Generate stop condition on the bus*/
	SET_BIT(TWCR ,TWCR_TWSTO);
	/* Clear the interrupt flag to Allow the Slave to send Data*/
	SET_BIT(TWCR ,TWCR_TWINT);

}


