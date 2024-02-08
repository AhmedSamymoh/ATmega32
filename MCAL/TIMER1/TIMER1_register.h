/*
 * TIMER1_register.h
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_TIMER1_TIMER1_REGISTER_H_
#define MCAL_TIMER1_TIMER1_REGISTER_H_


#define  TCCR1A 		 *( (volatile uint8 *)(0x4F) )

#define  TCCR1A_COM1A1		7
#define  TCCR1A_COM1A0		6
#define  TCCR1A_COM1B1		5
#define  TCCR1A_COM1B0		4
#define  TCCR1A_FOC1A		3
#define  TCCR1A_FOC1B		2
#define  TCCR1A_WGM11		1
#define  TCCR1A_WGM10		0

/*Timer/Counter1 Control Register B – TCCR1B */
#define  TCCR1B 		 *( (volatile uint8 *)(0x4E) )
#define  TCCR1B_ICNC1		7
/* Input Capture Edge Select*/
#define  TCCR1B_ICES1		6
#define  TCCR1B_WGM13		4
#define  TCCR1B_WGM12		3

/*  CS12:0: Clock Select (Prescaler)*/
#define  TCCR1B_CS12		2
#define  TCCR1B_CS11		1
#define  TCCR1B_CS10		0



#define  TCNT1 		     *( (volatile uint16 *)(0x4C) )
#define  OCR1A 		     *( (volatile uint16 *)(0x4A) )
#define  ICR1 		     *( (volatile uint16 *)(0x46) )

/*TIMSK  -  Timer/Counter Interrupt Mask Register*/

#define TIMSK			*((volatile uint8 *)(0x59))
/*Input Capture Interrupt Enable*/
#define  TIMSK_TICIE1		5




#endif /* MCAL_TIMER1_TIMER1_REGISTER_H_ */
