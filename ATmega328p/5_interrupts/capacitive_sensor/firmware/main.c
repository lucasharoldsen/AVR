                                                         

/*
Interrupt Button
*/


// ------- Preamble -------- //
#include <avr/io.h>            /* Defines pins, ports, etc */
#include <util/delay.h>        /* Functions to waste time */
#include <avr/interrupt.h>
#include <avr/power.h>
#include "USART.h"


#define SENSE_TIME          20
#define THRESHOLD           2700
#define CAP_SENSOR_DDR      DDRC
#define CAP_SENSOR          PC3
#define CAP_SENSOR_PORT     PORTC
#define LED_DDR             DDRB
#define LED_PORT            PORTB


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

// ---- Global Varialble ----//

volatile uint16_t chargeCycleCount;

// ------- Functions --------//

ISR(PCINT1_vect){
  chargeCycleCount++; 

  CAP_SENSOR_DDR |= (1 << CAP_SENSOR); //set cap senseor pin to output mode
  _delay_us(1);

  CAP_SENSOR_DDR &= ~(1 << CAP_SENSOR);
  PCIFR |= (1 << PCIF1);


}


void initPinChangeInterrupt(void) {
  PCICR |= (1 << PCIE1);    //enable pin-change interrupts 1 (bank C)
  PCMSK1 |= (1 << PC3);     //pin mask to enable specific interrupt - PC1
}



int main(void) {

  // -------- Inits --------- //

  clock_prescale_set(clock_div_1);
  initUSART();
  printString("------CAP_SENSOR------\r\n\r\n");


  LED_DDR = 0xff;
  MCUCR |= (1 << PUD);
  CAP_SENSOR_PORT |= (1 << CAP_SENSOR);

  initPinChangeInterrupt();

  // ------ Event loop ------ //

  while (1) {

   chargeCycleCount = 0;
   CAP_SENSOR_DDR |= (1 << CAP_SENSOR);
   
   sei();
   _delay_ms(SENSE_TIME);
   cli();
   if (chargeCycleCount < THRESHOLD) {
    LED_PORT = 0xff;
   }
   else{
    LED_PORT = 0;
   }
   printWord(chargeCycleCount);
   printString("\r\n");
 
  }                                           // End event loop
  return (0);
}


