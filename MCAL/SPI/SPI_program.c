/*
 * SPI_program.c
 *
 *  Created on: Nov 3, 2023
 *      Author: AhmedSamy
 */

#include "SPI_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

/*Helper Function*/
static void SPI_SetClk(void);



void SPI_voidMaster_Init(void){
	/*SCK*/
	DIO_SetPinDirection(PORT_B,PIN_7,PIN_OUTPUT);
	/*MISO*/
	DIO_SetPinDirection(PORT_B,PIN_6,PIN_INPUT);
	/*MOSI*/
	DIO_SetPinDirection(PORT_B,PIN_5,PIN_OUTPUT);
	/*SS*/
	DIO_SetPinInputPullup(PORT_B, PIN_4);

	/*Master Initialization*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*Configure SPI CLK @SPI_config.h*/
	SPI_SetClk();

	/*SPI Enable Peripheral */
	SET_BIT(SPCR, SPCR_SPE);

	/* SPI Interrupt Enable*/
	//SET_BIT(SPCR, SPCR_SPIE);
}



void SPI_voidSlave_Init(void){
	/*SCK*/
	DIO_SetPinDirection(PORT_B,PIN_7,PIN_INPUT);
	/*MISO*/
	DIO_SetPinDirection(PORT_B,PIN_6,PIN_OUTPUT);
	/*MOSI*/
	DIO_SetPinDirection(PORT_B,PIN_5,PIN_INPUT);
	/*SS*/
	DIO_SetPinDirection(PORT_B,PIN_4,PIN_INPUT);

	/*Slave Initialization*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*SPI Enable Peripheral */
	SET_BIT(SPCR, SPCR_SPE);
}



uint8 SPI_u8TransmitRecieve(uint8 TxData){
	/*Send Data*/
	SPDR = TxData;

	/*Polling until transfer complete*/
	while(0 == GET_BIT(SPSR,SPSR_SPIF));

	/*Get The exchanged Data*/
	return SPDR;
}



static void SPI_SetClk(void){


#if SPI_PRESCALER == fosc_DIV_BY_4
	CLR_BIT(SPCR ,SPCR_SPR0);
	CLR_BIT(SPCR ,SPCR_SPR1);

	CLR_BIT(SPSR ,SPSR_SPI2X);

#elif SPI_PRESCALER == fosc_DIV_BY_16
	SET_BIT(SPCR ,SPCR_SPR0);
	CLR_BIT(SPCR ,SPCR_SPR1);

	CLR_BIT(SPSR ,SPSR_SPI2X);
#elif SPI_PRESCALER == fosc_DIV_BY_64
	CLR_BIT(SPCR ,SPCR_SPR0);
	SET_BIT(SPCR ,SPCR_SPR1);

	CLR_BIT(SPSR ,SPSR_SPI2X);
#elif SPI_PRESCALER == fosc_DIV_BY_128
	SET_BIT(SPCR ,SPCR_SPR0);
	SET_BIT(SPCR ,SPCR_SPR1);

	CLR_BIT(SPSR ,SPSR_SPI2X);
#elif SPI_PRESCALER == fosc_DIV_BY_2
	CLR_BIT(SPCR ,SPCR_SPR0);
	CLR_BIT(SPCR ,SPCR_SPR1);

	SET_BIT(SPSR ,SPSR_SPI2X);
#elif SPI_PRESCALER == fosc_DIV_BY_8
	SET_BIT(SPCR ,SPCR_SPR0);
	CLR_BIT(SPCR ,SPCR_SPR1);

	SET_BIT(SPSR ,SPSR_SPI2X);
#elif SPI_PRESCALER == fosc_DIV_BY_32
	CLR_BIT(SPCR ,SPCR_SPR0);
	SET_BIT(SPCR ,SPCR_SPR1);

	SET_BIT(SPSR ,SPSR_SPI2X);

#endif
}
