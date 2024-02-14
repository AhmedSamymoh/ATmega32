/*
 * main.c
 *
 *  Created on: Sep 30, 2023
 *      Author: AhmedSamy
 */

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/PWM/PWM_interface.h"
#include "MCAL/TIMER0/Timer0_interface.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "MCAL/WATCHDOG/WATCHDOG_register.h"

#include "HAL/LCD/LCD_Interface.h"
#include "HAL/IR_SENSOR/hal_ir.h"
#include "HAL/KEYPAD/hal_keyad_interface.h"

int main(){
	DIO_SetPinDirection(PORT_B , PIN_3 , PIN_OUTPUT);
	ADC_Init(1);
	LCD_4Bit_Init();

	TIMER0_PWM_Init(1);

	uint32 Reading = 0;

	uint16 Analog = 0;

	float V =0.0;
	LCD_4Bit_Send_Command(_LCD_CLEAR);
	LCD_4Bit_Write_String_Position("Voltage ",1,1);
	while(1){


	LCD_4Bit_Write_String_Position("         ",2,1);
	Reading = ADC_GetChannelReading(1);
	Analog = (Reading*5000UL) / 1024;

	V = (float)Analog / 1000.0;
	TIMER0_SetOCRvalue(V*100/2);

	LCD_4Bit_Set_Cursor(2,1);
	LCD_4Bit_Send_Number((int8_t)V);  // Display integer part
	LCD_4Bit_Send_Data('.');

	V = (V - (int8_t)V) * 100.0;
	LCD_4Bit_Send_Number((int8_t)V);

	LCD_4Bit_Send_Data(' ');
	LCD_4Bit_Send_Data('V');


	_delay_ms(150);

	}

}

