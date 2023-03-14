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
	
	uint8_t myvar1 = 40;
	uint8_t myvar2 = 16;
	uint8_t myvar3 = 9;
	

	/* main loop */
	for(uint8_t i = 0; i < 65565; i++) {

		printf("%u:%u:%u: Cycle start\n", myvar1, myvar2, myvar3);
		printf("End of iteration %d.\n", i);
		_delay_ms(2000);
	}

	return 0;
}
