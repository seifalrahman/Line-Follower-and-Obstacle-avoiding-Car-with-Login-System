
#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_VidWriteByte(u16 Copy_u16ByteAddress,u8 Copy_u8Data);

u8 EEPROM_VidReadByte(u16 Copy_u16ByteAddress);

#define uniqueAddress	0x50

void writeStringToEEPROM(const u8* str, u16 addr);

void readStringFromEEPROM(u8* str, u16 addr, u8 maxSize);

/*Selsecr EEPROM
 * 1-0
 * 2-1
 * */
//unsigned char eepromRead(unsigned int addr);
//void eepromWrite(unsigned int addr,unsigned char dat);

#define A2	0

#endif /* E2PROM_H_ */
