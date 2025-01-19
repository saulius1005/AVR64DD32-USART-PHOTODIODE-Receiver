/*
 * USART.h
 *
 * Created: 2025-01-19 17:24:47
 *  Author: Saulius
 */ 


#ifndef USART_H_
#define USART_H_

typedef struct { 
    uint16_t ADC_Voltage;
	double Angle;
} UST;

/**
 * @brief Global variable for storing altitude data.
 */
extern UST UART_READ_PHOTODIODE;

#endif /* USART_H_ */