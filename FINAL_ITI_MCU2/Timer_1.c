#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer_1.h"
#include <avr/interrupt.h>

#define NULL ((void *)0)

void (*ICU_PFCallBack)(void)=NULL;
void Timer0_Init_CTC_Mode(unsigned char distance)
{
	TCNT0 = 0;    // Set Timer initial value to 0

	OCR0  =(distance*5 * 16000)/1024  ;// Set Compare Value

	TIMSK |= (1<<OCIE0); // Enable Timer0 Compare Interrupt

	/* Configure timer0 control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
}
void Timer1_VidTimer1Normal (void)
{
	/*MODE -> Normal*/
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);

	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);


	/* CLK / 256 	*/
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
}

void Timer1_VidTimer1FPWM (void)
{
	/*MODE -> FAST PWM*/
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);

	/*CLEAR OC1A*/
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);

	ICR1=19999;

	/* CLK / 8 	*/
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}

void ICU_VidInit(void){
	/*rising edge*/
	SET_BIT(TCCR1B,ICES1);

	/*INPUT CAPTURE INTERRUPT ENABLE*/
	SET_BIT(TIMSK,TICIE1);
}


void ICU_VidEdgeSelect(u8 Copy_U8EdgeSelect)
{
	switch(Copy_U8EdgeSelect)
	{
	case 0:
		CLR_BIT(TCCR1B,ICES1);
		break;
	case 1:
		SET_BIT(TCCR1B,ICES1);
		break;

	}
}



u16 ICU_U16ReadICR()
{
	return	ICR1;//Value of TCNT1
}
void ICU_VidINT_Disable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}

void ICU_VidSetCallBack(void (*Copy_pfCallBack)(void)){
	ICU_PFCallBack=Copy_pfCallBack;
}

ISR(TIMER1_CAPT_vect)
{
	if(ICU_PFCallBack != NULL)
		ICU_PFCallBack();
}

