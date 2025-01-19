/**
 * @file AVR64DD32-USART-PHOTODIODE-Receiver.c
 * @brief Main program for the AVR64DD32 microcontroller to receive data via USART using a photodiode.
 * 
 * This program configures the microcontroller's clock, GPIO, and USART peripherals. 
 * It continuously reads data using a photodiode and processes it.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#include "Settings.h"

/**
 * @brief Main entry point of the program.
 * 
 * The main function initializes the necessary peripherals:
 * - Configures the clock to run at 24 MHz.
 * - Initializes the GPIO for general-purpose I/O operations.
 * - Initializes USART0 for receiving data.
 * After initialization, it continuously calls the `LedDataReader()` function to read data using the photodiode.
 * 
 * @return This function does not return any value as it contains an infinite loop.
 */
int main(void)
{
    CLOCK_INHF_clock_init(); ///< Configure the system clock to 24 MHz.
    GPIO_init(); ///< Initialize general-purpose input/output (GPIO) pins.
    USART0_init(); ///< Initialize USART0 for receiving data only.

    while (1) 
    {
        LedDataReader(); ///< Continuously read data from the photodiode.
    }
}
