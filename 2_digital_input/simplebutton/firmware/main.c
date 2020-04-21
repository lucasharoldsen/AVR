                                                         

/*
simple code for listening to a digital input
*/


// ------- Preamble -------- //
#include <avr/io.h>            /* Defines pins, ports, etc */
#include <util/delay.h>        /* Functions to waste time */


int main(void) {

  // -------- Inits --------- //
  PORTB |= (1 << PB4);   // Set PortB4 pin with an internal pulldown resistor
  DDRB |= (1 << 0);      // Set first pin in PortB to output
  

  // ------ Event loop ------ //
  while (1) {

    if ((PINB & (1 << PB4)) == 0){    //alternative with macro--> if (bit_is_clear(PINB, PB4)) 
                                      //compare PINB value with a bitmask and see if it is equals to 0
      PORTB |= (1 << 0);              // output hight on PB0
    }
    else{
      PORTB &= ~(1 << 0);             //output low on PB0
    }

  }                              /* End event loop */
  return 0;
}


