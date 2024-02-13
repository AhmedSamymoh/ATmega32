/*
 * DIO_program.c
 *
 *  Created on: Sep 1, 2023
 *      Author: AhmedSamy
 */
#include "DIO_interface.h"


/*******************************************************************************
 * @brief Initialize the direction of a specific Port
 *
 * @parameter PortNo 		Port @(PORT_A , PORT_B , PORT_C ,PORT_D)
 * @parameter Direction 	Direction Of The Port @(PORT_INPUT , PORT_OUTPUT)
 ********************************************************************************/
void  DIO_SetPortDirection(uint8 PortNo , uint8 Direction)
{
	switch(PortNo)
	{
		case PORT_A:
				DDRA_register = Direction;
			break;

		case PORT_B:
				DDRB_register = Direction;
			break;

		case PORT_C:
				DDRC_register = Direction;
			break;
		case PORT_D:
				DDRD_register = Direction;
			break;
		default:
			break;
	}
}


/*******************************************************************************
 * @brief Set the value of a specific Port
 *
 * @parameter PortNo 		Port @(PORT_A , PORT_B , PORT_C ,PORT_D)
 * @parameter Value 	Direction Of The Port @(PORT_HIGH , PORT_LOW)
 ********************************************************************************/
void  DIO_SetPortValue(uint8 PortNo , uint8 Value)
{
	switch(PortNo)
	{
		case PORT_A:
				PORTA_register = Value;
			break;

		case PORT_B:
				PORTB_register = Value;
			break;

		case PORT_C:
				PORTC_register = Value;
			break;

		case PORT_D:
				PORTD_register = Value;
			break;

		default:
			break;
	}
}


/*******************************************************************************
 * @brief Set the value of a specific Port
 *
 * @parameter PortNo 		Port @(PORT_A , PORT_B , PORT_C ,PORT_D)
 * @return 					local_return (1 , 0)
 ********************************************************************************/
uint8 DIO_GetPortValue(uint8 PortNo)
{
	uint8 local_return;
	if( (PortNo >= PORT_A) && (PortNo <= PORT_D) ) // Validation
	{
		switch(PortNo)
		{
			case PORT_A:
				local_return = PINA_register;
				break;
			case PORT_B:
				local_return = PINB_register;
				break;
			case PORT_C:
				local_return = PINC_register;
				break;
			case PORT_D:
				local_return = PIND_register;
				break;
			default:
				break;
		}

	}else{
		return 0;
	}
	return local_return;
}


/*******************************************************************************
 * @brief Set Direction of a specific Pin
 *
 * @parameter PortNo 		Port @(PORT_A , PORT_B , PORT_C ,PORT_D)
 * @parameter PinNo 		Pin Port @(PIN_0 - PIN_7)
 * @parameter Direction 	Direction Of The Port @(PIN_OUTPUT , PIN_INPUT)
 ********************************************************************************/
void  DIO_SetPinDirection(uint8 PortNo , uint8 PinNo , uint8 Direction)
{
	if( (PinNo >= PIN_0) && (PinNo <= PIN_7) && (PortNo >= PORT_A) && (PortNo <= PORT_D) ) // Validation
	{
		switch(PortNo)
		{
			case PORT_A:
				if(Direction == PIN_OUTPUT)
				{
					SET_BIT(DDRA_register , PinNo);
				}else if(Direction == PIN_INPUT){
					CLR_BIT(DDRA_register , PinNo);
				}else{

				}
				break;
			case PORT_B:
				if(Direction == PIN_OUTPUT)
				{
					SET_BIT(DDRB_register , PinNo);
				}else if(Direction == PIN_INPUT){
					CLR_BIT(DDRB_register , PinNo);
				}else{

				}
				break;
			case PORT_C:
				if(Direction == PIN_OUTPUT)
				{
					SET_BIT(DDRC_register , PinNo);
				}else if(Direction == PIN_INPUT){
					CLR_BIT(DDRC_register , PinNo);
				}else{

				}
				break;
			case PORT_D:
				if(Direction == PIN_OUTPUT)
				{
					SET_BIT(DDRD_register , PinNo);
				}else if(Direction == PIN_INPUT){
					CLR_BIT(DDRD_register , PinNo);
				}else{

				}
				break;

			default:
				break;
		}
	}else{

	}

}

/*******************************************************************************
 * @brief Set a specific Pin Input Pull up
 *
 * @parameter PortNo 		Port @(PORT_A , PORT_B , PORT_C ,PORT_D)
 * @parameter PinNo 		Pin Port @(PIN_0 - PIN_7)
 ********************************************************************************/
void  DIO_SetPinInputPullup(uint8 PortNo , uint8 PinNo)
{
	if( (PinNo >= PIN_0) && (PinNo <= PIN_7) && (PortNo >= PORT_A) && (PortNo <= PORT_D) ) // Validation
	{
		switch(PortNo)
		{
			case PORT_A:
					CLR_BIT(DDRA_register , PinNo);
					SET_BIT(PORTA_register , PinNo);
				break;
			case PORT_B:
					CLR_BIT(DDRB_register , PinNo);
					SET_BIT(PORTB_register , PinNo);
				break;
			case PORT_C:
					CLR_BIT(DDRC_register , PinNo);
					SET_BIT(PORTC_register , PinNo);
				break;
			case PORT_D:
					CLR_BIT(DDRD_register , PinNo);
					SET_BIT(PORTD_register , PinNo);
				break;
			default:
				break;
		}
	}else{
		/*Nothing*/
	}

}


/*******************************************************************************
 * @brief Set the value of a specific Pin
 *
 * @parameter PortNo 		Port @(PORT_A , PORT_B , PORT_C ,PORT_D)
 * @parameter PinNo 		Pin Port @(PIN_0 - PIN_7)
 * @parameter Direction 	Direction Of The Port @(PORT_HIGH , PORT_LOW)
 ********************************************************************************/
void  DIO_SetPinValue(uint8 PortNo , uint8 PinNo , uint8 Value)
{
	if( (PinNo >= PIN_0) && (PinNo <= PIN_7) )// Validation
	{
		switch(PortNo)
			{
				case PORT_A:
					if(Value == PIN_HIGH)
					{
						SET_BIT(PORTA_register , PinNo);
					}else if(Value == PIN_LOW){
						CLR_BIT(PORTA_register , PinNo);
					}else{

					}
					break;
				case PORT_B:
					if(Value == PIN_HIGH)
					{
						SET_BIT(PORTB_register , PinNo);
					}else if(Value == PIN_LOW){
						CLR_BIT(PORTB_register , PinNo);
					}else{

					}
					break;
				case PORT_C:
					if(Value == PIN_HIGH)
					{
						SET_BIT(PORTC_register , PinNo);
					}else if(Value == PIN_LOW){
						CLR_BIT(PORTC_register , PinNo);
					}else{

					}
					break;
				case PORT_D:
					if(Value == PIN_HIGH)
					{
						SET_BIT(PORTD_register , PinNo);
					}else if(Value == PIN_LOW){
						CLR_BIT(PORTD_register , PinNo);
					}else{

					}
					break;

				default:
					break;
			}
	}else{

	}

}
/*******************************************************************************
 * @brief Toggle the value of a specific Pin
 *
 * @parameter PortNo 		Port @(PORT_A , PORT_B , PORT_C ,PORT_D)
 * @parameter PinNo 		Pin Port @(PIN_0 - PIN_7)
 ********************************************************************************/
void DIO_TogPinValue(uint8 PortNo, uint8 PinNo)
{
	switch(PortNo)
	{
		case PORT_A:
			TOG_BIT(PORTA_register , PinNo);
			break;
		case PORT_B:
			TOG_BIT(PORTB_register , PinNo);
			break;
		case PORT_C:
			TOG_BIT(PORTC_register , PinNo);
			break;
		case PORT_D:
			TOG_BIT(PORTD_register , PinNo);
			break;
		default:
			break;
	}


}

/*******************************************************************************
 * @brief Set the value of a specific Pin
 *
 * @parameter PortNo 		Port @(PORT_A , PORT_B , PORT_C ,PORT_D)
 * @parameter PinNo 		Pin Port @(PIN_0 - PIN_7)
 * @return 					local_return (1 , 0)
 ********************************************************************************/
uint8 DIO_GetPinValue(uint8 PortNo, uint8 PinNo)
{
	uint8 local_return;
	if( (PinNo >= PIN_0) && (PinNo <= PIN_7) && (PortNo >= PORT_A) && (PortNo <= PORT_D) ) // Validation
	{
		switch(PortNo)
		{
			case PORT_A:
				local_return = GET_BIT(PINA_register , PinNo);
				break;
			case PORT_B:
				local_return = GET_BIT(PINB_register , PinNo);
				break;
			case PORT_C:
				local_return = GET_BIT(PINC_register , PinNo);
				break;
			case PORT_D:
				local_return = GET_BIT(PIND_register , PinNo);
				break;
			default:
				break;
		}
	}else{

	}
	return local_return;
}


