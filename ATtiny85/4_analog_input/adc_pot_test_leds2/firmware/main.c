                                                         

/*
simple code for toggling output with digital input
*/


// ------- Preamble -------- //
#define __DELAY_BACKWARD_COMPATIBLE__
#include <avr/io.h>                // Defines pins, ports, etc 
#include <util/delay.h>
#define LED_DDR        DDRB
//#define LED_PORT      PORTB



// ------------------------------------------
//
//                 ATtiny85
//               +----------+  
//       (RST)---+ PB5  Vcc +---(+)--VCC--
//  --[LED4]-----+ PB3  PB2 +-----[LED3]--
//  --[LED5]-----+ PB4  PB1 +-----[LED2]--
//  -------(-)---+ GND  PB0 +-----[LED1]-- 
//               +----------+
//              
// ------------------------------------------


// ------- Functions --------//
static inline void initADC (void)
{
ADMUX =  (0 << REFS1) |     //use external voltage reference VCC to PB0
         (0 << MUX3)  |     // use ADC2 for input (PB4), MUX bit 0
         (0 << MUX2)  |     // use ADC2 for input (PB4), MUX bit 0
         (1 << MUX1)  |     // use ADC2 for input (PB4), MUX bit 1
         (0 << MUX0)  |     // use ADC2 for input (PB4), MUX bit 0
         (1 << ADLAR);      //Left Adjust the ADCH and ADCL registers

ADCSRA = (1 << ADEN)  |
         (1 << ADPS1) |     //with next line…
         (1 << ADPS0);     //set division factor-8 for 125kHz ADC clock

}


int main(void) {

// -------- Inits --------- //
  initADC();
  
  LED_DDR = (1 << 1)   | 
            (1 << 2)   | 
            (1 << 3); 
            //(1 << 4);


  // ------ Event loop ------ //
  while (1) {

   ADCSRA |= (1 << ADSC); // start ADC measurement
   loop_until_bit_is_clear(ADCSRA, ADSC);
   
  if (ADCH > 50){
    PORTB |= (1 << PB1);
  }

 if (ADCH > 100){
     PORTB |= (1 << PB2);
  } 

 if (ADCH > 189){
     PORTB |= (1 << PB3);
   }

 if (ADCH <= 50) {
     PORTB &= ~(1 << PB1);
     PORTB &= ~(1 << PB2);
     PORTB &= ~(1 << PB3);
  }
  }                                           // End event loop
  return (0);
}


