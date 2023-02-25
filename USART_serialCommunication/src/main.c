/*******************************/
/*** Created by Ovidiu Sabau ***/
/***	25th February 2023	 ***/
/*******************************/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"
#include <stdio.h>

int main(void)
{
	initUSART();	
	while (1)
	{
		sendCharUSART('P');
		sendCharUSART('U');
		sendCharUSART('I');
		sendCharUSART('U');
		sendCharUSART('C');
		sendCharUSART('\n');
		_delay_ms(1000);
	}
	return 0;
}