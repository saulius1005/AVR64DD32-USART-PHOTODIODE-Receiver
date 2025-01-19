/*
 * AVR64DD32-USART-PHOTODIODE-Receiver.c
 *
 * Created: 2025-01-19 16:54:30
 * Author : Saulius
 */ 
#include "Settings.h"
int main(void)
{
	CLOCK_INHF_clock_init(); //24Mhz main cpu speed
    GPIO_init(); // initialization of general purpose input and output
	USART0_init(); // initilization USART0 as receiver only
    while (1) 
    {
		LedDataReader();// reading data using photodiode
    }
}

