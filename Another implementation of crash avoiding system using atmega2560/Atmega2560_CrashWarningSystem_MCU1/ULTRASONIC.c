
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#include "Timer1.h"
#include "ULTRASONIC.h"
#include "LCD.h"
#include "UART.h"

u16 pulse=0 ;
u8  i =0 ;
f32 distance = 0 ;

void ultrasonic_in_action(void){

	if(i==1){
		pulse=TCNT1;
		i=0;
		distance=(pulse/2)*(float)(1.0976);//cm
		if(distance< MINIMUM_DISTANCE ){
			LCD_VidSendString("WARNING");
			_delay_ms(250);
			LCD_Clear();
			UART_Transmit(1);
			UART_Transmit(distance);
			_delay_ms(250);


		}
		LCD_Clear() ;
		LCD_VidLocation(LINE_1,2);
		LCD_VidSendString("Distance is ");
		LCD_VidLocation(LINE_2,7);
		LCD_VidSendMultiInt(distance) ;
		_delay_ms(250) ;


	}else if(i==0){
		TCNT1=0 ;
		i=1;
		LCD_Clear() ;
	}
}
