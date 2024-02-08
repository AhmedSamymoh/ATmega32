/*
 * TIMER1_config.h
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_TIMER1_TIMER1_CONFIG_H_
#define MCAL_TIMER1_TIMER1_CONFIG_H_



/* TO CONFIGURE "PRESCALER of @Timer1 */
#define DIV_BY_1		1
#define DIV_BY_8		2
#define DIV_BY_64		3
#define DIV_BY_256		4
#define DIV_BY_1024		5

#define TIMER1_PRESCALER	DIV_BY_8



/*		PWM Mode		*/
#define FAST_PWM 		0
#define PHASE_COR		1

/*************** TO CONFIGURE PWM MODE ***************/
#define TIMER1_PWM_Mode		FAST_PWM
/*****************************************************/



/*************** TO CONFIGURE FAST PWM ***************/
#define TIMER1_FAST_PWM_MODE		NON_INVERTED_MODE
/*****************************************************/

#define INVERTED_MODE 	    0
#define NON_INVERTED_MODE 	1


#endif /* MCAL_TIMER1_TIMER1_CONFIG_H_ */
