/**
 * @file USART.h
 * @brief Header file for USART communication and data storage structures.
 * 
 * This file contains the definition of the `UST` structure, which is used to store the
 * ADC voltage and corresponding angle data received via USART communication. It also 
 * declares the global variable `UART_READ_PHOTODIODE`, which holds the altitude data.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#ifndef USART_H_
#define USART_H_

/**
 * @brief Timeout Counter
 * 
 * Defines the timeout value for USART0 operations.
 */
#define TIMEOUT_COUNTER 500000 ///< Timeout counter value for operations

/** 
 * @brief Error count threshold for handling errors.
 */
#define CountForError 10

/**
 * @struct UST
 * @brief Structure to store ADC voltage and angle data.
 * 
 * This structure is used to store the ADC voltage value and its corresponding
 * angle calculated from the photodiode readings. Also store warnin, error counter and error flag
 */
typedef struct { 
    uint16_t ADC_Voltage; ///< The ADC voltage value from the photodiode sensor.
    double Angle; ///< The calculated angle based on the ADC voltage.
	uint32_t warning;	///< Warning flag if USART0 communication is interrupted
	uint8_t errorCounter; ///< Counter for error confirmation
	uint8_t error;	///< 
} UST;

/**
 * @brief Global variable to store photodiode data (ADC voltage and angle).
 * 
 * This global variable stores the ADC voltage reading and the calculated angle
 * from the photodiode sensor. It is used across the USART communication functions.
 */
extern UST UART_READ_PHOTODIODE;

#endif /* USART_H_ */
