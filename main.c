#include <msp430g2553.h>

#define LED_1 0x40                      // BIT6

void main(void) {
    WDTCTL = WDTPW + WDTHOLD;           // Stop watchdog timer
    P1DIR &= ~0x08;                 // Push Port 1 P1.3 (push button) as input
    P1DIR |= LED_1;                     // Set P1.6 (LED) to output direction
    P1SEL &= ~0x08;                 // Select Port 1 P1.3 (push button)
    P1OUT &= ~LED_1;                    // Set the LED off

    while( 1 ) {
        if( (P1IN & 0x08) == 0)             // Push button down when bit 3 == 0
            P1OUT |= LED_1;         // Set LED on when button down
        else
            P1OUT &= ~LED_1;            // Set LED off when button off
    }
}

