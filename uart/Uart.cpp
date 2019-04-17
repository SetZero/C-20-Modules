module;
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/boot.h>
#include <util/delay.h>
export module Uart;

[[nodiscard]] constexpr auto ubbr_val(auto baudrate) {
    return (F_CPU+baudrate*8)/(baudrate*16)-1;
}

export void uart_init(auto baudrate);
export int uart_putc(unsigned char c);
export void uart_puts (const char *s);