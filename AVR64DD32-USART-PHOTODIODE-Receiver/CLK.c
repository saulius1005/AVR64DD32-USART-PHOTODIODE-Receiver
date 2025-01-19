/*
 * CLK.c
 *
 * Created: 2025-01-19 16:56:30
 *  Author: Saulius
 */ 

#include "Settings.h"

void CLOCK_INHF_clock_init(){
	/* Enable internal (24 MHz) clock input */
	ccp_write_io((uint8_t *) &CLKCTRL.OSCHFCTRLA, CLKCTRL_FRQSEL_24M_gc); //1, 2, 3, 4, 8, 12, 16, 20 or 24Mhz

	/* Set Main Clock Prescaler*/
	//ccp_write_io((uint8_t *) &CLKCTRL.MCLKCTRLB, CLKCTRL_PDIV_2X_gc | CLKCTRL_PEN_bm); // uncomment if need clock prescaller

	/* Set the main clock to use internal clock as source */
	ccp_write_io((uint8_t *) &CLKCTRL.MCLKCTRLA, CLKCTRL_CLKSEL_OSCHF_gc | CLKCTRL_CLKOUT_bm); //comment | CLKCTRL_CLKOUT_bm if no need clock output on PA4

	/* Wait for system oscillator change to complete */
	while (CLKCTRL.MCLKSTATUS & CLKCTRL_SOSC_bm)
	{};
}
