/*
 * SPI_register.h
 *
 *  Created on: Apr 20, 2024
 *      Author: AhmedSamy
 */

#ifndef MCAL_SPI_SPI_REGISTER_H_
#define MCAL_SPI_SPI_REGISTER_H_


/*SPDR - SPI Data Register*/
#define SPDR				( *(volatile uint8 *)(0x2F) )

/*SPSR - SPI Status Register*/
#define SPSR				( *(volatile uint8 *)(0x2E) )

#define SPSR_SPIF			7 	/* SPI Interrupt Flag*/
#define SPSR_WCOL			6 	/* SPI Write COLlision Flag*/
#define SPSR_SPI2X			0 	/* SPI Prescaler bit 2 (Double Speed)*/

/*SPCR - SPI Control Register*/
#define SPCR				( *(volatile uint8 *)(0x2D) )

#define SPCR_SPIE			7	/* SPI Interrupt Enable*/
#define SPCR_SPE			6 	/*SPI Enable Peripheral */
#define SPCR_DORD			5	/*Data Order*/
#define SPCR_MSTR			4 	/*Master/Slave */
#define SPCR_CPOL			3	/*Clock Polarity Leading Edge(Rising 0 /Falling 1)*/
#define SPCR_CPHA			2	/*Clock Phase Leading Edge(Setup 1 /Sample 0)*/
#define SPCR_SPR1			1	/* SPI Prescaler bit 1*/
#define SPCR_SPR0			0	/* SPI Prescaler bit 0*/











#endif /* MCAL_SPI_SPI_REGISTER_H_ */
