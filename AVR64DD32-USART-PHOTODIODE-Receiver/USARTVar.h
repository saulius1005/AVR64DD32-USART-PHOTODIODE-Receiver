/**
 * @file USARTVar.h
 * @brief Header file for defining and initializing global USART-related variables.
 * 
 * This file defines and initializes the global variable `UART_READ_PHOTODIODE`, 
 * which holds the ADC voltage and corresponding angle data received via USART communication.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#ifndef USARTVAR_H_
#define USARTVAR_H_

/**
 * @brief Global variable to store photodiode data (ADC voltage and angle).
 * 
 * This global variable holds the ADC voltage reading and the calculated angle from 
 * the photodiode sensor. It is initialized with default values: ADC voltage set to 0 
 * and angle set to 0.0.
 */
UST UART_READ_PHOTODIODE = {
    .ADC_Voltage = 0, ///< Initial ADC voltage value (0).
    .Angle = 0.0,      ///< Initial angle value (0.0).
	.warning = 0,	///< Initial warning value (0).
	.errorCounter = 0, ///< Initial error counter value (0).
	.error = 0	///< Initial error value (0).
};

#endif /* USARTVAR_H_ */
