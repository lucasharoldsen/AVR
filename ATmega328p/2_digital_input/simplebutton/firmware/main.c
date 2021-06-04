                                                         

/*
simple code for listening to a digital input
*/


// ------- Preamble -------- //
#include <avr/io.h>            /* Defines pins, ports, etc */
#include <util/delay.h>        /* Functions to waste time */


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
//  -------------+ PD4   PC0 +--[BUTTON1]--
//  --VCC---(+)--+ VCC   GND +--(-)---GND--
//  --GND---(-)--+ GND  AREF +------------- 
//  -------------+ PB6  AVCC +-------------
//  -------------+ PB7   PB5 +-------------
//  -------------+ PD5   PB4 +-------------
//  -------------+ PD6   PB3 +------------- 
//  -------------+ PD7   PB2 +-------------
//  --[LED1]-----+ PB0   PB1 +------------- 
//               +-----------+
//              
// ------------------------------------------


int main(void) {

  // -------- Inits --------- //
  PORTC |= (1 << PC0);   // Set PortC0 pin with an internal pulldown resistor
  DDRB |= (1 << 0);      // Set first pin in PortB to output
  

  // ------ Event loop ------ //
  while (1) {

    if ((PINC & (1 << PC0)) == 0){    //alternative with macro--> if (bit_is_clear(PINC, PC0)) 
                                      //compare PINC value with a bitmask and see if it is equals to 0
      PORTB |= (1 << 0);              // output hight on PB0
    }
    else{
      PORTB &= ~(1 << 0);             //output low on PB0
    }

  }                              /* End event loop */
  return 0;
}


