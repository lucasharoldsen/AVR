                                                         

/*
ADC scope
*/


// ------- Preamble -------- //
#include <avr/io.h>            /* Defines pins, ports, etc */
#include <util/delay.h>        /* Functions to waste time */
#include "USART.h"

#define SAMPLE_DELAY   20

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
//  -------------+ PD4   PC0 +-----[POT]---
//  --VCC---(+)--+ VCC   GND +--(-)---GND--
//  --GND---(-)--+ GND  AREF +--(+)---VCC-- 
//  --[LED7]-----+ PB6  AVCC +-------------
//  --[LED8]-----+ PB7   PB5 +-----[LED6]-- 
//  -------------+ PD5   PB4 +-----[LED5]-- 
//  -------------+ PD6   PB3 +-----[LED4]--  
//  -------------+ PD7   PB2 +-----[LED3]-- 
//  --[LED1]-----+ PB0   PB1 +-----[LED2]-- 
//               +-----------+
//              
// ------------------------------------------


// ------- Functions --------//
static inline void initADC (void)
{
ADMUX =  (0 << REFS0) |
         (0 << REFS1) |     //use external voltage reference from AREF
         (0 << MUX3)  |     // use ADC0 for input (PC0), MUX bit 0
         (0 << MUX2)  |     // use ADC0 for input (PC0), MUX bit 0
         (0 << MUX1)  |     // use ADC0 for input (PC0), MUX bit 1
         (0 << MUX0)  |    // use ADC0 for input (PC0), MUX bit 0
         (1 << ADLAR);      //Left Adjust the ADCH and ADCL registers

ADCSRA = (1 << ADEN)  |
         (1 << ADPS1) |     //with next line…
         (1 << ADPS0) |     //set division factor-8 for 125kHz ADC clock
         (1 << ADATE) |     //auto trigger enabled
         (1 << ADSC);

}


int main(void) {

  // -------- Inits --------- //

  initUSART();
  initADC();

  // ------ Event loop ------ //
  while (1) {

   transmitByte(ADCH);
   _delay_ms(SAMPLE_DELAY);
 
  }                                           // End event loop
  return (0);
}


