#include <avr/io.h>
#include<avr/interrupt.h>
#include <avr/delay.h>

#include "UART.h"
int main (void){
	DDRD &= ~(1 << PD0);
	DDRD |= (1 << PD1);

	DDRC|=(1<<0);
	DDRC|=(1<<1);
	sei();
	//PORTD |= (1 << PD0);
	PORTC&=~3 ;
	UART_VidInit() ;
	while(1){
		PORTC&=~(1<<1);
		unsigned short  warning=UART_VidReciveData();
		unsigned short distance =UART_VidReciveData();

		if(warning==1){
			Timer0_Init_CTC_Mode(distance);
			PORTC|=(1<<0) ;
			_delay_ms(500) ;
			PORTC&=~(1<<0) ;
			_delay_ms(500) ;
		}
	}

}

ISR(TIMER0_COMP_vect)
{	TCCR0 &=~(1<<CS02);
	TCCR0 &=~(1<<CS00);
	PORTC|=(1<<1);
	}
