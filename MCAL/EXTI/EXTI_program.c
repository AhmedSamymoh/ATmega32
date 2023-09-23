/*
 * EXTI_program.c
 *
 *  Created on: Sep 22, 2023
 *      Author: AhmedSamy
 */
#include "EXTI_interface.h"

void GLOBAL_Interrupt_ENABLE(){
	SET_BIT(SREG_Register, I);
}
void GLOBAL_Interrupt_DISABLE(){
	SET_BIT(SREG_Register, I);
}

void EXT_Interrupt_Init(){
#if EXTI0_MODE == LOW_LEVEL_MODE
	CLR_BIT(MCUCR , ISC00);
	CLR_BIT(MCUCR , ISC01);
#elif EXTI0_MODE == FALLING_EDGE_MODE
	CLR_BIT(MCUCR , ISC00);
	SET_BIT(MCUCR , ISC01);
#elif EXTI0_MODE == RISING_EDGE_MODE
	SET_BIT(MCUCR , ISC00);
	SET_BIT(MCUCR , ISC01);
#elif EXTI0_MODE == IOC_MODE
	SET_BIT(MCUCR , ISC00);
	CLR_BIT(MCUCR , ISC01);
#else
#endif

#if EXTI1_MODE == LOW_LEVEL_MODE
	CLR_BIT(MCUCR , ISC10);
	CLR_BIT(MCUCR , ISC11);
#elif EXTI1_MODE == FALLING_EDGE_MODE
	CLR_BIT(MCUCR , ISC10);
	SET_BIT(MCUCR , ISC11);
#elif EXTI1_MODE == RISING_EDGE_MODE
	SET_BIT(MCUCR , ISC10);
	SET_BIT(MCUCR , ISC11);
#elif EXTI1_MODE == IOC_MODE
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#else
#endif


#if EXTI2_MODE == FALLING_EDGE_MODE
	CLR_BIT(MCUCSR , ISC2);
#elif EXTI2_MODE == RISING_EDGE_MODE
	SET_BIT(MCUCSR , ISC2);
#else
#endif

}
void EXT_Interrupt_ENABLE(uint8 INT_no){
	switch(INT_no)
	{
		case EXTI0:
			SET_BIT(GICR , INT0);
			break;
		case EXTI1:
			SET_BIT(GICR , INT1);
			break;
		case EXTI2:
			SET_BIT(GICR , INT2);
			break;
		default:
			break;
	}
}
void EXT_Interrupt_DISABLE(uint8 INT_no){
	switch(INT_no)
		{
			case EXTI0:
				CLR_BIT(GICR , INT0);
				break;
			case EXTI1:
				CLR_BIT(GICR , INT1);
				break;
			case EXTI2:
				CLR_BIT(GICR , INT2);
				break;
			default:
				break;
		}
}
void EXT_Interrupt_Set_Mode(uint8 INT_no , uint8 MODE){
	switch(INT_no)
	{
		case EXTI0:
			switch(MODE)
			{
				case LOW_LEVEL_MODE:
					CLR_BIT(MCUCR , ISC00);
					CLR_BIT(MCUCR , ISC01);
					break;
				case FALLING_EDGE_MODE:
					CLR_BIT(MCUCR , ISC00);
					SET_BIT(MCUCR , ISC01);
					break;
				case IOC_MODE:
					SET_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
					break;
				case RISING_EDGE_MODE:
					SET_BIT(MCUCR , ISC00);
					SET_BIT(MCUCR , ISC01);
					break;
				default:
						break;
			}
			break;
		case EXTI1:
			switch(MODE)
			{
				case LOW_LEVEL_MODE:
					CLR_BIT(MCUCR , ISC10);
					CLR_BIT(MCUCR , ISC11);
					break;
				case FALLING_EDGE_MODE:
					CLR_BIT(MCUCR , ISC10);
					SET_BIT(MCUCR , ISC11);
					break;
				case IOC_MODE:
					SET_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);
					break;
				case RISING_EDGE_MODE:
					SET_BIT(MCUCR , ISC10);
					SET_BIT(MCUCR , ISC11);
					break;
				default:
						break;
			}
			break;
		case EXTI2:
			switch(MODE)
			{

				case FALLING_EDGE_MODE:
					CLR_BIT(MCUCSR , ISC2);
					break;
				case RISING_EDGE_MODE:
					SET_BIT(MCUCSR , ISC2);
					break;
				default:
					break;

			}
			break;
		default:
			break;
	}
}
