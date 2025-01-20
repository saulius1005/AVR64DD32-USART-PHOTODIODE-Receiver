/**
 * @file GPIO.c
 * @brief GPIO configuration for the AVR64DD32 microcontroller.
 * 
 * This file contains the implementation of GPIO initialization, 
 * specifically for setting up input pins, such as the USART0 RX pin.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#include "Settings.h"

/**
 * @brief Initializes GPIO pins for USART0 RX.
 * 
 * This function configures the necessary GPIO pins for the USART0 receiver:
 * - PA1 is configured as an input.
 * - A pull-up resistor is enabled on PA1 to ensure a defined high level when no signal is present.
 * - The input signal is inverted for proper signal reception from the photodiode.
 */
void GPIO_init() {
    PORTA.DIRCLR = PIN1_bm; ///< Set PA1 as input (USART0 RX).
    PORTA.PIN1CTRL = PORT_PULLUPEN_bm /*| PORT_INVEN_bm*/; ///< Enable pull-up resistor and invert input signal for PA1.
}
