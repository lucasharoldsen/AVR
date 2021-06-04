                                                         

/*
simple code for toggling output with digital input
*/


// ------- Preamble -------- //
#include <avr/io.h>                // Defines pins, ports, etc 
#define BUTTON_PIN     PINC
#define BUTTON         PC0
#define LED_DDR        DDRB
#define LED0           PB0


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
  uint8_t buttonWasPressed;                   // variable for storing the button state 
  PORTC |= (1 << BUTTON);                     // Set PC0 pin with an internal pulldown resistor
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


