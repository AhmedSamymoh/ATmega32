/*
 * main.c
 *
 *  Created on: Sep 30, 2023
 *      Author: AhmedSamy
 */

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KEYPAD/hal_keyad_interface.h"
#include "MCAL/TIMER0/Timer0_interface.h"
#include "MCAL/PWM/PWM_interface.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "MCAL/WATCHDOG/WATCHDOG_register.h"


uint32 Reading = 0;

uint16 Analog = 0;
uint16 Angle = 0;

float V =0.0;
void main(void)
{

	/*OC1A Pin -> PD5*/
	DIO_SetPinDirection(PORT_D , PIN_5 , PIN_OUTPUT);

	LCD_4Bit_Init();

	ADC_Init(0);

	TIMER1_init();

	TIMER1_Set_OCR_Value(1200);

	LCD_4Bit_Write_String("Servo Test");

	_delay_ms(1000);


	while(1){


		LCD_4Bit_Write_String_Position("                ",2,1);
		Reading = ADC_GetChannelReading(0);
		Analog = (Reading*255UL) / 1024;

		Angle = ((140/17) * Analog )+ 450 ;

		TIMER1_Set_OCR_Value(Angle);

		LCD_4Bit_Write_String_Position("Angle = ",2,1);
		Analog = ((Analog*180)/255);
		LCD_4Bit_Send_Number(Analog);

		LCD_4Bit_Write_String("'");

        _delay_ms(150);

	}



}











//
//#include "MCAL/DIO/DIO_interface.h"
//#include "MCAL/EXTI/EXTI_interface.h"
//#include "MCAL/ADC/ADC_interface.h"
//#include "HAL/LCD/LCD_Interface.h"
//#include "HAL/KEYPAD/hal_keyad_interface.h"
//#include "MCAL/TIMER0/Timer0_interface.h"
//#include "MCAL/PWM/PWM_interface.h"
//#include "MCAL/TIMER1/TIMER1_interface.h"
//#include "MCAL/WATCHDOG/WATCHDOG_register.h"
//
//
//#define CharToNumber(c) ((c) - '0')
//
//uint8 i = 0 ;
//uint16 periodticks = 0 ;
//uint16 onticks = 0 ;
//
//
//uint8 pressedKey = KEY_NOT_PRESSED;
//
//uint8 Buzzer = PIN_0;
//
//uint8 firstOperator[6] = {0} ;
//
//uint8 Operator = 0 ;
//
//uint8 SecondOperator[6] = {0} ;
//uint8 * Output;
//uint8 Calc;
//uint8 OperatorFlag = 0;
//
//
//
//void NumberToString(uint8 number, uint8 *arr);
//uint8 String2Number(uint8 *arr);
//void Restart(void);
//
//int main (void){
//
//	DIO_SetPinDirection(PORT_B , Buzzer , PIN_OUTPUT);
//
//	LCD_Init();
//	KEYPAD_init();
//
//
//
//	while(1){
//
//		pressedKey = KEYPAD_GetPressedKey();
//
//		if(pressedKey != KEY_NOT_PRESSED)
//		{
//
//			DIO_SetPinValue(PORT_B , Buzzer , PIN_HIGH);
//			_delay_ms(200);
//			DIO_SetPinValue(PORT_B , Buzzer , PIN_LOW);
//			_delay_ms(200);
//
//			uint8 x = 0;
//
//			if(pressedKey != '*' && pressedKey != '/' &&
//			   pressedKey != '+' && pressedKey != '-' && pressedKey != '#' && pressedKey != '='  ){
//
//				firstOperator[x] = CharToNumber(pressedKey);
//				LCD_Send_Data(pressedKey);
//				_delay_ms(200);
//				x++;
//
//				if (x > 5){
//					LCD_Send_Command(_LCD_CLEAR);
//					LCD_Write_String_Position("Math Error" , 2 , 1);
//					Restart();
//				}
//
//
//			}
//
//			if (!(pressedKey != '*' && pressedKey != '/' &&
//					   pressedKey != '+' && pressedKey != '-')){
//				LCD_Write_String(" ");
//				Operator = pressedKey;
//				LCD_Send_Data(pressedKey);
//				LCD_Write_String(" ");
//				OperatorFlag = 1;
//			}
//
//			if (pressedKey == '='){
//				LCD_Send_Command(_LCD_CLEAR);
//				if (Operator == '+'){
//					Calc = String2Number(firstOperator) + String2Number(SecondOperator);
//				}else if(Operator == '-'){
//					Calc = String2Number(firstOperator) - String2Number(SecondOperator);
//				}else if(Operator == '/'){
//					if (String2Number(SecondOperator)){
//						LCD_Send_Command(_LCD_CLEAR);
//						LCD_Write_String_Position("Math Error" , 2 , 1);
//						Restart();
//					}
//					Calc = String2Number(firstOperator) / String2Number(SecondOperator);
//				}else if (Operator == '-'){
//					Calc = String2Number(firstOperator) * String2Number(SecondOperator);
//				}else{}
//
//				NumberToString(Calc, &Output);
//				LCD_Write_String_Position('=' , 2 , 1);
//				LCD_Write_String_Position(Output , 2 , 3);
//
//
//			}
//
//
//			x = 0;
//			if((OperatorFlag==1)&& pressedKey != '*' && pressedKey != '/' &&
//			   pressedKey != '+' && pressedKey != '-' && pressedKey != '#' && pressedKey != '='  ){
//
//				SecondOperator[x] = CharToNumber(pressedKey);
//				LCD_Send_Data(pressedKey);
//				x++;
//				OperatorFlag = 0;
//				if (x > 5){
//					LCD_Send_Command(_LCD_CLEAR);
//					LCD_Write_String_Position("Math Error" , 2 , 1);
//					Restart();
//				}
//
//			}
//
//
//			if (pressedKey == '#'){
//				Restart();
//			}
//
//
//		}else
//		{
//			/* Do Nothing */
//		}
//
//
//
//	}
//}
//
//void Restart(void){
//	LCD_Send_Command(_LCD_CLEAR);
//	firstOperator[6] = 0 ;
//	Operator = 0 ;
//	SecondOperator[6] = 0 ;
//	Output = 0;
//}
//
//void NumberToString(uint8 number, uint8 *arr) {
//    uint8 i = 0;
//
//    if (number == 0) {
//        arr[i++] = '0';
//    }
//
//    while (number != 0) {
//        uint8 digit = number % 10;
//        arr[i++] = digit + '0';
//        number /= 10;
//    }
//
//    arr[i] = '\0';
//
//    // Reverse the string
//    uint8 len = i;
//    for (i = 0; i < len / 2; i++) {
//        uint8 temp = arr[i];
//        arr[i] = arr[len - i - 1];
//        arr[len - i - 1] = temp;
//    }
//}
//
//uint8 String2Number(uint8 *arr) {
//    uint8 n = 6, Number = 0, temp = 0;
//    while (n) {
//        temp = arr[n - 1] - '0'; // Convert ASCII to numerical value
//        Number = Number * 10 + temp; // Multiply by 10 and add the digit
//        n--;
//    }
//    return Number;
//}


/*
 * Voltmeter

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
 *
 * */



/*
 * icu hw
 *
 *

	DIO_SetPinDirection(PORT_B , PIN_3 , PIN_OUTPUT);

	DIO_SetPinDirection(PORT_D , PIN_6 , PIN_INPUT);



	LCD_Init();
	LCD_Write_String_Position("HWICU LAB" ,1 , 1 );
    _delay_ms(1000);

	PWM_Init();
	PWM_SetMode(NON_INVERTED_MODE);
	PWM_SetOCRvalue(64);

	TIMER1_init();
	HWICU_Init();
	HWICU_SetCallBack(&HWICU);
	GLOBAL_Interrupt_ENABLE();



while(1){


	LCD_Write_String_Position("Per tick is:" ,1 , 1 );
	LCD_Send_Number(periodticks);

	LCD_Write_String_Position( "On tick is :" , 2 , 1 );
	LCD_Send_Number(onticks);
}

}
void HWICU()
{

	static uint8 counter = 0;
	static uint16 reading1 = 0;
	static uint16 reading2 = 0;
	static uint16 reading3 = 0;

	counter ++;
	if(1 == counter){
		reading1 = HWICU_ReadTicks();
	}else if(2 == counter ){

		reading2 = HWICU_ReadTicks();
		HWICU_EdgeSelect(FALLING_EDGE);
		periodticks = reading2 - reading1;
	}else if(3 == counter ){

		reading3 = HWICU_ReadTicks();
		HWICU_InterruptDisable();
		onticks = reading3 - reading2;

	}else{

	}

}
 *
 *
 *
 *
 *
 *	SERVO
 *
 		TIMER1_Set_OCR_Value(450);
		for(uint16 i = 450 ; i <= 2500 ; i++){
			TIMER1_Set_OCR_Value(i);
			_delay_ms(1);
		}

		for(uint16 i = 2500 ; i >= 450 ; i--){
			TIMER1_Set_OCR_Value(i);
			_delay_ms(1);
		}




		ICU

		uint8 i = 0 ;
 uint16 periodticks = 0 ;
 uint16 onticks = 0 ;

void SWICU();

int main (void){

	DIO_SetPinDirection(PORT_B , PIN_3 , PIN_OUTPUT);
	DIO_SetPinDirection(PORT_D , PIN_2 , PIN_INPUT);

	GLOBAL_Interrupt_ENABLE();

	EXTI_Interrupt_Init();
	EXTI_Interrupt_Set_Callback(SWICU  , EXTI0);
	EXTI_Interrupt_Set_Mode(EXTI0 ,FALLING_EDGE_MODE  );

	LCD_Init();


	PWM_Init();
	PWM_SetMode(NON_INVERTED_MODE);
	PWM_SetOCRvalue(64);

	TIMER1_init();


	while(1){

		LCD_Write_String_Position("Per tick is:" ,1 , 1 );
		LCD_Send_Number(periodticks);
		LCD_Write_String_Position( "On tick is :" , 2 , 1 );
		LCD_Send_Number(onticks);
	}

}

void SWICU(){
	static uint8 counter = 0;
	counter ++;
	if(1 == counter){
		TIMER1_Set_TCNT_Value(0);
	}else if(2 == counter ){

		periodticks = TIMER1_Read_TCNT_Value();
		EXTI_Interrupt_Set_Mode(EXTI0 , RISING_EDGE_MODE);
	}else if(3 == counter ){

		onticks = TIMER1_Read_TCNT_Value();
		onticks -= periodticks;
		//EXTI_Interrupt_DISABLE(EXTI0);
		SET_BIT(GICR , INT0);
	}else{

	}
}





 * GLOBAL_Interrupt_ENABLE();
	DIO_SetPinDirection(PORT_B , PIN_3 , PIN_OUTPUT);


	PWM_Init();
	PWM_SetMode(NON_INVERTED_MODE);

	ADC_Init(0);

	uint32 Reading = 0;

	uint16 Analog = 0;


	while(1){
		Reading = ADC_GetChannelReading(0);
		Analog = (Reading*5000UL) / 1024;

		i = (Analog * 256)/5000UL;
		TIMER0_SetOCRvalue(i);
		//_delay_ms(20);


	}
 * PWM SW
 *
 *
void LED();

int main (void){
	LCD_Init();
	GLOBAL_Interrupt_ENABLE();
	DIO_SetPinDirection(PORTA_register , PIN_0 , PIN_OUTPUT);
	DIO_SetPinDirection(PORTA_register , PIN_1 , PIN_OUTPUT);
	DIO_SetPinDirection(PORTA_register , PIN_2 , PIN_OUTPUT);

	TIMER0_SetOCRvalue(100);
	TIMER0_SetCallBackOVF(&LED);


	while(1){




	}

}

void LED(){
	static uint16 counter = 0;
	counter++;
	if(3 == counter){

		DIO_SetPinValue(PORTA_register , PIN_0 , PIN_LOW);


	}else if(counter == 5) {
		DIO_SetPinValue(PORTA_register , PIN_1 , PIN_LOW);
	}else if(counter == 7) {
		DIO_SetPinValue(PORTA_register , PIN_2 , PIN_LOW);
	}else if(counter == 10) {
		DIO_SetPinValue(PORTA_register , PIN_0 , PIN_HIGH);
		DIO_SetPinValue(PORTA_register , PIN_1 , PIN_HIGH);
		DIO_SetPinValue(PORTA_register , PIN_2 , PIN_HIGH);
		counter = 0;
	}
}

 *
 *
 *
 * */
/*Temperture sensor
 *
 *

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
game ::




int main (void){
	LCD_Init();
	GLOBAL_Interrupt_ENABLE();
	ADC_Init(0);


	uint32 Reading = 0;

	uint16 Analog = 0;

	//LCD_Write_String_Position("Chase Game !",1,2);

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

 */

/*
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/TIMER0/Timer0_interface.h"

void led();
int main (void){

	GLOBAL_Interrupt_ENABLE();

	DIO_SetPinDirection(PORTA_register , 0 , PIN_OUTPUT);

	TIMER0_SetOCRvalue(250);
	TIMER0_voidInit();
	(void)TIMER0_SetCallBack(&led);

	while(1){

	}

}

void led()
{
	static uint16 counter = 0 ;
	static uint8 Led_State = 0;
	counter ++;
	if(4000 == counter){
		TOG_BIT(PORTA_register , 0);
		//DIO_SetPinValue(PORTA_register , 0 ,Led_State);
		counter = 0;
	}
}



*/
