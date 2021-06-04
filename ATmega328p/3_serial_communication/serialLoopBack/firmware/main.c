                                                         

/*
test of USART serial comunication 
Light 8 LED acording to the ASCII value of the letter typed in the terminal
*/


// ------- Preamble -------- //
#include <avr/io.h>            /* Defines pins, ports, etc */
#include <util/delay.h>        /* Functions to waste time */
#include "USART.h"


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


int main(void) {

  char serialCharacter;

  // -------- Inits --------- //
  DDRB = 0xff;
  initUSART();
  printString("hello world\r\n");

  printString("DDRB = "); //Print "DDRB = (binary value of DDRB) "
  printBinaryByte(DDRB);
  printString("\r\n");
  

  // ------ Event loop ------ //
  while (1) {

    serialCharacter = receiveByte();
    transmitByte(serialCharacter);
    printString("\r\n");
    PORTB = serialCharacter;

  }                              /* End event loop */
  return 0;
}


