/*
 * hal_stepper.c
 *
 *  Created on: Feb 13, 2024
 *      Author: AhmedSamy
 */

#include "hal_stepper.h"


void Stepper_Init(stepper_t * _stepper){
	 DIO_SetPinDirection(_stepper->Port , _stepper->Blue_Pin ,PIN_OUTPUT);
	 DIO_SetPinDirection(_stepper->Port , _stepper->Pink_Pin ,PIN_OUTPUT);
	 DIO_SetPinDirection(_stepper->Port , _stepper->Yellow_Pin ,PIN_OUTPUT);
	 DIO_SetPinDirection(_stepper->Port , _stepper->Orange_Pin ,PIN_OUTPUT);
}

/* Stepper_SetAngle: Get an accurate angle for the stepper.
 * max speed of Stepper per step within 2ms
 * 1 degree = 5.68 step
 */
void Stepper_SetAngle(stepper_t * _stepper ,uint8 angle){
	uint16 L_i = 0;
	uint8 BitMask = 0x01;
	for(L_i = 0 ; L_i < (6 * angle); L_i++){
		/*0b0000 1111 & (BitMask << L_i % 4);*/
		DIO_SetPortValue(_stepper->Port , ( 0x0F & (~(BitMask << L_i % 4 )) ) );
		_delay_ms(2);

	}
	Stepper_Stop(_stepper);
	_delay_ms(1000);
}
void Stepper_RotateCCW(stepper_t * _stepper){
	uint16 L_i = 0;
	for(L_i = 0 ; L_i < 512 ; L_i++){
		DIO_SetPinValue(_stepper->Port , _stepper->Blue_Pin ,PIN_LOW);
		DIO_SetPinValue(_stepper->Port , _stepper->Pink_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Yellow_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Orange_Pin ,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(_stepper->Port , _stepper->Blue_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Pink_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Yellow_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Orange_Pin ,PIN_LOW);
		_delay_ms(2);
		DIO_SetPinValue(_stepper->Port , _stepper->Blue_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Pink_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Yellow_Pin ,PIN_LOW);
		DIO_SetPinValue(_stepper->Port , _stepper->Orange_Pin ,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(_stepper->Port , _stepper->Blue_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Pink_Pin ,PIN_LOW);
		DIO_SetPinValue(_stepper->Port , _stepper->Yellow_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Orange_Pin ,PIN_HIGH);
		_delay_ms(2);
	}
	Stepper_Stop(_stepper);
	_delay_ms(1000);
}
void Stepper_RotateCW(stepper_t * _stepper){
	uint16 L_i = 0;
	for(L_i = 0 ; L_i < 512 ; L_i++){
		DIO_SetPinValue(_stepper->Port , _stepper->Blue_Pin ,PIN_LOW);
		DIO_SetPinValue(_stepper->Port , _stepper->Pink_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Yellow_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Orange_Pin ,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(_stepper->Port , _stepper->Blue_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Pink_Pin ,PIN_LOW);
		DIO_SetPinValue(_stepper->Port , _stepper->Yellow_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Orange_Pin ,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(_stepper->Port , _stepper->Blue_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Pink_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Yellow_Pin ,PIN_LOW);
		DIO_SetPinValue(_stepper->Port , _stepper->Orange_Pin ,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(_stepper->Port , _stepper->Blue_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Pink_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Yellow_Pin ,PIN_HIGH);
		DIO_SetPinValue(_stepper->Port , _stepper->Orange_Pin ,PIN_LOW);
		_delay_ms(2);

	}
	Stepper_Stop(_stepper);
	_delay_ms(1000);

}
void Stepper_Stop(stepper_t * _stepper){

	DIO_SetPinValue(_stepper->Port , _stepper->Blue_Pin ,PIN_LOW);
	DIO_SetPinValue(_stepper->Port , _stepper->Pink_Pin ,PIN_LOW);
	DIO_SetPinValue(_stepper->Port , _stepper->Yellow_Pin ,PIN_LOW);
	DIO_SetPinValue(_stepper->Port , _stepper->Orange_Pin ,PIN_LOW);
	_delay_ms(2);
}
