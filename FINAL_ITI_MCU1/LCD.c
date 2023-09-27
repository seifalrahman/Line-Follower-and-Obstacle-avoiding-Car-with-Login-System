#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "LCD.h"
#include <avr/delay.h>



void LCD_VidInit(void)
{
	DIO_VidSetPortDirection(LCD_DATA_PORT,0xff);

	DIO_VidSetPinDirection(LCD_CMD_PORT,RS,DIO_OUTPUT);
	DIO_VidSetPinDirection(LCD_CMD_PORT,RW,DIO_OUTPUT);
	DIO_VidSetPinDirection(LCD_CMD_PORT,EN,DIO_OUTPUT);

	_delay_ms(35);
	LCD_VidSendCMD(FUN_SET);
	_delay_ms(1);
	LCD_VidSendCMD(C_ON_OFF);
	_delay_ms(1);
	LCD_VidSendCMD(LCD_CLR);
	_delay_ms(2);


}


void LCD_VidSendCMD(u8 Copy_U8CMD)
{
	DIO_VidSetPinValue(LCD_CMD_PORT,RS,DIO_LOW);

	DIO_VidSetPinValue(LCD_CMD_PORT,RW,DIO_LOW);

	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_U8CMD);

	DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_HIGH);

	_delay_ms(1);

	DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_LOW);
}

void LCD_VidSendChar(u8 Copy_U8Char)
{
	DIO_VidSetPinValue(LCD_CMD_PORT,RS,DIO_HIGH);

	DIO_VidSetPinValue(LCD_CMD_PORT,RW,DIO_LOW);

	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_U8Char);

	DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_HIGH);

	_delay_ms(1);

	DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_LOW);
}




void LCD_VidSendString(u8 *Copy_U8ptr)
{
	for(u8 Local_U8Counter=0;Copy_U8ptr[Local_U8Counter]!='\0';Local_U8Counter++)
	{
		LCD_VidSendChar(Copy_U8ptr[Local_U8Counter]);
	}
}


void LCD_VidLocation(u8 Copy_U8Line,u8 Copy_U8CharNum)
{
	switch(Copy_U8Line)
	{
	case LINE_1:LCD_VidSendCMD(0x80+Copy_U8CharNum);break;
	case LINE_2:LCD_VidSendCMD(0xc0+Copy_U8CharNum);break;

	}
}


void LCD_VidSendSpecialChar(u8 Copy_U8CharNum,u8 *Copy_U8Ptr)
{
	u8 Local_U8Counter;
	LCD_VidSendCMD(0x40+(Copy_U8CharNum*8));

	for(Local_U8Counter=0;Local_U8Counter<8;Local_U8Counter++)
		LCD_VidSendChar(Copy_U8Ptr[Local_U8Counter]);
}






void LCD_VidSendSingleInt(u8 Copy_U8SingleInt){
    //u8 Local_Copy_Tochar=2Copy_U8SingleInt;

    DIO_VidSetPinValue(LCD_CMD_PORT,RS,DIO_HIGH);

    DIO_VidSetPinValue(LCD_CMD_PORT,RW,DIO_LOW);

    DIO_VidSetPortValue(LCD_DATA_PORT,Copy_U8SingleInt+48);

    DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_HIGH);

    _delay_ms(1);

    DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_LOW);
}

void LCD_VidSendMultiInt(u32 Copy_U8MultiInt){
    u32 Local_Div = 1;
    u32 Local_Temp = Copy_U8MultiInt;
    u8 Copy_U8SingleInt;
    while(Local_Temp >= 10){
        Local_Div *= 10;
        Local_Temp /= 10;
    }

    while(Local_Div >= 1){
        Copy_U8SingleInt = Copy_U8MultiInt / Local_Div;
        LCD_VidSendSingleInt(Copy_U8SingleInt);
        Copy_U8MultiInt %= Local_Div;
        Local_Div /= 10;
    }
}
void LCD_Clear (void){
    LCD_VidSendCMD(0x01);
    LCD_VidSendChar(' ');
    LCD_VidLocation(LINE_1,0);
}





