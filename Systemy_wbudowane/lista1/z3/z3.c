#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);

DDRD = 0xFF;

char numbers[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xBF};
while(1) {
    for (int i = 0; i <= 9; i++) {
        PORTD = numbers[i];
        _delay_ms(1000);
    }
}
}
