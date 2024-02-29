/*
 * TIMER2_config.h
 *
 *  Created on: Feb 28, 2024
 *      Author: AhmedSamy
 */

#ifndef MCAL_TIMER2_TIMER2_CONFIG_H_
#define MCAL_TIMER2_TIMER2_CONFIG_H_

/*TIMER2 SELECT MODE:*/
#define TIMER2_NORMAR_MODE 	0
#define TIMER2_CTC_MODE	 	1

#define TIMER2_MODE	 	CTC_MODE

/*TO CONFIGURE INTERRUPT SOURCE*/
#define TIMER2_OVF_INT 		0
#define TIMER2_CTC_INT 	 	1

#define TIMER2_INT_SRC	CTC_INT

/* TO CONFIGURE TIMER FREQUANCY "PRESCALER" */
#define DIV_BY_1		1
#define DIV_BY_8		2
#define DIV_BY_64		3
#define DIV_BY_256		4
#define DIV_BY_1024		5

#define TIMER2_PRESCALER		DIV_BY_8

/*		PWM Mode		*/
#define FAST_PWM 		0
#define PHASE_COR		1
/*************** TO CONFIGURE PWM MODE ***************/
#define TIMER2_PWM_Mode		FAST_PWM
/*****************************************************/



/*************** TO CONFIGURE FAST PWM ***************/
#define TIMER2_FAST_PWM_MODE		NON_INVERTED_MODE
/*****************************************************/

#define INVERTED_MODE 	    0
#define NON_INVERTED_MODE 	1



#endif /* MCAL_TIMER2_TIMER2_CONFIG_H_ */
