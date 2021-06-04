#include <avr/io.h>
#include <util/delay.h>



void delay_ms(int d)
{
    int i;
    for (i = 0; i < d; i++) {
        _delay_ms(1);
    }
}


int main() {

    _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0); // set to 20Mhz (assuming fuse 0x02 is set to 2)

    PORTB.DIRSET = (1 << 2); //PB2 to output
    uint8_t i;


    while (1) {
        
        for (i = 1; i < 200; i = i + 5){
            PORTB.OUTSET = (1 << 2);
            delay_ms(200);
            PORTB.OUTCLR = (1 << 2);
            delay_ms(i);
        }
        
        
    }
    return(0);
}
