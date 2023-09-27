/*
 * MOTOR.c
 *
 *  Created on: Sep 4, 2023
 *      Author: seif alrahman
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include "DIO_Interface.h"
#include "MOTOR.h"

void MOTOR_init(void){
	DDRD|=(1<<6)|(1<<7);
	DDRC|=(1<<4)|(1<<3);
}
void Rotate_right(void){
	PORTD|=(1<<6);
	PORTD&=~(1<<7) ;

	PORTC|=(1<<4);
	PORTC&=~(1<<3) ;
}
void Rotate_left(void){
	PORTD|=(1<<7);
	PORTD&=~(1<<6) ;

	PORTC&=~(1<<4);
	PORTC|=(1<<3) ;
}
void GoStraight(void){
	PORTD|=(1<<7);
	PORTD&=~(1<<6);
	PORTC|=(1<<4);
	PORTC&=~(1<<3) ;
}
