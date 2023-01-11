/*****************USART*************/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "uart.h"

void USART_Init(uint32_t ubr)
{
	UBRRH = (ubr>>8);    	// Set baud rate
	UBRRL =  ubr;
	UCSRC =  (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);	// 8bit data format
	UCSRB = (1<<TXEN) | (1<<RXEN); 		// Enable transmitter and receiver*/
}

void USARTWriteChar(char data) { // blocking
	while(!(UCSRA & (1<<UDRE))) {}
	UDR=data;
}

void USART_TransmitString(char *data)
{
    while (*data) USARTWriteChar(*data++);
}





