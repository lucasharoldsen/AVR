// ATtiny85 chirper experiment 
// Lucas Yasunaga (yasunaga.work) (electronicentomology.com)
// Code is ased on a book "MAKE: AVR Programming" by Elliot Wiliams
// 04/15/2020


// ------- Preamble -------- //
#define __DELAY_BACKWARD_COMPATIBLE__ //this enables _delay function to be able to take variable
#include <avr/io.h>
#include <util/delay.h>               /* Functions to waste time */
                                
#define LED_PORT                PORTB
#define LED_DDR                 DDRB

int main(void) {

  // ------ init ------//
  uint8_t i; //declare the variable i
  uint16_t randomNumber = 0x1234; 
  LED_DDR |= (1 << 4); //configure DDRB pin 4 to output   


  // ------ Event loop ------ //
  while (1) {

    randomNumber = 2053 * randomNumber + 13849;

    for (i = 1; i < 200; i += 10 ){                                
      LED_PORT |= (1 << 4);                   
      _delay_us(i);
      LED_PORT &= ~(1 << 4);
      _delay_us(i);
    }
                                 
    _delay_ms(randomNumber);

  }                                                  /* End event loop */
  return 0;                            /* This line is never reached */
}
