/*
 * TIMER2_register.h
 *
 *  Created on: Feb 28, 2024
 *      Author: AhmedSamy
 */

#ifndef MCAL_TIMER2_TIMER2_REGISTER_H_
#define MCAL_TIMER2_TIMER2_REGISTER_H_

/*TCNT2 - Timer/Counter Register*/
#define TCNT2			*((volatile uint8 *)(0x44))

/*TCCR2 - Timer/Counter Register*/
#define	TCCR2 		    *((volatile uint8 *)(0x45))
#define TCCR2_FOC2    	7
#define TCCR2_WGM20   	6
#define TCCR2_COM21   	5
#define TCCR2_COM20   	4
#define TCCR2_WGM21   	3
#define TCCR2_CS22    	2
#define TCCR2_CS21    	1
#define TCCR2_CS20    	0

/* OCR2  -  Output Compare Register  */
#define OCR2			*((volatile uint8 *)(0x43))


/*TIMSK  -  Timer/Counter Interrupt Mask Register*/
#define TIMSK			*((volatile uint8 *)(0x59))
#define TIMSK_OCIE2			7	//Output Compare Match Interrupt Enable
#define TIMSK_TOIE2			6	//Timer OVF Interrupt Enable




#endif /* MCAL_TIMER2_TIMER2_REGISTER_H_ */
