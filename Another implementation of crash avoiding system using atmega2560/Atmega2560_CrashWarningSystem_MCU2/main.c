/*
 * main.c
 *
 *  Created on: Sep 21, 2023
 *      Author: seif alrahman
 */


#include <avr/io.h>
#include<avr/interrupt.h>
#include <avr/delay.h>

#include "UART.h"
int main (void){
	DDRD &= ~(1 << PD0);
	DDRD |= (1 << PD1);

	DDRC|=(1<<0);
	DDRC|=(1<<1);
	//PORTD |= (1 << PD0);
	PORTC&=~3 ;
	UART_Init();
	Timer1_Init_CTC();
	while(1){
		TCCR1A = 0;
		TCCR1B = 0;
		unsigned char  warning=UART_Receive();
		unsigned char distance =UART_Receive();
		if(warning==1){
			Timer1_Init_CTC();
			PORTC|=(1<<0) ;
			_delay_ms(500) ;

			PORTC&=~(1<<0) ;
			_delay_ms(500) ;

		}
	}

}
ISR(TIMER1_COMPA_vect)
{
	PORTC^=(1<<1);
}

