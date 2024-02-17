#include <avr/io.h>
#include <util/delay.h>

// #define LED1 PD0
// #define LED2 PD1
// #define LED3 PD2
// #define LED4 PD3
// #define LED5 PD4
// #define LED6 PD5
// #define LED7 PD6
// #define LED8 PD7
#define LED_DDR DDRD
#define LED_PORT PORTD

int main() {
    // UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);
  LED_DDR = 0xff; 
  
  LED_PORT = 0x00;
  
  while (1) {
    // LED_PORT = 0b00000001;
    // _delay_ms(100);

    for(int i = 0; i < 8; i++) {
      LED_PORT |= _BV(i);
      _delay_ms(100);
      LED_PORT &= ~_BV(i);
    }
    _delay_ms(100);
    for(int i = 6; i > 0; i--) {
      LED_PORT |= _BV(i);
      _delay_ms(100);
      LED_PORT &= ~_BV(i);
    }
    _delay_ms(100);

    // LED_PORT = 0b00000010;
    // _delay_ms(100);
    // LED_PORT = 0b00000100;
    // _delay_ms(100);
    // LED_PORT = 0b00001000;
    // _delay_ms(100);
    // LED_PORT = 0b00010000;
    // _delay_ms(100);
    // LED_PORT = 0b00100000;
    // _delay_ms(100);
    // LED_PORT = 0b01000000;
    // _delay_ms(100);
    // LED_PORT = 0b10000000;
    // _delay_ms(100);
    // LED_PORT = 0b01000000;
    // _delay_ms(100);
    // LED_PORT = 0b00100000;
    // _delay_ms(100);
    // LED_PORT = 0b00010000;
    // _delay_ms(100);
    // LED_PORT = 0b00001000;
    // _delay_ms(100);
    // LED_PORT = 0b00000100;
    // _delay_ms(100);
    // LED_PORT = 0b00000010;
    // _delay_ms(100);

    // LED_PORT |= _BV(LED1);
    // _delay_ms(1000);
    // LED_PORT &= ~_BV(LED1);

    // LED_PORT |= _BV(LED2);
    // _delay_ms(1000);
    // LED_PORT &= ~_BV(LED2);

    // LED_PORT |= _BV(LED3);
    // _delay_ms(1000);
    // LED_PORT &= ~_BV(LED3);

    // LED_PORT |= _BV(LED4);
    // _delay_ms(1000);
    // LED_PORT &= ~_BV(LED4);

    // LED_PORT |= _BV(LED5);
    // _delay_ms(1000);
    // LED_PORT &= ~_BV(LED5);

    // LED_PORT |= _BV(LED6);
    // _delay_ms(1000);
    // LED_PORT &= ~_BV(LED6);

    // LED_PORT |= _BV(LED7);
    // _delay_ms(1000);
    // LED_PORT &= ~_BV(LED7);

    // LED_PORT |= _BV(LED8);
    // _delay_ms(1000);
    // LED_PORT &= ~_BV(LED8);
    // _delay_ms(1000);
  }
}
