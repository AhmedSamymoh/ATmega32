/*
 * Timer0_config.h
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedSamy
*/

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_

/*TIMER0 SELECT MODE:*/
#define NORMAR_MODE 	0
#define CTC_MODE	 	1

#define TIMER_MODE	 	CTC_MODE


/*TO CONFIGURE INTERRUPT SOURCE*/
#define OVF_INT 		0
#define CTC_INT 	 	1

#define INT_SRC	 		CTC_INT

/* TO CONFIGURE TIMER FREQUANCY "PRESCALER" */
#define DIV_BY_1		1
#define DIV_BY_8		2
#define DIV_BY_64		3
#define DIV_BY_256		4
#define DIV_BY_1024		5

#define PRESCALER		DIV_BY_64


#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
