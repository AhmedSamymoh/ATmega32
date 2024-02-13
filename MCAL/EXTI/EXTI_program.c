/*
 * EXTI_program.c
 *
 *  Created on: Sep 22, 2023
 *      Author: AhmedSamy
 */
#include "EXTI_interface.h"

void (*INT0_CALLBACK_Ptr)(void) = NULL;
void (*INT1_CALLBACK_Ptr)(void) = NULL;
void (*INT2_CALLBACK_Ptr)(void) = NULL;


void GLOBAL_Interrupt_ENABLE(){
	SET_BIT(SREG_Register, I);
}
void GLOBAL_Interrupt_DISABLE(){
	CLR_BIT(SREG_Register, I);
}


/*******************************************************************************
 * @brief Initialize the direction of a specific Port
 *
 * @parameter PortNo 		Port @(PORT_A , PORT_B , PORT_C ,PORT_D)
 * @parameter Direction 	Direction Of The Port @(PORT_INPUT , PORT_OUTPUT)
 ********************************************************************************/
void EXTI_Interrupt_Init(){
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
void EXTI_Interrupt_ENABLE(uint8 INT_no){
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


void EXTI_Interrupt_DISABLE(uint8 INT_no){
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


void EXTI_Interrupt_Set_Mode(uint8 INT_no , uint8 MODE){
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

void EXTI_Interrupt_Set_Callback(void (*ptr)(void) , uint8 INT_no){
	switch(INT_no){
		case EXTI0:
			INT0_CALLBACK_Ptr = ptr;
			break;
		case EXTI1:
			INT1_CALLBACK_Ptr = ptr;
			break;
		case EXTI2:
			INT2_CALLBACK_Ptr = ptr;
			break;
		default:
			break;
	}
}


void __vector_1 (void) __attribute__ ((signal,used, externally_visible)) ;
    void __vector_1 (void){
    	INT0_CALLBACK_Ptr();
}
void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ;
    void __vector_2 (void){
    	INT1_CALLBACK_Ptr();
}
void __vector_3 (void) __attribute__ ((signal,used, externally_visible)) ;
    void __vector_3 (void){
    	INT2_CALLBACK_Ptr();
}

