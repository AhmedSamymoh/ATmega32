

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

	LCD_Write_String_Position("Chase Game !",1,2);

	while(1){
		LCD_Write_String_Position("Chase Game !",1,3);

		Reading = ADC_GetChannelReading(0);
		Analog = (Reading*500UL) / 1024;
		Analog = (Analog*16)/490;
		LCD_Write_String_Position("&",2,Analog);
		_delay_ms(1000);
		LCD_Send_Command(_LCD_CLEAR);



	}

}