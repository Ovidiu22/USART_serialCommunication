/*
 * USART.h
 *
 * Created: 25.02.2023 08:06:15
 *  Author: lenovo
 */ 

#ifndef USART_H_
#define USART_H_
	#include <stdio.h>

	#ifndef F_CPU
	#define F_CPU 16000000UL // Defining the CPU Frequency
	#endif
	
	#include <avr/io.h>      // Contains all the I/O Register Macros

	#define USART_BAUDRATE 9600 // Desired Baud Rate
	#define BAUD_PRESCALER (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

	#define ASYNCHRONOUS (0<<UMSEL00) // USART Mode Selection

	#define DISABLED    (0<<UPM00)
	#define EVEN_PARITY (2<<UPM00)
	#define ODD_PARITY  (3<<UPM00)
	#define PARITY_MODE  DISABLED // USART Parity Bit Selection

	#define ONE_BIT (0<<USBS0)
	#define TWO_BIT (1<<USBS0)
	#define STOP_BIT ONE_BIT      // USART Stop Bit Selection

	#define FIVE_BIT  (0<<UCSZ00)
	#define SIX_BIT   (1<<UCSZ00)
	#define SEVEN_BIT (2<<UCSZ00)
	#define EIGHT_BIT (3<<UCSZ00)
	#define DATA_BIT   EIGHT_BIT  // USART Data Bit Selection

	void initUSARTdebug(void);
	void initUSART(void);
	void sendCharUSART(uint8_t);
	int sendCharUSART_printf(char var, FILE *stream);

#endif /* USART_H_ */