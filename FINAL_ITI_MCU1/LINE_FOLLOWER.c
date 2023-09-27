#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include<avr/delay.h>
#include <avr/io.h>
#include "avr/interrupt.h"
#include "EXTERNAL_INT.h";

#include "ir.h"
#include "MOTOR.h"
#include "LINE_FOLLOWER.h"

void FollowTheLine(void){
	PORTD|=(1<<5);
	_delay_us(150);
	PORTD &=~(1<<5) ;

	PORTC|=1;

	u8 RightSensor=getIR(1) ;
	u8 LeftSensor=getIR(2);
	if(RightSensor==1 && LeftSensor==0){
		Rotate_right() ;
		_delay_ms(750) ;
	}else if (RightSensor==0 && LeftSensor==1){
		Rotate_left();
		_delay_ms(750) ;
	}else{
		GoStraight() ;

	}
}
