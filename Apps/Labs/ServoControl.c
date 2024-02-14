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
	LCD_4Bit_Init();

	TIMER0_PWM_Init();

	ADC_Init(0);

	TIMER1_init();

	TIMER1_Set_OCR_Value(1200);

	LCD_4Bit_Write_String("Servo Control");

	_delay_ms(1000);


	while(1){


	LCD_4Bit_Write_String_Position("                ",2,1);
	Reading = ADC_GetChannelReading(0);
	Analog = (Reading*255UL) / 1024;

	Angle = ((140/17) * Analog )+ 450 ;
	//Angle = ADC_Mapping(0,255,450 , 2500 ,Analog );

	TIMER1_Set_OCR_Value(Angle);


	LCD_4Bit_Write_String_Position("Angle = ",2,1);
	Analog = ((Analog*180)/255);
	LCD_4Bit_Send_Number(Analog);

	LCD_4Bit_Write_String("'");

	_delay_ms(150);

	}


}

