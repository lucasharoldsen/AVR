// ------- Preamble -------- //

#include <avr/io.h>          //include the 
#include <util/delay.h>      //include utility for the delay function


// ------------------------------------------
//
//                 ATmega328p
//
//               +-----------+  
//  ---(RST)-----+ PC6   PC5 +-------------
//  ----(RX)-----+ PD0   PC4 +-------------
//  ----(TX)-----+ PD1   PC3 +-------------
//  -------------+ PD2   PC2 +------------- 
//  -------------+ PD3   PC1 +-------------
//  -------------+ PD4   PC0 +-------------
//  --VCC---(+)--+ VCC   GND +--(-)---GND--
//  --GND---(-)--+ GND  AREF +------------- 
//  --[LED7]-----+ PB6  AVCC +-------------
//  --[LED8]-----+ PB7   PB5 +-----[LED6]--
//  -------------+ PD5   PB4 +-----[LED5]--
//  -------------+ PD6   PB3 +-----[LED4]-- 
//  -------------+ PD7   PB2 +-----[LED3]--
//  --[LED1]-----+ PB0   PB1 +-----[LED2]-- 
//               +-----------+
//              
// ------------------------------------------

//-------- functions --------//

void flashLED(uint8_t oneByte) {
	PORTB = oneByte;
	_delay_ms(200);
	PORTB = 0b00000000;
	_delay_ms(200);
}


//-------- main loop --------//

int main(void){

// -------- Inits --------- //

DDRB = 0xff; //DDRB = 0b11111111;

// ------ Event loop ------ //
while (1) {

	flashLED(0b00000001);
	flashLED(0b00000010);
	flashLED(0b00000100);
	flashLED(0b00001000);
	flashLED(0b00010000);
	flashLED(0b00100000);
	flashLED(0b01000000);
	flashLED(0b10000000);

    }
    return 0;   // never reached 
}
