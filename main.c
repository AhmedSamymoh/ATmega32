/*
 * main.c
 *
 *  Created on: Sep 1, 2023
 *      Author: AhmedSamy
 */

#include "MCAL/DIO/DIO_interface.h"
#include "HAL/SEVEN_SEGMENTS/hal_segmenets_interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include <avr/io.h>

uint8 data = 0;
uint8 portstatus = 0;

int main()
{
	//LCD_Init();
	GLOBAL_Interrupt_ENABLE();
	EXT_Interrupt_Init();
	EXT_Interrupt_ENABLE(EXTI0);
	EXT_Interrupt_ENABLE(EXTI1);


	DIO_SetPinDirection(PORT_D , PIN_0 , PIN_OUTPUT);
	DIO_SetPinDirection(PORT_D , PIN_1 , PIN_OUTPUT);

	DIO_SetPinDirection(PORT_D , PIN_2 , PIN_INPUT);
	DIO_SetPinValue(PORT_D , PIN_2 , PIN_HIGH);
	DIO_SetPinDirection(PORT_D , PIN_3 , PIN_INPUT);
	DIO_SetPinValue(PORT_D , PIN_3 , PIN_HIGH);
	//LCD_Write_String_Position("Interrupt Lab",1,1);

	while(1)
	{

	}
	return 0;
}
void __vector_1 (void) __attribute__ ((signal,used, externally_visible)) ;
    void __vector_1 (void){
	DIO_TogPinValue(PORT_D, PIN_0);
	//LCD_Write_String_Position("INT0",2,1);
}

void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ;
	void __vector_2 (void){
	TOG_BIT(PORTD, PIN_1);
	//LCD_Write_String_Position("INT1",2,1);

}

