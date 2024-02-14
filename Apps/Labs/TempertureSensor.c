
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "HAL/LCD/LCD_Interface.h"


int main (void){
	LCD_Init();
	GLOBAL_Interrupt_ENABLE();
	ADC_Init(0);


	uint32 Reading = 0;

	uint16 Analog = 0;

	LCD_Write_String("Temperture:");

	while(1){
		Reading = ADC_GetChannelReading(0);
		Analog = (Reading*5000UL) / 1024;
		LCD_Set_Cursor(1 , 13);
		LCD_Send_Number(Analog/10);


	}

}