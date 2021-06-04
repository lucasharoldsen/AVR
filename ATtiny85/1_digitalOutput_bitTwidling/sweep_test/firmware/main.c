// ------- Preamble -------- //

#include <avr/io.h>          //include the 
#include <util/delay.h>      //include utility for the delay function



// ------------------------------------------
//
//                 ATtiny85
//               +----------+  
//       (RST)---+ PB5  Vcc +---(+)--VCC--
//  --[LED4]-----+ PB3  PB2 +-----[LED3]--
//  --[LED5]-----+ PB4  PB1 +-----[LED2]--
//  -------(-)---+ GND  PB0 +-----[LED1]-- 
//               +----------+
//              
// ------------------------------------------


//-------- main loop --------//

int main(void){

// -------- Inits --------- //

DDRB = 0b00011111;     

// ------ Event loop ------ //
while (1) {

	PORTB = 0b00000001; //output HIGH to the 1st pin of Port B
	_delay_ms(500);     //delay 500 milli seconds

	PORTB = 0b00000000; //output LOW to the 1st pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

	PORTB = 0b00000010; //output LOW to the 2nd pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

	PORTB = 0b00000000; //output LOW to the 2nd pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

	PORTB = 0b00000100; //output LOW to the 3rd pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

	PORTB = 0b00000000; //output LOW to the 3rd pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

	PORTB = 0b00001000; //output LOW to the 4th pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

	PORTB = 0b00000000; //output LOW to the 4th pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

	PORTB = 0b00010000; //output LOW to the 5th pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

	PORTB = 0b00000000; //output LOW to the 5th pin of Port B
	_delay_ms(500);      //delay 500 milli seconds

    }
    return 0;   // never reached 
}
