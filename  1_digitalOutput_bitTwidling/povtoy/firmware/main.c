/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>


//main loop 

void POVDisplay(uint8_t oneByte){
	PORTB = oneByte;
	_delay_ms(4);
}



int main(void){
//initializing
// DDRB = 0b00001000;
DDRB= 0xff;

while (1) {

	POVDisplay(0b00000100);
	POVDisplay(0b00000100);
	POVDisplay(0b00001010);
	POVDisplay(0b00001010);
	POVDisplay(0b00010001);
	POVDisplay(0b00010001);
	POVDisplay(0b00011111);
	POVDisplay(0b00011111);
	POVDisplay(0b00010001);
	POVDisplay(0b00010001);
	POVDisplay(0b00010001);
	POVDisplay(0b00010001);


	

	PORTB = 0;
	_delay_ms(20);

    }
    return 0;   /* never reached */
}
