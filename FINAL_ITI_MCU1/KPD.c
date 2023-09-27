#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/io.h>
#include <avr/delay.h>

#include "DIO_Interface.h"
#include "KPD.h"

u8 KPD_AU8KEYS[4][4]=KPD_KEYS;
u8 KPD_AU8ROWS[4]={KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN,KPD_R4_PIN};
u8 KPD_AU8COLS[4]={KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN,KPD_C4_PIN};



void KPD_VidInit(void){


	 DIO_VidSetPortDirection(KPD_PORT ,0x0f);
	 DIO_VidSetPortValue(KPD_PORT,0xff);
	 //cols are pull up
	 //rows are 1
}
u8 KPD_U8PressedKey(void){
	u8 Local_U8CounterR ;
	u8 Local_U8CounterC ;
	u8 Local_U8Pressed,Local_U8ReturnedKey=KPD_CHECK,Local_U8Flag=0;
	for(Local_U8CounterR=0;Local_U8CounterR<4 ;Local_U8CounterR++){
		DIO_VidSetPinValue(KPD_PORT,KPD_AU8ROWS[Local_U8CounterR],DIO_LOW);

		for(Local_U8CounterC=0;Local_U8CounterC<4 ;Local_U8CounterC++){
			Local_U8Pressed=DIO_U8GetPinValue(KPD_PORT,KPD_AU8COLS[Local_U8CounterC]);


			if(Local_U8Pressed==DIO_LOW){
				_delay_ms(20);
				while(Local_U8Pressed==DIO_LOW){
					Local_U8Pressed=DIO_U8GetPinValue(KPD_PORT,KPD_AU8COLS[Local_U8CounterC]);
				}
				Local_U8ReturnedKey= KPD_AU8KEYS[Local_U8CounterR][Local_U8CounterC];
				Local_U8Flag=1;
				break ;
			}
		}
		DIO_VidSetPinValue(KPD_PORT,KPD_AU8ROWS[Local_U8CounterR],DIO_HIGH);
		if(Local_U8Flag){
			break ;
		}
	}
	return Local_U8ReturnedKey ;

}
