/*
 * EXTI_config.h
 *
 *  Created on: Sep 22, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

/*PreBuild Configuration Modes*/
#define EXTI0_MODE  	RISING_EDGE_MODE
#define EXTI1_MODE  	FALLING_EDGE_MODE
#define EXTI2_MODE  	FALLING_EDGE_MODE

/*Modes*/
#define LOW_LEVEL_MODE		0
#define FALLING_EDGE_MODE	1
#define RISING_EDGE_MODE	2
#define IOC_MODE			3

/* Bit 7 – I: Global Interrupt Enable*/
#define I 			7

#define INT0 		6
#define INT1 		7
#define INT2 		5

#define INTF0 		6
#define INTF1 		7
#define INTF2 		5

/*Bits of MCUCR Register*/
#define ISC00		0
#define ISC01		1
#define ISC10		2
#define ISC11		3

#define ISC2		6


#define EXTI0	0
#define EXTI1	1
#define EXTI2	2

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
