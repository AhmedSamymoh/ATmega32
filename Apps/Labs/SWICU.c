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

uint16 Analog = 0;
uint16 pwm = 0;
uint16 DutyCycle = 0;
uint16 Freq = 0;

static uint16 PeriodTime = 0;
static uint16 OnTime = 0;

void issr() {
    static uint16 counter = 0;
    counter++;

    if (counter == 1) {

        TIMER1_Set_TCNT_Value(0);

    } else if (counter == 2) {

        PeriodTime = TIMER1_Read_TCNT_Value();
        EXTI_Interrupt_Set_Mode(EXTI0 , FALLING_EDGE_MODE);

    } else if (counter == 3) {
    	counter = 0;
        OnTime = TIMER1_Read_TCNT_Value();
        OnTime = OnTime - PeriodTime;
        EXTI_Interrupt_Set_Mode(EXTI0 , RISING_EDGE_MODE);
        Freq = 1.0/(PeriodTime * 0.000001);
        DutyCycle = (OnTime * 100)/ PeriodTime;

    }else {

    }


}

int main(void)
{
	LCD_4Bit_Init();
	DIO_SetPinDirection(PORT_B , PIN_3 , PIN_OUTPUT);
	DIO_SetPinDirection(PORT_D , PIN_2 , PIN_INPUT);
	ADC_Init(0);
	GLOBAL_Interrupt_ENABLE();
	EXTI_Interrupt_Init();
	EXTI_Interrupt_ENABLE(EXTI0);
	EXTI_Interrupt_Set_Callback(issr , EXTI0);

	TIMER0_PWM_Init(125);

	TIMER1_init();




	while(1){
		if((OnTime == 0)&& (PeriodTime == 0));
		else{

			LCD_4Bit_Set_Cursor(1 , 1 );
			LCD_4Bit_Send_Number(DutyCycle);
			LCD_4Bit_Set_Cursor(2, 1 );
			LCD_4Bit_Send_Number(Freq);
			_delay_ms(1000);
		}



	}
}

