#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <avr/io.h>
#include "IIC.h"


void TWI_VidMasterInit(void)
{
	/*Prescaller Value*/
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

	/*frequency -> 400KHZ*/
	TWBR=2;

	/*Enable I2C*/
	SET_BIT(TWCR,TWEN);
}

void TWI_VidSlaveInit(u8 Copy_u8Addrss)
{
	/*Enable ACK*/
	SET_BIT(TWCR,TWEA);

	/*Write Address*/
	TWAR=Copy_u8Addrss<<1;

	/*Enable I2C*/
	SET_BIT(TWCR,TWEN);
}

void TWI_VidStartCondition(void)
{
	/*Enable Start Condition & Clear Init flag*/
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWINT);

	/*Wait hardware action*/
	while(GET_BIT(TWCR,TWINT)==0);
}

void TWI_VidStopCondition(void)
{
	/*Enable Stop Condition &Clear Int Flag*/
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTO);
}

void TWI_VidSlaveAddressWrite(u8 Copy_u8SlaveAddress)
{
	/*Write Slave address*/
	TWDR=Copy_u8SlaveAddress<<1;
	/*Write Operation*/
	CLR_BIT(TWDR,0);
	/*Disable Start Condition*/
	CLR_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWINT);
	/*Wait hardware action*/
	while(GET_BIT(TWCR,TWINT)==0);
}

void TWI_VidSlaveAddRead(u8 Copy_u8SlaveAdd)
{
	/*Write Slave address*/
	TWDR=Copy_u8SlaveAdd<<1;
	/*Read Operation*/
	SET_BIT(TWDR,0);
	/*Disable Start Condition*/
	CLR_BIT(TWCR,TWSTA);

	SET_BIT(TWCR,TWINT);
	/*Wait hardware action*/
	while(GET_BIT(TWCR,TWINT)==0);
}

void TWI_VidMasterSendData(u8 Copy_u8Data)
{
	/*Write Data*/
	TWDR=Copy_u8Data;

	SET_BIT(TWCR,TWINT);
	/*Wait hardware action*/
	while(GET_BIT(TWCR,TWINT)==0);
}


u8 TWI_VidSlaveReadData(void)
{
	/*SLA+W has been recieved ACK has been returned*/
	while((TWSR & 0xf8)!=0x60);
	/*Clear Flag*/
	SET_BIT(TWCR,TWINT);
	while((TWSR & 0xf8)!=0x80);
	return TWDR;
}


u8 TWI_VidMasterReadData(void)
{
	SET_BIT(TWCR,TWINT);
	/*Wait hardware action*/
	while(GET_BIT(TWCR,TWINT)==0);
	return TWDR;
}






