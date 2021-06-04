// ------- Preamble -------- //

#include <avr/io.h>          //include the 
#include <util/delay.h>      //include utility for the delay function

//-------- main loop --------//

int main(void){

// -------- Inits --------- //
// DDRB = 0b00001000;  //setting DDRB 4th pin to high (PinMode on arduino) configure it for the output
DDRB|= (1 << PB3);     // DDRB = DDRB | (1 << PB3) shift bit to location of the pin we want and OR them to turn the PB3 pin


// ------ Event loop ------ //
while (1) {

	PORTB = 0b00001000; //output HIGH to the 4th pin of Port B
	_delay_ms(500);     //delay 500 milli seconds

	PORTB = 0b00000000; //output LOW to the 4th pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

    }
    return 0;   // never reached 
}
