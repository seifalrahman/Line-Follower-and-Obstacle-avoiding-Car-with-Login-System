#include <avr/io.h>

// UART initialization
void UART_Init()
{
    // Set baud rate to 9600 (F_CPU = 8MHz)
    UBRR0H = 0;
    UBRR0L = 51;

    // Enable receiver and transmitter
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    // Set frame format: 8-bit data, 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

// UART transmit data
void UART_Transmit(unsigned char data)
{
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));

    // Put data into buffer, sends the data
    UDR0 = data;
}

// UART receive data
unsigned char UART_Receive()
{
    // Wait for data to be received
    while (!(UCSR0A & (1 << RXC0)));

    // Get and return received data from buffer
    return UDR0;
}
