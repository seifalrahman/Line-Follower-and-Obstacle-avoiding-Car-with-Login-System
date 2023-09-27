/*
 * Servo_Motor.h
 *
 *  Created on: Aug 21, 2023
 *      Author: DELL
 */

#ifndef TIMER_1_H_
#define TIMER_1_H_

#define NULL ((void *)0)

void Timer1_VidTimer1Normal (void);

void Timer1_VidTimer1FPWM (void);

void ICU_VidInit(void);

void ICU_VidEdgeSelect(u8 Copy_U8EdgeSelect);

u16 ICU_U16ReadICR();
void Timer0_Init_CTC_Mode(unsigned char tick);
void ICU_VidINT_Disable(void);

void ICU_VidSetCallBack(void (*Copy_pfCallBack)(void));

#endif /* TIMER_1_H_ */
