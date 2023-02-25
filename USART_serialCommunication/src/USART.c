/*
 * USART.c
 *
 * Created: 25.02.2023 08:06:32
 *  Author: lenovo
 */ 

#include "USART.h"

/* Define a stream for printf function */
static FILE mystdout = FDEV_SETUP_STREAM(sendCharUSART_printf, NULL, _FDEV_SETUP_WRITE);

void initUSARTdebug()
{
	/* setup our stdio stream */
	stdout = &mystdout;

	/* Initialize USART */
	initUSART();

}

void initUSART()
{
	// Set Baud Rate
	UBRR0H = BAUD_PRESCALER >> 8;
	UBRR0L = BAUD_PRESCALER;
	
	// Set Frame Format
	UCSR0C = ASYNCHRONOUS | PARITY_MODE | STOP_BIT | DATA_BIT;
	
	// Enable Receiver and Transmitter
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
}

void sendCharUSART(uint8_t DataByte)
{
	while (( UCSR0A & (1<<UDRE0)) == 0) {}; // Do nothing until UDR is ready
	UDR0 = DataByte;
}

int sendCharUSART_printf(char var, FILE *stream)
{
	// translate \n to \r for br@y++ terminal
	if (var == '\n') sendCharUSART('\r');
	sendCharUSART(var);
	return 0;
}