#include <avr/io.h>
#include <util/delay.h>



void ticking(uint8_t time){
	PORTB.OUTSET = (1 << 2);
	_delay_ms(100);
	PORTB.OUTCLR = (1 << 2);
	_delay_ms(time);
}

int main() {
    _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0); // set to 20Mhz (assuming fuse 0x02 is set to 2)

    PORTB.DIRSET = (1 << 2); //PB2 to output

    while (1) {
        
        ticking(1);
        ticking(3);
        ticking(7);
        ticking(10);
        ticking(100);
        
        
    }
    return(0);
}
