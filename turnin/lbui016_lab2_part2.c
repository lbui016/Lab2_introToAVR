/*	Author: Liam Bui
 *  Partner(s) Name: 
 *	Lab Section:
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
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
    /* Insert your solution below */
	unsigned char tmpA = 0x00;
	unsigned char cntavail = 0x00;
    while (1) {
	cntavail = 0x00;
	tmpA = PINA; //read in PINA's value to tmpA
	tmpA = tmpA & 0x0F; //bit-mask to only get A3-A0

	unsigned char i = 0;
	
	for (i = 0; i < 4; ++i) {
		if ((tmpA & 0x01) == 0x00) {
			cntavail = cntavail + 1;
		}
		//checks the leftmost bit for available space
		tmpA = tmpA >> 1; //shifts to next parking space to check
	}
	PORTC = cntavail;
 }  
 return 0;
}
