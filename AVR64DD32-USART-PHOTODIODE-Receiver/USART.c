/**
 * @file USART.c
 * @brief USART communication functions for AVR64DD32 microcontroller.
 * 
 * This file contains functions for initializing USART0, sending and receiving data, 
 * and handling formatted data via USART communication. It also includes functions 
 * for reading commands and processing photodiode data.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#include "Settings.h"
#include "USARTVar.h"

/**
 * @brief Initializes USART0 with a baud rate of 2500000.
 * 
 * This function configures USART0 for asynchronous communication. It enables both
 * transmission and reception at a baud rate of 2500000 with double-speed operation.
 * The USART0 is configured with 8 data bits, no parity, 1 stop bit, and asynchronous mode.
 */
void USART0_init() {
    USART0.BAUD = (uint16_t)USART0_BAUD_RATE(500000); ///< Set baud rate to 2500000.
    USART0.CTRLB = USART_RXEN_bm | USART_RXMODE_CLK2X_gc; ///< Enable RX with double speed mode.
    USART0.CTRLC = USART_CMODE_ASYNCHRONOUS_gc | USART_CHSIZE_8BIT_gc | USART_PMODE_DISABLED_gc | USART_SBMODE_1BIT_gc; ///< Configure for 8-bit data, no parity, 1 stop bit, and asynchronous mode.
}

/**
 * @brief Sends a single character via USART0.
 * 
 * This function waits until the USART0 data register is empty, then transmits a character.
 * 
 * @param c The character to send.
 */
void USART0_sendChar(char c) {
    while (!(USART0.STATUS & USART_DREIF_bm)); ///< Wait for the data register to be empty.
    USART0.TXDATAL = c; ///< Send the character to the USART data register.
}

/**
 * @brief Sends a string via USART0.
 * 
 * This function sends each character of the string one by one using the `USART0_sendChar` function.
 * 
 * @param str The string to send.
 */
void USART0_sendString(char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        USART0_sendChar(str[i]); ///< Send each character in the string.
    }
}

/**
 * @brief Reads a single character from USART0.
 * 
 * This function waits until a character is received, clears the receive interrupt flag, 
 * and then returns the received character.
 * 
 * @return The received character from USART0.
 */
char USART0_readChar() {
    USART0.STATUS = USART_RXCIF_bm; ///< Clear the receive interrupt flag.
	uint32_t timeout_counter = TIMEOUT_COUNTER; // Set a timeout counter
    while (!(USART0.STATUS & USART_RXCIF_bm)){ ///< Wait for data to be received.
		if (--timeout_counter == 0) { // Timeout condition
			UART_READ_PHOTODIODE.warning = 1; // Set warning if timeout occurs
			break;
		}
	}
    return USART0.RXDATAL; ///< Return the received character.
}

/**
 * @brief Sends a formatted string via USART0.
 * 
 * This function formats the input string with the provided arguments and sends it via USART0.
 * 
 * @param format The format string.
 * @param ... The arguments to be formatted into the string.
 */
void USART_printf(const char *format, ...) {
    char buffer[128]; ///< Temporary buffer for the formatted message.
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args); ///< Format the message into the buffer.
    va_end(args);
    USART0_sendString(buffer); ///< Send the formatted string via USART0.
}

/**
 * @brief Executes the command received from USART0.
 * 
 * This function processes the command string received from USART0 and updates the
 * photodiode reading data. The ADC voltage is converted into an angle.
 * 
 * @param command The command string received from USART0.
 */
void executeCommand(char *command) {
    UART_READ_PHOTODIODE.ADC_Voltage = atoi(command); ///< Convert the command string to an integer (ADC voltage).
    UART_READ_PHOTODIODE.Angle = 0.3515625 * UART_READ_PHOTODIODE.ADC_Voltage; ///< Convert the ADC voltage to an angle (360/1024 = 0.3515625).
}

/**
 * @brief Reads data from USART0 and processes photodiode information.
 * 
 * This function continuously reads characters from USART0 until a complete command is received.
 * It processes the command string and executes the associated action, such as updating the 
 * photodiode reading.
 */
void LedDataReader() {
    uint8_t index = 0;
    char command[15] = {0};
    uint8_t start = 0;

    while (1) {
	    char c = USART0_readChar();

	    if (!UART_READ_PHOTODIODE.warning) {
			UART_READ_PHOTODIODE.errorCounter = 0;
		    if (start == 1) {
			    if (c == ']') {
				    start = 0;
				    executeCommand(command);
				    index = 0;
				    break;
				    } else {
				    command[index++] = c;
			    }
		    }
		    if (c == '[') {
			    start = 1;
		    }
		    if (UART_READ_PHOTODIODE.error == 1) {
			    UART_READ_PHOTODIODE.errorCounter = 0;
			    UART_READ_PHOTODIODE.error = 0;
		    }
		    } else {
		    UART_READ_PHOTODIODE.warning = 0;
		    if (UART_READ_PHOTODIODE.errorCounter < CountForError) {
			    UART_READ_PHOTODIODE.errorCounter += 1;
			    } else {
			    UART_READ_PHOTODIODE.error = 1;
		    }
		    break;
	    }
    }
}
