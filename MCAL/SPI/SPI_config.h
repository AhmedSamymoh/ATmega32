/*
 * SPI_config.h
 *
 *  Created on: Apr 20, 2024
 *      Author: AhmedSamy
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

/* TO CONFIGURE Clock FREQUANCY "PRESCALER" */
#define fosc_DIV_BY_4		1
#define fosc_DIV_BY_16		2
#define fosc_DIV_BY_64		3
#define fosc_DIV_BY_128		4
#define fosc_DIV_BY_2		5
#define fosc_DIV_BY_8		6
#define fosc_DIV_BY_32		7

#define SPI_PRESCALER		fosc_DIV_BY_16



#endif /* MCAL_SPI_SPI_CONFIG_H_ */
