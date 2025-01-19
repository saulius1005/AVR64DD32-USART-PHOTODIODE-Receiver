/**
 * @file Settings.h
 * @brief Header file for configuring and initializing peripherals on the AVR64DD32 microcontroller.
 * 
 * This file defines macros, includes necessary libraries, and declares function prototypes 
 * for GPIO, clock, USART, and other peripheral configurations.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

/**
 * @brief CPU clock frequency (F_CPU).
 * 
 * This macro defines the system clock frequency used for various calculations, including baud rate configuration.
 * The frequency is set to 24 MHz for the microcontroller.
 */
#define F_CPU 24000000

/**
 * @brief Macro for calculating the USART0 baud rate.
 * 
 * This macro calculates the baud rate for USART0 based on the desired baud rate and the system clock (F_CPU).
 * The formula used here assumes the system clock is running at 24 MHz.
 * 
 * @param BAUD_RATE Desired baud rate.
 * @return The calculated baud rate setting for USART0.
 */
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (8 *(float)BAUD_RATE)) + 0.5)

#include <avr/io.h>      /**< Include AVR I/O library for register definitions and hardware control. */
#include <stdio.h>       /**< Include standard I/O library for functions like printf. */
#include <string.h>      /**< Include string library for handling string functions like strlen. */
#include <stdlib.h>      /**< Include standard library for additional utilities. */
#include <avr/cpufunc.h> /**< Include AVR-specific functions like ccp_write_io. */
#include <util/delay.h>  /**< Include delay utilities for timing functions. */
#include "USART.h"       /**< Include custom USART header for additional USART-related functions. */

/**
 * @brief Initializes the General Purpose I/O (GPIO) pins for necessary tasks.
 * 
 * This function configures the necessary GPIO pins for communication, control, 
 * or other I/O purposes. The exact configuration will depend on the application.
 */
void GPIO_init();

/**
 * @brief Initializes the internal high-frequency clock.
 * 
 * Configures the system clock to run at the desired frequency, typically 24 MHz in this case.
 */
void CLOCK_INHF_clock_init();

/**
 * @brief Initializes USART0 for serial communication.
 * 
 * Configures the USART0 peripheral to support transmitting and receiving data at the desired baud rate.
 * It will set up the necessary registers and parameters for asynchronous serial communication.
 */
void USART0_init();

/**
 * @brief Sends a single character over USART0.
 * 
 * This function waits until the USART0 data register is empty and then transmits the specified character.
 * 
 * @param c The character to send.
 */
void USART0_sendChar(char c);

/**
 * @brief Sends a string over USART0.
 * 
 * This function sends a string of characters one by one using the `USART0_sendChar` function.
 * 
 * @param str The string to send.
 */
void USART0_sendString(char *str);

/**
 * @brief USART0 character output function for printf.
 * 
 * This function is used for sending a character when using `printf` in the program.
 * It transmits the character over USART0.
 * 
 * @param c The character to send.
 * @param stream The stream used for output (typically stdout).
 * @return The character sent.
 */
int USART0_printChar(char c, FILE *stream);

/**
 * @brief Reads a character from USART0.
 * 
 * This function waits for the data register to be filled and then reads the received character.
 * 
 * @return The character received from USART0.
 */
char USART0_readChar();

/**
 * @brief Sends formatted data over USART.
 * 
 * This function formats the input string using the provided arguments and sends it via USART0.
 * It uses `vsnprintf` to format the string and transmits it over USART0.
 * 
 * @param format The format string for the data.
 */
void USART_printf(const char *format, ...);

/**
 * @brief Reads data from a photodiode using the LED data reader.
 * 
 * This function reads data using a photodiode sensor and processes it accordingly.
 * The exact data processing logic will depend on the application.
 */
void LedDataReader();

#endif /* SETTINGS_H_ */
