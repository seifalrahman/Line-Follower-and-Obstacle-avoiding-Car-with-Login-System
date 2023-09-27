/*
 * Timer1.c
 *
 *  Created on: Sep 21, 2023
 *      Author: seif alrahman
 */
#include <avr/io.h>
#include <avr/interrupt.h>
void Timer1_Init()
{
    // Set Timer1 to normal mode
    TCCR1A = 0;
    TCCR1B = 0;

    // Set prescaler to 256
    TCCR1B |= (1 << CS12);



    TCNT1 = 0;


}
void Timer1_Init_CTC(unsigned char distance)
{
    // Set Timer1 to CTC (Compare) mode
    unsigned long compareValue = (distance*10 * 8000UL) / 256UL;
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B |= (1 << WGM12);

    // Set prescaler to 256
    TCCR1B |= (1 << CS12);


    OCR1A = (unsigned int)compareValue;
    // Enable Timer1 compare interrupt
    TIMSK1 |= (1 << OCIE1A);

    // Enable global interrupts
    sei();
}
