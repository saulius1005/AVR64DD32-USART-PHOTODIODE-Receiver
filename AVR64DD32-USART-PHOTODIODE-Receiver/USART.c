/*
 * USART.c
 *
 * Created: 2025-01-19 16:59:25
 *  Author: Saulius
 */ 
#include "Settings.h"
#include "USARTVar.h"

/**
 * @brief Initializes USART0 with a baud rate of 2500000.
 * 
 * This function configures USART0 for asynchronous communication, enabling both
 * transmission and reception at a baud rate of 0.25 Mbps with double-speed operation.
 */
void USART0_init() {
	USART0.BAUD = (uint16_t)USART0_BAUD_RATE(250000); // Set baud rate to 0.25 Mbps
	USART0.CTRLB = USART_RXEN_bm | USART_RXMODE_CLK2X_gc; // Enable RX, double speed mode
	USART0.CTRLC = USART_CMODE_ASYNCHRONOUS_gc | USART_CHSIZE_8BIT_gc | USART_PMODE_DISABLED_gc | USART_SBMODE_1BIT_gc; // Configure for 8-bit, no parity, 1 stop bit, asynchronous mode
}

/**
 * @brief Sends a single character via USART0.
 * 
 * This function waits until the USART0 data register is empty and then transmits a character.
 * 
 * @param c The character to send.
 */
void USART0_sendChar(char c) {
	while (!(USART0.STATUS & USART_DREIF_bm)); // Wait for data register to be empty
	USART0.TXDATAL = c; // Send character
}

/**
 * @brief Sends a string via USART0.
 * 
 * This function sends each character of the string one by one using the USART0_sendChar function.
 * 
 * @param str The string to send.
 */
void USART0_sendString(char *str) {
	for (size_t i = 0; i < strlen(str); i++) {
		USART0_sendChar(str[i]); // Send each character
	}
}

/**
 * @brief Reads a single character from USART0.
 * 
 * This function waits until a character is received on USART0, clears the receive interrupt flag, and then returns the received character.
 * 
 * @return The received character.
 */
char USART0_readChar() {
	USART0.STATUS = USART_RXCIF_bm; // Clear buffer before reading
	while (!(USART0.STATUS & USART_RXCIF_bm)); // Wait for data to be received
	return USART0.RXDATAL; // Return received character
}

/**
 * @brief Sends a formatted string via the selected USART.
 * 
 * This function formats the input string with the provided arguments and sends it via the specified USART (either USART0 or USART1).
 * @param format The format string.
 * @param ... The arguments to be formatted into the string.
 */
void USART_printf(const char *format, ...) {
	char buffer[128]; // Temporary buffer for formatted message
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args); // Format the message into the buffer
	va_end(args);
	USART0_sendString(buffer); // Use USART0 for sending
}


void executeCommand(char *command) {
	UART_READ_PHOTODIODE.ADC_Voltage = atoi(command);
	UART_READ_PHOTODIODE.Angle = 0.3515625 * UART_READ_PHOTODIODE.ADC_Voltage; //360/1024 = 0,3515625
}

void LedDataReader() {
	uint8_t index = 0;
	char command[15] = {0};
	uint8_t start = 0;

	while (1) {
		char c = USART0_readChar();
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
	}
}