/**
 * @file CLK.c
 * @brief Clock configuration functions for AVR64DD32 microcontroller.
 * 
 * This file contains the implementation of functions related to configuring the internal clock system.
 * The main clock is set to 24 MHz, and the configuration ensures that the microcontroller uses the 
 * internal high-frequency oscillator (OSCHF) for the main clock source.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#include "Settings.h"

/**
 * @brief Initializes the internal high-frequency oscillator and configures the system clock.
 * 
 * This function sets up the internal 24 MHz clock as the main clock source for the microcontroller.
 * It also enables the optional clock output and sets up the main clock prescaler if needed (currently commented out).
 * 
 * @details The clock configuration includes:
 * - Setting the internal oscillator to a frequency of 24 MHz.
 * - Optionally enabling the clock output on pin PA4 (currently commented out).
 * - Ensuring the system clock uses the internal oscillator as its source.
 * - Waiting for the system oscillator change to complete.
 */
void CLOCK_INHF_clock_init() {
    /* Enable internal (24 MHz) clock input */
    ccp_write_io((uint8_t *) &CLKCTRL.OSCHFCTRLA, CLKCTRL_FRQSEL_24M_gc); ///< Set oscillator frequency to 24 MHz.
    
    /* Set Main Clock Prescaler (commented out by default) */
    // ccp_write_io((uint8_t *) &CLKCTRL.MCLKCTRLB, CLKCTRL_PDIV_2X_gc | CLKCTRL_PEN_bm); ///< Enable clock prescaler if needed (currently not used).

    /* Set the main clock to use internal clock as source */
    ccp_write_io((uint8_t *) &CLKCTRL.MCLKCTRLA, CLKCTRL_CLKSEL_OSCHF_gc | CLKCTRL_CLKOUT_bm); ///< Set the internal 24 MHz oscillator as the main clock source, with optional clock output on PA4.

    /* Wait for system oscillator change to complete */
    while (CLKCTRL.MCLKSTATUS & CLKCTRL_SOSC_bm) {}; ///< Wait for oscillator switch to be completed.
}
