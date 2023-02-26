/*******************************/
/*** Created by Ovidiu Sabau ***/
/***	25th February 2023	 ***/
/*******************************/

#define F_CPU 16000000UL

#include <util/delay.h>
#include "USART.h"


int main(void)
{
	/* Initialization of USART */
	initUSARTdebug();
	
	uint8_t myvar = 40;

	/* main loop */
	for(uint8_t i = 0; i < 65565; i++) {

		printf("The variable as an unsigned integer: %d\n", myvar);
		printf("The variable as a char: %c\n", myvar);
		printf("The variable in hex: 0x%X\n", myvar);
		printf("The variable in octal: %o\n", myvar);
		printf("End of iteration %d.\n", i);
		_delay_ms(2000);
	}

	return 0;
}
