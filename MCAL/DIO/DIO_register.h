/*
 * DIO_register.h
 *
 *  Created on: Sep 1, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include <util/delay.h>

#define F_CPU 8000000

#define HWREG8(_REG)		 	*( (volatile uint8 *)(_REG) )

/* Port A */
#define PORTA_register			HWREG8(0x3B) //Memory Mapped Address
#define DDRA_register			HWREG8(0x3A)
#define	PINA_register           HWREG8(0x39)

/* Port B */
#define PORTB_register          HWREG8(0x38)
#define DDRB_register           HWREG8(0x37)
#define PINB_register           HWREG8(0x36)
/* Port C */
#define PORTC_register          HWREG8(0x35)
#define DDRC_register           HWREG8(0x34)
#define PINC_register           HWREG8(0x33)
/* Port D */
#define PORTD_register          HWREG8(0x32)
#define DDRD_register           HWREG8(0x31)
#define PIND_register           HWREG8(0x30)








#endif /* MCAL_DIO_DIO_REGISTER_H_ */
