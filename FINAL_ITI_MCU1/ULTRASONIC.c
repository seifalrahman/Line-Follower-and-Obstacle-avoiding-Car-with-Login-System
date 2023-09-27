
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "DIO_Interface.h"
#include "EXTERNAL_INT.h"
#include "Timer_1.h"
#include "ULTRASONIC.h"
#include "LCD.h"
#include "UART.h"
u16 pulse=0 ;
u8  i =0 ;
f32 distance = 0 ;
void ULTRASONIC_init(void){
	DDRD  |=  (1<<5) ;
	DDRD  &= ~(1<<2) ;
	PORTD|=(1<<5);
	PORTD &=~(1<<0)  ;


}
void ultrasonic_in_action(void){

	if(i==1){
		pulse=TCNT1;
		i=0;
		distance=(pulse/2)*(float)(0.5488);//cm
		if(distance< MINIMUM_DISTANCE ){
			LCD_VidSendString("STEERING..");
			_delay_ms(500);
			LCD_Clear();
			UART_VidSendData(1);
			UART_VidSendData(distance);
			Obstacle_avoiding() ;
			_delay_ms(500);


		}
		LCD_Clear() ;
		LCD_VidLocation(LINE_1,2);
		LCD_VidSendString("Distance is ");
		LCD_VidLocation(LINE_2,7);
		LCD_VidSendMultiInt(distance) ;
		_delay_ms(500) ;


	}else if(i==0){
		TCNT1=0 ;
		i=1;
		LCD_Clear() ;
	}
}


void Obstacle_avoiding(void){
	Rotate_right();
	_delay_ms(500);
	GoStraight();
	_delay_ms(500);

	Rotate_left();
	_delay_ms(500);
	GoStraight();
	_delay_ms(500);

	Rotate_left();
	_delay_ms(500);
	GoStraight();
	_delay_ms(500);

	Rotate_right();
	GoStraight();
}
