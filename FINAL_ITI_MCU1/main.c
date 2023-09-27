#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include"DIO_Interface.h"
#include "EXTERNAL_INT.h"
#include "Timer_1.h"
#include"ULTRASONIC.h"
#include"MOTOR.h"
#include"ir.h"
#include "LINE_FOLLOWER.h"
#include "KPD.h"
#include "LCD.h"
#include "UART.h"

void INT0_Init(void)
{
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}
void main (void){
	DDRC|=(1<<0);
	PORTC&=~1;
	u8 numtimes=0;
	EXTI_VidGIE () ;
	EXTI_VidInit();
	EXTI_VidSetCallBack(0,&ultrasonic_in_action) ;
	INT0_Init();
		LCD_VidInit();
		Timer1_VidTimer1Normal () ;
		ULTRASONIC_init() ;
		UART_VidInit() ;


	DDRD &= ~(1 << PD0);
	DDRD |= (1 << PD1);

	IRArrayOf5_Init();
	MOTOR_init();
	KPD_VidInit() ;
	GoStraight();
	//INT0_Init();


	u8 pw []={'1','2','3','4'};
	u8 num=KPD_CHECK ;
	u8 cnt =3;

	u8 numwa=1;
	LCD_VidSendString("  LOGIN_SYSTEM");
	_delay_ms(500);
	LCD_VidSendCMD(0x01) ;
	while (1){
		int i =0 ;
		if(numwa>0){
			numwa=0;
			num=KPD_CHECK ;
			for(i=0;i<4;i++){
				while((num==KPD_CHECK)){
					num=KPD_U8PressedKey();
				}


				if(num!=(pw[i])){

					numwa++;
					LCD_VidSendChar('*');
					//break ;
				}else{

					//LCD_VidLocation(LINE_1,)
					LCD_VidSendChar('*');
				}
				num=KPD_CHECK ;
			}
		}
		if(numwa>0){
			cnt--;
			LCD_VidSendString("INCORRECT");
			_delay_ms(2000) ;
			LCD_VidSendCMD(0x01) ;
			if(cnt==0){
				cnt=3 ;
				LCD_VidSendString(" wait 10 sec");
				_delay_ms(1000);
				LCD_VidSendCMD(0x01) ;
				for(i=1;i<11;i++){
					if(i<10){
						LCD_VidSendChar((char)(i+'0'));
					}else {LCD_VidSendChar('1');LCD_VidSendChar('0');}
					_delay_ms(500);
					LCD_VidSendCMD(0x01) ;
					_delay_ms(500);
				}
			}




		}

		if(numwa==0){
			if(numtimes==0){
				numtimes++;
				_delay_ms(200);
				LCD_Clear();
				LCD_VidSendString("CORRECT");
				_delay_ms(500);
				LCD_Clear(); }

			FollowTheLine() ;
		}
	}


}
