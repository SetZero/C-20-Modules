module;
#include <avr/interrupt.h>
#include <avr/boot.h>
#include <util/delay.h>
module Loader;

void initBootloader() {
    uint8_t sregtemp = SREG;
    cli();
    interruptVar = MCUCR;
    MCUCR = interruptVar | (1<<IVCE);
    MCUCR = interruptVar | (1<<IVSEL);
    SREG = sregtemp;

    sei();
}

void endBootloader() {
    cli();
    interruptVar = MCUCR;
    MCUCR = interruptVar | (1<<IVCE);
    MCUCR = interruptVar & ~(1<<IVSEL);

    start();
}