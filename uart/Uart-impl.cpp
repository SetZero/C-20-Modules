module;
#include <avr/interrupt.h>
#include <avr/boot.h>
#include <util/delay.h>
module Uart;

void uart_init(auto baudrate)
{
    UBRR0 = ubbr_val(baudrate);
    UCSR0B |= (1<<TXEN0);
    // Frame Format: Asynchron 8N1
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

int uart_putc(unsigned char c)
{
    while (!(UCSR0A & (1<<UDRE0))) { }

    UDR0 = c;                      /* sende Zeichen */
    return 0;
}

void uart_puts (const char *s)
{
    while (*s) {
        uart_putc(*s);
        s++;
    }
}