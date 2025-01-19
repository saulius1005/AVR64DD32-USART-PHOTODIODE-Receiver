/*
 * GPIO.c
 *
 * Created: 2025-01-19 16:56:02
 *  Author: Saulius
 */ 
#include "Settings.h"

void GPIO_init(){
	PORTA.DIRCLR = PIN1_bm; // Set PA1 as input (USART0 RX)
	PORTA.PIN1CTRL = PORT_PULLUPEN_bm | PORT_INVEN_bm; // Enable pull-up and inverting input signal for PA1 (USART0 RX)
}