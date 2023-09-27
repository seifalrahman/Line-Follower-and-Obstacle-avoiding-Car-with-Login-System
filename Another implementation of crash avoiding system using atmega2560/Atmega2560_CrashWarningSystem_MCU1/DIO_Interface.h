#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H



void DIO_VidSetPinDirection(u8 copy_u8port ,u8 copy_u8Pin, u8 copy_U8Direction);

void DIO_VidSetPinValue(u8 copy_U8port ,u8 copy_U8Pin , u8 copy_U8Value);

u8 DIO_U8GetPinValue(u8 copy_u8port ,u8 copy_U8Pin);

void DIO_VidSetPortValue(u8 copy_u8port ,u8 copy_U8Value);

void DIO_VidSetPortDirection(u8 copy_u8port ,u8 copy_U8Direction);

void DIO_VidToggelPinValue(u8 copy_u8port ,u8 copy_U8Pin);


#define PORT_A	0
#define PORT_B	1
#define PORT_C	2
#define PORT_D	3


#define PIN_0	0
#define PIN_1	1
#define PIN_2	2
#define PIN_3	3
#define PIN_4	4
#define PIN_5	5
#define PIN_6	6
#define PIN_7	7

#define DIO_OUTPUT	1
#define DIO_INPUT	0

#define DIO_HIGH	1
#define DIO_LOW		0



#endif
