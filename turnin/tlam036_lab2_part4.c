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
#include <stdlib.h>
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs (weight person 1)
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs (weight person 2)
  	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs (weight person 3)
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as output (output)

  	unsigned short tmpA = 0x00;
	unsigned short tmpB = 0x00;
	unsigned short tmpC = 0x00;
	unsigned short tmpD = 0x00;
	unsigned short negA = 0x00;
  	while(1) {
    		// 1) Read input
    		tmpA = PINA & 0xFF;  
		tmpB = PINB & 0xFF;
		tmpC = PINC & 0xFF;

		negA = (~tmpA) + 0x01;     //retrieving the negative value of A for subtraction

    		// 2) Perform computation
    		if( (tmpA + tmpB + tmpC) > 0x8C){   //checks if total weight exceeds 140 kg
			tmpD = tmpD | 0x01;         //sets PD0 to 1 if it does
		}
		
		if( (abs(tmpC + negA)) > 0x50){     //check if the difference in weight A and C exceeds 80 kg
			tmpD = tmpD | 0x02;         //sets PD1 to 1 if it does
		}
		
		if( (tmpA + tmpB + tmpC) > 0x3F){  //if the total weight exceeds the max value of 6 bits (63)
			tmpD = tmpD | (0x3F << 2); //set D7-D2 to 1 or the max value of 6 bits 63)
		}
		else{
			tmpD = tmpD | ( (tmpA + tmpB + tmpC) << 2);
		}

    		// 3) write output
		PORTD = tmpD;
  	}
  	return 0;
}
