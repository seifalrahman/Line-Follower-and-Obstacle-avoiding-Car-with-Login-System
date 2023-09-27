/*
 * main.c
 *
 *  Created on: Sep 21, 2023
 *      Author: seif alrahman
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include<avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "Timer1.h"
#include "LCD.h"
#include "UART.h"
#include "ULTRASONIC.h"

void INT0_init() {

	DDRD &= ~(1 << 0);


	EICRA |= (1 << ISC00);
	EIMSK |= (1 << INT0);


	sei();
}

void main (void){
	Timer1_Init();
	UART_Init();
	LCD_VidInit();
	INT0_init();
	DDRD|=(1<<7);

	while(1){
		PORTD|=(1<<7);
		_delay_us(15);
		PORTD &=~(1<<7) ;
	}
}

ISR(INT0_vect) {
	ultrasonic_in_action();
}
