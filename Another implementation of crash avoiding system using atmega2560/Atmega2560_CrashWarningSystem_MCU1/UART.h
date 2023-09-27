/*
 * UART.h
 *
 *  Created on: Sep 21, 2023
 *      Author: seif alrahman
 */

#ifndef UART_H_
#define UART_H_
void UART_Init();
void UART_Transmit(unsigned char data);
unsigned char UART_Receive();
#endif /* UART_H_ */
