                                                         

/*
simple code for toggling output with digital input
*/


// ------- Preamble -------- //
#include <avr/io.h>                // Defines pins, ports, etc 
#define BUTTON_PIN     PINB   
#define BUTTON         PB4
#define LED_DDR        DDRB
#define LED0           PB0


int main(void) {

  // -------- Inits --------- //
  uint8_t buttonWasPressed;                   // variable for storing the button state 
  PORTB |= (1 << BUTTON);                     // Set PB4 pin with an internal pulldown resistor
  LED_DDR |= (1 << LED0);                     // Set first pin in PortB to output
  

  // ------ Event loop ------ //
  while (1) {

    if (bit_is_clear(BUTTON_PIN, BUTTON)){    //if button was pressed
      if (buttonWasPressed == 0){             //but was not last time
        PORTB ^= (1 << LED0);                 //toggle the PB0 pin
        buttonWasPressed = 1;                 //update the state
      }                               
                 
    }
    else{                                     //button is not pressed now
      buttonWasPressed = 0;                   //update the state
    }

  }                                           // End event loop
  return 0;
}


