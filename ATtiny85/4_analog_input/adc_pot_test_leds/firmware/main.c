                                                         

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



int main(void) {

// -------- Inits --------- //
  ADMUX |= (1 << REFS1); //use internal voltage reference of 1.1V
  ADMUX |= (1 << MUX0); //ADC1 PB2
  //ADMUX |= (1 << MUX1); //Chosing alalog input pin. Analog channel selection but of (1,1) makes ADC3
  ADMUX |= (1 << ADLAR);   //Left Adjust the ADCH and ADCL registers
  //also can be written as 
  //ADMUX = 0b01100011;
  ADCSRA |= (1 << ADEN);   //enables the ADC
  ADCSRA |= (1 << ADPS1);   //with next line…
  ADCSRA |= (1 << ADPS0);   //set division factor-8 for 125kHz ADC clock
  //also can be written as 
  //ADCSRA = 0b10000011;
  
  LED_DDR = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 4);
  

  uint8_t ledValue;
  uint16_t analogData;
  uint8_t i;

  // ------ Event loop ------ //
  while (1) {

   ADCSRA |= (1 << ADSC);
   loop_until_bit_is_clear(ADCSRA, ADSC);
   analogData = ADC;
   
   ledValue = (analogData >> 8);
   LED_PORT &= ~(1 << 0);
   LED_PORT &= ~(1 << 1);
   LED_PORT &= ~(1 << 2);
   LED_PORT &= ~(1 << 3);

   for (i = 0; i <= ledValue; i++){
    LED_PORT |= (1 << i);
   }
   _delay_ms(50);
  }                                           // End event loop
  return (0);
}


