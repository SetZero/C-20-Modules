
#include <avr/io.h>
#include <util/delay.h>
import Loader;

int main() {
    initBootloader();
    endBootloader();
    while(true) {
        _delay_ms(1000/8);
    }
}