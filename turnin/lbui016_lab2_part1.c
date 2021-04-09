/*	Author: lbui016
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
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA0; // Temporary variable to hold the value of A
	unsigned char tmpA1;
    /* Insert your solution below */
    while (1) {
	/*tmpA = PINA & 0x01;
	if (tmpA == 0x01) {
		tmpB = (tmpB & 0xFC) | 0x01;
	} else {
		tmpB = (tmpB & 0xFC) | 0x02;
	}
	PORTB = tmpB;*/
	
	/*if ((tmpA1 == 0) && (tmpA0 == 0)) {
		tmpB = 0;
	}*/
 	tmpA0 = PINA & 0x01;
	tmpA1 = PINA & 0x02;
	
	if ((tmpA1 == 0) && (tmpA0 == 1)) {
		tmpB = 1;
	}
	else {
		tmpB = 0;
	}	
	PORTB = tmpB;
	/*if ((tmpA1 == 1) && (tmpA0 == 0)) {
		tmpB = 0;
	}*/

	/*if ((tmpA1 == 1) && (tmpA0 == 1)) {
		tmpB =0;
	}*/
 }  
 return 0;
}
