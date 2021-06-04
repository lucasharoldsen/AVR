                                                         

/*
Interrupt Button
*/


// ------- Preamble -------- //
#include <avr/io.h>            /* Defines pins, ports, etc */
#include <util/delay.h>        /* Functions to waste time */
#include <avr/interrupt.h>

#define LED_PORT     PORTB
#define LED0         PB0
#define LED1         PB1
#define LED_DDR      DDRB
#define BUTTON_PORT  PORTD
#define BUTTON_PIN   PIND
#define BUTTON       PD2

// ------------------------------------------
//
//                 ATmega328p
//
//               +-----------+  
//  ---(RST)-----+ PC6   PC5 +-------------
//  ----(RX)-----+ PD0   PC4 +-------------
//  ----(TX)-----+ PD1   PC3 +-------------
//  --[INT0]-----+ PD2   PC2 +------------- 
//  -------------+ PD3   PC1 +-------------
//  -------------+ PD4   PC0 +-------------
//  --VCC---(+)--+ VCC   GND +--(-)---GND--
//  --GND---(-)--+ GND  AREF +------------- 
//  -------------+ PB6  AVCC +-------------
//  -------------+ PB7   PB5 +------------- 
//  -------------+ PD5   PB4 +------------- 
//  -------------+ PD6   PB3 +-------------  
//  -------------+ PD7   PB2 +------------- 
//  --[LED0]-----+ PB0   PB1 +-----[LED1]-- 
//               +-----------+
//              
// ------------------------------------------


// ------- Functions --------//

ISR(INT0_vect){
  if(bit_is_clear(BUTTON_PIN, BUTTON)){
    LED_PORT |= (1 << LED0);
  }else{
    LED_PORT &= ~(1 << LED0);
  }
}


void initInterrupt0(void) {
  EIMSK |= (1 << INT0);    //EIMSK – External Interrupt Mask Register  --> enable INT0
  EICRA |= (1 << ISC00);  //EICRA – External Interrupt Control Register A
 // EICRA |= (0 << ISC01);   //Any logical change on INT0 generates an interrupt request
  sei();
}



int main(void) {

  // -------- Inits --------- //

  LED_DDR = 0xff;
  BUTTON_PORT |= (1 << BUTTON);
  initInterrupt0();

  // ------ Event loop ------ //
  while (1) {

   _delay_ms(500);
   LED_PORT ^= (1 << LED1);
 
  }                                           // End event loop
  return (0);
}


