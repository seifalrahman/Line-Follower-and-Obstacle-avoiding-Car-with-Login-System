#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/delay.h>
#include <avr/io.h>
#include "IIC.h"
#include "EEPROM.h"


void EEPROM_VidWriteByte(u16 Copy_u16ByteAddress,u8 Copy_u8Data)
{
	TWI_VidStartCondition();

	TWI_VidSlaveAddressWrite(uniqueAddress | (A2<<2) |(Copy_u16ByteAddress>>8));

	TWI_VidMasterSendData((u8)Copy_u16ByteAddress);

	TWI_VidMasterSendData(Copy_u8Data);

	TWI_VidStopCondition();

	_delay_ms(10);
}


u8 EEPROM_VidReadByte(u16 Copy_u16ByteAddress)
{
	u8 Local_u8Data;

	TWI_VidStartCondition();

	TWI_VidSlaveAddressWrite(uniqueAddress | (A2<<2) |(Copy_u16ByteAddress>>8));

	TWI_VidMasterSendData((u8)Copy_u16ByteAddress);

	TWI_VidStartCondition();

	TWI_VidSlaveAddRead(uniqueAddress | (A2<<2) |(Copy_u16ByteAddress>>8));

	Local_u8Data=TWI_VidMasterReadData();

	TWI_VidStopCondition();

	return Local_u8Data;
}
void writeStringToEEPROM(const u8* str, u16 addr)//str data ,addr address
{
	while (*str != '\0')
	{
		EEPROM_VidWriteByte((u8*)addr, *str);
		//eepromWrite((u8*)addr,*str) ;
		str++;
		addr++;
	}
	//eepromWrite((u8*)addr,'\0'); // Null terminator
	EEPROM_VidWriteByte((u8*)addr, '\0');
}

void readStringFromEEPROM(u8* str, u16 addr, u8 maxSize)
{
	u8 i = 0;
	u8 data;
	do
	{
		data = EEPROM_VidReadByte((const u8*)addr);
		//data=eepromRead((const u8*)addr);
		str[i] = data;
		i++;
		addr++;
	} while (data != '\0' && i < maxSize);
}
/*
void eepromWrite(unsigned int addr,unsigned char dat){

	while(EECR&(1<<EEWE));

	EEAR=addr;
	EEDR=dat;

	EECR|=(1<<EEMWE);

	EECR|=(1<<EEWE);
}


unsigned char eepromRead(unsigned int addr){

	while(EECR&(1<<EEWE));

	EEAR=addr;

	EECR|=(1<<EERE);

	return EEDR;
}
*/
