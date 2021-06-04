#include <avr/io.h>
#include <util/delay.h>

int main() {
    _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0); // set to 20Mhz (assuming fuse 0x02 is set to 2)

    PORTB.DIRSET = 0b00000010; //PB1 to output

    while (1) {
        PORTB.OUTSET = 0b00000010; //PB1 high
        _delay_ms(10);
        PORTB.OUTCLR = 0b00000010; //PB1 Low 
        _delay_ms(1000);
    }
    return(0);
}
