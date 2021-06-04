                                                         

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
  ADMUX |= (1 << MUX0); 
  //ADMUX |= (1 << MUX1); //Chosing alalog input pin. Analog channel selection but of (1,1) makes ADC3
  ADMUX |= (1 << ADLAR);   //Left Adjust the ADCH and ADCL registers
  //also can be written as 
  //ADMUX = 0b01100011;
  ADCSRA |= (1 << ADEN);   //enables the ADC
  ADCSRA |= (1 << ADPS1);   //with next line…
  ADCSRA |= (1 << ADPS0);   //set division factor-8 for 125kHz ADC clock
  //also can be written as 
  //ADCSRA = 0b10000011;
  
  LED_DDR = (1 << 1);
  

  
  uint8_t analogData;

  // ------ Event loop ------ //
  while (1) {

   ADCSRA |= (1 << ADSC);
   
   analogData = ADCH;
   

    PORTB |= (1 << 1);
    _delay_ms(analogData);
    PORTB &= ~(1 << 1);
    _delay_ms(analogData);

  }                                           // End event loop
  return (0);
}


