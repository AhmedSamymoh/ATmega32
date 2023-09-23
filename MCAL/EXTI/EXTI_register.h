/*
 * EXTI_register.h
 *
 *  Created on: Sep 22, 2023
 *      Author: AhmedSamy
 */

#ifndef MCAL_EXTI_EXTI_REGISTER_H_
#define MCAL_EXTI_EXTI_REGISTER_H_


#define HWREG8(_REG)		*( (volatile uint8 *)(_REG) )
#define SREG_Register		HWREG8(0x5F)
/*MCU Control Register (EXINT0 , EXINT1)*/
#define MCUCR				HWREG8(0x55)
/*MCU Control and Status Register (EXINT2)*/
#define MCUCSR				HWREG8(0x54)
/*General Interrupt Control Register*/
#define GICR				HWREG8(0x5B)
/*General Interrupt Flag Register*/
#define GIFR				HWREG8(0x5A)



#endif /* MCAL_EXTI_EXTI_REGISTER_H_ */
