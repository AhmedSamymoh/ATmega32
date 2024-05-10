/*
 * I2C_register.h
 *
 *  Created on: Dec 20, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_I2C_I2C_REGISTER_H_
#define MCAL_I2C_I2C_REGISTER_H_

#include  "../../BIT_MATH.h"
#include  "../../STD_TYPES.h"

/*TWS: TWI Status*/
#define START_ACK				0x08   /* Start Condition has been sent */
#define REP_START_ACK			0x10   /* Repeat start */
#define SLAVE_ADD_AND_WR_ACK	0x18   /* Master transmit ( slave address + Write request) ACK */
#define SLAVE_ADD_AND_RD_ACK	0x40   /* Master transmit ( slave address + Read request) ACK */
#define MSTR_WR_BYTE_ACK		0x28   /* Master Received data  ACK */
#define MSTR_RD_BYTE_WITH_ACK	0x50   /* Master Received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK	0x58   /* Master Received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ   0xA8   /* Slave address is received with read request*/
#define SLAVE_ADD_RCVD_WR_REQ   0x60   /* Slave address is received with write request */
#define SLAVE_DATA_RECEIVED 	0x80   /*A Byte is received */
#define SLAVE_DATA_TRANSMITTED  0xB8   /* Written byte is transmitted */

/* TWI Bit Rate Register - TWBR */
#define TWBR			( *(volatile uint8 *)(0x20) )

/* TWI Control Register – TWCR */
#define TWCR			( *(volatile uint8 *)(0x56) )
#define TWCR_TWINT		7			   /*Interrupt Flag*/
#define TWCR_TWEA		6			   /*Enable Acknowledge*/
#define TWCR_TWSTA		5			   /*Start Condition*/
#define TWCR_TWSTO		4			   /*Stop Condition*/
#define TWCR_TWWC		3		       /*Write Collision*/
#define TWCR_TWEN		2			   /*Enable*/
#define TWCR_TWIE		0			   /*Interrupt Enable*/

/* TWI Status Register – TWSR */
#define TWSR			( *(volatile uint8 *)(0x21) )
#define TWSR_TWPS1		1
#define TWSR_TWPS0 		0

/* TWI Data Register – TWDR */
#define TWDR			( *(volatile uint8 *)(0x23) )

/* TWI Address Register – TWDR */
#define TWAR			( *(volatile uint8 *)(0x22) )
#define TWAR_TWGCE		0			   /*General Call recognition Enable*/

#endif /* MCAL_I2C_I2C_REGISTER_H_ */
