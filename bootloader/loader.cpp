module;
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/boot.h>
#include <util/delay.h>
export module Loader;
import Uart;

char interruptVar = 0;
bool running = true;
void (*start)( void ) = 0x0000;

export void initBootloader();
export void endBootloader();
