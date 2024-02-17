#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR DDRD
#define LED_PORT PORTD
#define TRANS_DDR DDRC
#define TRANS_PORT PORTC


char numbers[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xBF};



void next_number(int8_t digit, int8_t trans) {
    LED_PORT = numbers[digit];
    TRANS_PORT &= ~_BV(trans);

    _delay_ms(5);

    LED_PORT = 0xFF;
    TRANS_PORT |= _BV(trans);
}




int main(void)
{
    UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);

    LED_DDR = 0xFF;
    LED_PORT = 0xFF;
    TRANS_DDR |= 0b00000011;
    TRANS_PORT |= 0b00000011;

    int8_t number = 0 , tens = 0, units = 0;

    while(1) {
        if (number > 60) number = 0;
        tens = number / 10;
        units = number - tens * 10;
        
        for (int8_t i = 0; i < 100; i++) {
            if (tens > 0) {
                next_number(tens, 0);
            }
            else {
                _delay_ms(5);
            }
            next_number(units, 1);
        }
        number++;
    }
}