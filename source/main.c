/*	Author: Trung Lam
 *  Partner(s) Name: None
 *	Lab Section: B22
 *	Assignment: Lab #2  Exercise #2
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs (parking sensors)
  	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs (# of spaces)

  	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;

  	while(1) {
    		// 1) Read input
    		tmpA = PINA & 0x0F; //initialize tmpA with A3-A0 

    		// 2) Perform computation
    		if(tmpA == 0x0F){
			tmpC = 0x00;
		}
		else if(tmpA == 0x0E || tmpA == 0x07 || tmpA == 0x0B || tmpA == 0x0D){
			tmpC = 0x01;
		}
		else if(tmpA == 0x0C || tmpA == 0x06 || tmpA == 0x03 || tmpA == 0x09 || tmpA == 0x05 || tmpA == 0x0A) {
			tmpC = 0x02;
		}
		else if(tmpA == 0x08 || tmpA == 0x04 || tmpA == 0x02 || tmpA == 0x01){
			tmpC = 0x03;
		}
		else{
			tmpC = 0x04;
		}

    		// 3) Write output
    		PORTC = tmpC;
  	}
  	return 0;
}
