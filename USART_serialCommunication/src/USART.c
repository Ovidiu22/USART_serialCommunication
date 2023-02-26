

#include "USART.h"

/* Define a stream for printf function */
static FILE mystdout = FDEV_SETUP_STREAM(sendCharUSART_printf, NULL, _FDEV_SETUP_WRITE);

/* *****************************************************************
Name:		initUSARTdebug
Inputs:		none
Outputs:	none
Description:Initializes debugging functionality over USART 
******************************************************************** */
void initUSARTdebug()
{
	/* setup our stdio stream */
	stdout = &mystdout;

	/* Initialize USART */
	initUSART();

}

/* *****************************************************************
Name:		initUSART
Inputs:		none
Outputs:	none
Description:Initializes USART communication
******************************************************************** */
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

/* *****************************************************************
Name:		sendCharUSART
Inputs:		data to be transmitted (one byte)
Outputs:	none
Description:Sends one byte over USART
******************************************************************** */
void sendCharUSART(uint8_t DataByte)
{
	while (( UCSR0A & (1<<UDRE0)) == 0) {}; // Do nothing until UDR is ready
	UDR0 = DataByte;
}

/* *****************************************************************
Name:		sendCharUSART_printf
Inputs:		data to be transmitted ()
Outputs:	none
Description:function linked to printf in order to put out the transmitted string
******************************************************************** */
int sendCharUSART_printf(char var, FILE *stream)
{
	// translate \n to \r for br@y++ terminal
	if (var == '\n') sendCharUSART('\r');
	sendCharUSART(var);
	return 0;
}