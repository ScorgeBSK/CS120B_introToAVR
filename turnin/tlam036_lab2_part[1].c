/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs (the sensors)
  	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs (the LED)

  	unsigned char tmpA0 = 0x00; //initialize temporary holders for the values  
	unsigned char tmpA1 = 0x00;
	unsigned char tmpB = 0x00;
  	while(1) {
    		// 1) Read input
    		tmpA0 = PINA & 0x01; //set tmpA0 to the A0 bit
		tmpA1 = PINA & 0x02; //set tmpA1 to the A1 bit

    		// 2) Perform computation
    		if ( (tmpA0 == 0x01) && (tmpA1 == 0x02) ) {        //if both sensors are on
      			tmpB = 0x00;                               //then LED is off
		}
		else if( (tmpA0 == 0x00) && (tmpA1 == 0x02) ){     //if light is detected but garage is closed
			tmpB = 0x00;                               //then LED is off
		}
		else if( (tmpA0 == 0x01) && (tmpA1 == 0x00) ){     //if garage door is open but no light
			tmpB = 0x01;                               //then LED is on
		}
		else {
			tmpB = 0x00;                               //if both are off
								   //LED is off
		}

    		// 3) Write output
    		PORTB = tmpB;
  	}
  	return 0;
}
