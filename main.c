#include <msp430.h> 

/*
 * testprogramma voor button
 * kopieert button state naar rode led
 */
 
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
	// Pin 1.0 = rode led
	// Pin 1.3 = button
    P1DIR = 1<<0;
    P1OUT = 0;
    
    P1REN = 1<<3; // enable pull-up or down
    P1OUT |= 1<<3; // select pull-up
    
    while (1)
    {
        if ((P1IN & 1<<3) == 1<<3)
        {
            P1OUT |= 1<<0;
        }
        else
        {
            P1OUT &= ~1<<0;
        }
    }
    
	return 0;
}
