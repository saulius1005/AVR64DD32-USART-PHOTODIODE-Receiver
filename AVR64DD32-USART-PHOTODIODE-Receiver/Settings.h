/*
 * Settings.h
 *
 * Created: 2025-01-19 16:56:15
 *  Author: Saulius
 */ 


#ifndef SETTINGS_H_
#define SETTINGS_H_

/**
 * @brief CPU clock frequency (F_CPU).
 * 
 * This macro defines the system clock frequency used for various calculations, including baud rate configuration.
 */
#define F_CPU 24000000

/**
 * @brief Macro for calculating the USART0 baud rate.
 * 
 * This macro calculates the baud rate for USART0 based on the desired baud rate and system clock (F_CPU).
 * 
 * @param BAUD_RATE Desired baud rate.
 * @return Calculated baud rate setting for USART0.
 */
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (8 *(float)BAUD_RATE)) + 0.5)

#include <avr/io.h>      /**< Include AVR I/O library for register definitions and hardware control */
#include <stdio.h>       /**< Include standard I/O library for functions like printf */
#include <string.h>      /**< Include string library for handling string functions like strlen */
#include <stdlib.h>
#include <avr/cpufunc.h>
#include <util/delay.h>
#include "USART.h"

/**
 * @brief Initializes the General Purpose I/O (GPIO) pins for necessary tasks.
 * 
 * This function configures the necessary GPIO pins for communication, control, 
 * or other I/O purposes. The exact configuration will depend on the application.
 */
void GPIO_init();

void CLOCK_INHF_clock_init();

/**
 * @brief Initializes USART0 for serial communication.
 * 
 * Configures the USART0 for transmitting and receiving data.
 */
void USART0_init();

/**
 * @brief Sends a character over USART0.
 * 
 * @param c Character to send.
 */
void USART0_sendChar(char c);

/**
 * @brief Sends a string over USART0.
 * 
 * @param str String to send.
 */
void USART0_sendString(char *str);

/**
 * @brief USART0 character output function for printf.
 * 
 * @param c Character to send.
 * @param stream Stream for the output.
 * @return Character sent.
 */
int USART0_printChar(char c, FILE *stream);

/**
 * @brief Reads a character from USART0.
 * 
 * @return Character received.
 */
char USART0_readChar();

/**
 * @brief Sends formatted data over USART.
 * 
 * @param format Format string for the data.
 */
void USART_printf(const char *format, ...);

void LedDataReader();

#endif /* SETTINGS_H_ */