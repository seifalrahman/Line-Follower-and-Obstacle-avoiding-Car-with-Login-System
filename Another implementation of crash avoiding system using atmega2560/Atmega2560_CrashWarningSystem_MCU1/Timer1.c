/*
 * Timer1.c
 *
 *  Created on: Sep 21, 2023
 *      Author: seif alrahman
 */
#include <avr/io.h>

void Timer1_Init()
{
    // Set Timer1 to normal mode
    TCCR1A = 0;
    TCCR1B = 0;

    // Set prescaler to 256
    TCCR1B |= (1 << CS12);



    TCNT1 = 0;


}
