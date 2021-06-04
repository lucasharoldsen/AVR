                                                         

/*
test of USART serial comunication 
Light 8 LED acording to the ASCII value of the letter typed in the terminal
*/


// ------- Preamble -------- //
#include <avr/io.h>            /* Defines pins, ports, etc */
#include <util/delay.h>        /* Functions to waste time */
#include "USART.h"
#define BUTTON_PIN     PINC
#define BUTTON_PORT    PORTC  
#define BUTTON         PC0
#define LED_PORT       PORTB
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


// -------- functions -------- //

static inline void blinkLED(void){
  LED_PORT = (1 << LED0);
  _delay_ms(1000);
  LED_PORT &= ~(1 << LED0);
}


int main(void) {

  // -------- Inits --------- //
  BUTTON_PORT |= (1 << BUTTON);
  LED_DDR = (1 << LED0);
  blinkLED();

  initUSART();
  transmitByte('O');

  

  // ------ Event loop ------ //
  while (1) {

    if (bit_is_clear(BUTTON_PIN, BUTTON)){
      transmitByte('X');
      blinkLED();
    }

  }                              /* End event loop */
  return 0;
}


