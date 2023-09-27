#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include "DIO_Interface.h"

void DIO_VidSetPinDirection(u8 copy_u8port ,u8 copy_u8Pin, u8 copy_U8Direction)
{
	if(copy_U8Direction==1)
	{
		switch(copy_u8port)
		{
			case 0: SET_BIT(DDRA,copy_u8Pin);break;
			case 1: SET_BIT(DDRB,copy_u8Pin);break;
			case 2: SET_BIT(DDRC,copy_u8Pin);break;
			case 3: SET_BIT(DDRD,copy_u8Pin);break;
		}
	}
	else if(copy_U8Direction==0)
	{
		switch(copy_u8port)
		{
			case 0: CLR_BIT(DDRA,copy_u8Pin);break;
			case 1: CLR_BIT(DDRB,copy_u8Pin);break;
			case 2: CLR_BIT(DDRC,copy_u8Pin);break;
			case 3: CLR_BIT(DDRD,copy_u8Pin);break;
		}

	}
}

void DIO_VidSetPinValue(u8 copy_U8port ,u8 copy_U8Pin , u8 copy_U8Value)
{
	if(copy_U8Value==1)
	{
		switch(copy_U8port)
		{
			case 0: SET_BIT(PORTA,copy_U8Pin);
				break;
			case 1: SET_BIT(PORTB,copy_U8Pin);
				break;
			case 2: SET_BIT(PORTC,copy_U8Pin);
				break;
			case 3: SET_BIT(PORTD,copy_U8Pin);
				break;
		}
	}
	else if(copy_U8Value==0)
	{
		switch(copy_U8port)
		{
			case 0: CLR_BIT(PORTA,copy_U8Pin);
				break;
			case 1: CLR_BIT(PORTB,copy_U8Pin);
				break;
			case 2: CLR_BIT(PORTC,copy_U8Pin);
				break;
			case 3: CLR_BIT(PORTD,copy_U8Pin);
				break;
		}

	}
}



u8 DIO_U8GetPinValue(u8 copy_u8port ,u8 copy_U8Pin)
{
	switch(copy_u8port)
	{
		case 0:return GET_BIT(PINA,copy_U8Pin);break;
		case 1:return GET_BIT(PINB,copy_U8Pin);break;
		case 2:return GET_BIT(PINC,copy_U8Pin);break;
		case 3:return GET_BIT(PIND,copy_U8Pin);break;
	}
}


void DIO_VidSetPortValue(u8 copy_u8port ,u8 copy_U8Value)
{
	switch(copy_u8port)
	{
		case 0:PORTA=copy_U8Value;break;
		case 1:PORTB=copy_U8Value;break;
		case 2:PORTC=copy_U8Value;break;
		case 3:PORTD=copy_U8Value;break;
	}
}

void DIO_VidSetPortDirection(u8 copy_u8port ,u8 copy_U8Direction)
{
	switch(copy_u8port)
	{
		case 0:DDRA=copy_U8Direction;break;
		case 1:DDRB=copy_U8Direction;break;
		case 2:DDRC=copy_U8Direction;break;
		case 3:DDRD=copy_U8Direction;break;
	}
}

void DIO_VidToggelPinValue(u8 copy_u8port ,u8 copy_U8Pin)
{
		switch(copy_u8port)
		{
			case 0: TOG_BIT(PORTA,copy_U8Pin);
				break;
			case 1: TOG_BIT(PORTB,copy_U8Pin);
				break;
			case 2: TOG_BIT(PORTC,copy_U8Pin);
				break;
			case 3: TOG_BIT(PORTD,copy_U8Pin);
				break;
		}
}
