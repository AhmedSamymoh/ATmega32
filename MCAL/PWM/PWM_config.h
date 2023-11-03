/*
 * PWM_config.h
 *
 *  Created on: Oct 27, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_PWM_PWM_CONFIG_H_
#define MCAL_PWM_PWM_CONFIG_H_

#define FAST_PWM 	0
#define PH_COR		1


#define PWM_TYPE 	FAST_PWM

/* TO CONFIGURE TIMER FREQUANCY "PRESCALER" */
#define DIV_BY_1		1
#define DIV_BY_8		2
#define DIV_BY_64		3
#define DIV_BY_256		4
#define DIV_BY_1024		5

#define PWM_PRESCALER		DIV_BY_8

#define INVERTED_MODE 	    0
#define NON_INVERTED_MODE 	1

#endif /* MCAL_PWM_PWM_CONFIG_H_ */
