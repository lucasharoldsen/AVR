                                                         

/*
simple code for toggling output with digital input
*/


// ------- Preamble -------- //
#define __DELAY_BACKWARD_COMPATIBLE__
#include <avr/io.h>                // Defines pins, ports, etc 
#include <util/delay.h>
#define LED_DDR        DDRB
#define LED_PORT      PORTB


// ------- Functions --------//

static inline void initADC0(void) {
  ADMUX |= (1 << REFS0);
  ADCSRA |= (1 << ADPS1) | (1 <<ADPS0);
  ADCSRA |= (1 << ADEN);
}


int main(void) {

  // -------- Inits --------- //
  uint8_t ledValue;                   // variable for storing the button state
  uint16_t adcValue;
  uint8_t i;

  initADC0();
  LED_DDR = (1 << 1); //| (1 << 1) | (1 << 2) | (1 << 3);

  // ------ Event loop ------ //
  while (1) {

   ADCSRA |= (1 << ADSC);
   //loop_until_bit_is_clear(ADCSRA, ADSC);
   adcValue = ADCH;

    PORTB |= (1 << 1);
    _delay_ms(adcValue);
    PORTB &= ~(1 << 1);
    _delay_ms(adcValue);

  }                                           // End event loop
  return (0);
}


