#ifndef IIC_H_
#define IIC_H_

void TWI_VidMasterInit(void);

void TWI_VidSlaveInit(u8 Copy_u8Addrss);

void TWI_VidStartCondition(void);

void TWI_VidStopCondition(void);

void TWI_VidSlaveAddressWrite(u8 Copy_u8SlaveAddress);

void TWI_VidSlaveAddRead(u8 Copy_u8SlaveAdd);

void TWI_VidMasterSendData(u8 Copy_u8Data);

u8 TWI_VidSlaveReadData(void);

u8 TWI_VidMasterReadData(void);

#endif /* I2C_H_ */
