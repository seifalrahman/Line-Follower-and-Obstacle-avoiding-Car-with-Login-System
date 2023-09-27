/*
 * ir.c
 *
 *  Created on: Sep 4, 2023
 *      Author: seif alrahman
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include "DIO_Interface.h"
#include "ir.h"

void IRArrayOf5_Init(void){
	DDRD &=~(0b00011000) ;
}
u8 getIR (u8 snum){
	switch(snum){
	case 1:return GET_BIT(PIND,3);break ;
	case 2:return GET_BIT(PIND,4);break ;

	}
	return 0 ;
}
