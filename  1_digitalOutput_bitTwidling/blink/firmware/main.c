/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>


//main loop 

int main(void){
//initializing
// DDRB = 0b00001000;
DDRB|= (1 << PB3);

while (1) {

	PORTB = 0b00001000;
	_delay_ms(500);

	PORTB = 0b00000000;
	_delay_ms(500);

    }
    return 0;   /* never reached */
}
