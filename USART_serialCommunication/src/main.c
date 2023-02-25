/*******************************/
/*** Created by Ovidiu Sabau ***/
/***	25th February 2023	 ***/
/*******************************/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include "USART.h"


int main(void)
{
	/* Initialization of USART */
	initUSARTdebug();
	
	uint8_t myvalue = 40;

	/* main loop */
	while(1) {

		printf("Here is myvalue as an unsigned integer: %d\n", myvalue);
		printf("Here is myvalue as a char: %c\n", myvalue);
		printf("Here is myvalue in hex: 0x%X\n", myvalue);
		printf("Here is myvalue in octal: %o\n", myvalue);
		printf("End of section.\n");
		_delay_ms(2000);
	}

	return 0;
}
