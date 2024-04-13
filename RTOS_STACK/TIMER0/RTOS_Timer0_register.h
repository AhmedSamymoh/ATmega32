/*
 * Timer0_register.h
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_TIMER0_TIMER0_REGISTER_H_
#define MCAL_TIMER0_TIMER0_REGISTER_H_

#define HWREG8(_REG)		 	*( (volatile uint8 *)(_REG) )

/*TCCR0 - Timer/Counter Control Register*/
#define	TCCR0 			 *((volatile uint8 *)(0x53))
#define TCCR0_WGM00			6
#define TCCR0_COM01			5
#define TCCR0_COM00			4
#define TCCR0_WGM01			3
#define TCCR0_CS02			2
#define TCCR0_CS01			1
#define TCCR0_CS00			0

#define TCNT0				*((volatile uint8 *)(0x52))


/*TIMSK  -  Timer/Counter Interrupt Mask Register*/
#define TIMSK			*((volatile uint8 *)(0x59))
#define TIMSK_OCIE0			1
#define TIMSK_TOIE0			0	//Timer OVF Interrupt Enable
/* OCR0  -  Output Compare Register  */
#define OCR0			*((volatile uint8 *)(0x5C))

#define MASK_VALUE		0b11111000


#endif /* MCAL_TIMER0_TIMER0_REGISTER_H_ */
