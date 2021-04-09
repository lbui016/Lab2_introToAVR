/*	Author: Liam Bui
 *  Partner(s) Name: 
 *	Lab Section:
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
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
    /* Insert your solution below */
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char totalWeight = 0x00;
	signed char difference = 0x00;
    while (1) {
	tmpA = PINA; // seat A
	tmpB = PINB; // seat B
	tmpC = PINC; // seat C
	totalWeight = 0x00;
	tmpD = 0x00;
	//difference = 0x00;
	
	totalWeight = tmpA + tmpB + tmpC; //total weight of the seats

	//difference of weight between A and C
	if (tmpA > tmpC) {
		difference = tmpA - tmpC; //to account for possible negative value
	}
	else {
		difference = tmpC - tmpA;
	}

	if (totalWeight > 140) {
		tmpD = tmpD | 0x01; //sets port PD0 to 1 if the cart's total passenger weight exceeds the max of 140 kg
	}

	totalWeight = totalWeight >> 2; //shifts totalWeight to get rid of least significant bits
	//totalWeight = totalWeight << 2;

	if (difference > 80) {
		tmpD = tmpD | 0x02; //sets port PD1 to 1 if the difference between A and C exceeds 80 kg, leaving PD0 alone
	}
	
	tmpD = totalWeight | tmpD; //ORs totalWeight and tmpD to get final solution
	PORTD = tmpD;
 }  
 return 0;
}
