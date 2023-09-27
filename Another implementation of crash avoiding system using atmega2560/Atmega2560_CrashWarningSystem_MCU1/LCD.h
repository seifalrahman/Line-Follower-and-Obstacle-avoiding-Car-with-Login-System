#ifndef LCD_2_H
#define  LCD_2_H

#define LCD_DATA_PORT		PORT_A
#define LCD_CMD_PORT		PORT_C

#define RS		PIN_5
#define RW		PIN_6
#define EN		PIN_7

#define FUN_SET			0b00111000
#define C_ON_OFF		0b00001111
#define LCD_CLR			0b00000001

#define LINE_1		0
#define LINE_2		1

void LCD_VidInit(void);

void LCD_VidSendCMD(u8 Copy_U8CMD);

void LCD_VidSendChar(u8 Copy_U8Char);

void LCD_VidSendString(u8 *Copy_U8ptr);

void LCD_VidLocation(u8 Copy_U8Line,u8 Copy_U8CharNum);
void LCD_VidSendMultiInt(u32 Copy_U8MultiInt);
void LCD_VidSendSingleInt(u8 Copy_U8SingleInt);
void LCD_Clear (void);
#endif
