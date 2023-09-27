#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/io.h>
#include "UART.h"

void UART_VidInit(void)
{

	u16 Local_u16BaudRate=51;
	u8 Local_u8USCRC=0b10000000;

	/*Baud Rate 9600*/
	UBRRL=(u8)Local_u16BaudRate;
	UBRRH=(u8)(Local_u16BaudRate>>8);

	/*Normal Speed */
	CLR_BIT(UCSRA,U2X);

	/*Disable Multi-processor*/
	CLR_BIT(UCSRA,MPCM);

	/*RX Enable / TX Enable */
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);

	/*Select 8 bit */
	SET_BIT(Local_u8USCRC,UCSZ0);
	SET_BIT(Local_u8USCRC,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);

	/*Asynchronous Operation*/
	CLR_BIT(Local_u8USCRC,UMSEL);

	/*Parity Mode Disable*/
	CLR_BIT(Local_u8USCRC,UPM0);
	CLR_BIT(Local_u8USCRC,UPM1);

	/*Stop Bit (2)*/
	SET_BIT(Local_u8USCRC,USBS);

	UCSRC=Local_u8USCRC;

}


void UART_VidSendData(u16 Copy_u16Data)
{
	/*Wait to empty shift reg*/
	while(GET_BIT(UCSRA,UDRE)==0);

	UDR=(u8)Copy_u16Data;

}



u16 UART_VidReciveData(void)
{
	/*Wait to*/
	while(GET_BIT(UCSRA,RXC)==0);

	return UDR;

}



