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

    uart_init(9600);
    sei();

    uart_puts("Hallo hier ist der Bootloader\n\r");
    _delay_ms(1000);
}

void endBootloader() {
    cli();
    interruptVar = MCUCR;
    MCUCR = interruptVar | (1<<IVCE);
    MCUCR = interruptVar & ~(1<<IVSEL);

    start();
}