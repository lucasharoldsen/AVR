/**
 * \file simavr.c
 *
 * This file describdes traces for simavr to collect. The metadata is stored in 
 * the .mmcu section of the compiled ELF binary.
 */
#include <stdlib.h>
#include "avr_mcu_section.h"


/** Trace data to collect.
 *
 * We collect each bit of PORTB (inputs and outputs) separately. We also keep
 * track of the global state variable.
 */
const struct avr_mmcu_vcd_trace_t _mytrace[]  _MMCU_ = {
    { AVR_MCU_VCD_SYMBOL("PORTB0"),    .mask = (1<<PB0),    .what = (void*)&PORTB,  },
    { AVR_MCU_VCD_SYMBOL("PORTB1"),      .mask = (1<<PB1),      .what = (void*)&PORTB,  },
    { AVR_MCU_VCD_SYMBOL("PORTB2"),      .mask = (1<<PB2),      .what = (void*)&PORTB,  },
    { AVR_MCU_VCD_SYMBOL("PORTB3"),      .mask = (1<<PB3),      .what = (void*)&PORTB,  },
   
};
