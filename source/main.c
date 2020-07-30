/*	Author: Trung Lam
 *  Partner(s) Name: None
 *	Lab Section: B22
 *	Assignment: Lab #2  Exercise #4
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs (weight person 1)
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs (weight person 2)
  	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs (weight person 3)
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as output (output)

  	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;

  	while(1) {
    		// 1) Read input
    		tmpA = PINA & 0xFF;  
		tmpB = PINB & 0xFF;
		tmpC = PINC & 0xFF;

    		// 2) Perform computation
    		if( (tmpA + tmpB + tmpC) > 0x8C){
			tmpD = 0x01;
		}

    		// 3) write output
  	}
  	return 0;
}
