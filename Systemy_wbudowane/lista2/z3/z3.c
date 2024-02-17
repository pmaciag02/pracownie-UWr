#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR DDRD
#define LED_PORT PORTD

#define BTN_DDR DDRC
#define BTN_PORT PORTC
#define BTN_PIN PINC

#define BTN1 0
#define BTN2 1
#define BTN3 2

to_Gray(uint8_t number) {
  LED_PORT = number ^ (number >> 1);
}

int main()
{
  UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);

  LED_DDR = 0xFF;
  LED_PORT = 0;
  BTN_DDR = 0b11111000;
  BTN_PORT = 0b00000111;

  uint8_t i = 0;

  while(1) {
    //kolejny kod
    if (!(BTN_PIN & _BV(BTN1))){
      i++;
      if (i > 15) {
        LED_PORT = 0;
        i = 0;
      }
      while (!(BTN_PIN & _BV(BTN1)))
      {
        _delay_ms(10);
      }
      
    }
    //poprzedni kod
    if (!(BTN_PIN & _BV(BTN2))){
      i--;
      if (i < 0) i = 0;
      while (!(BTN_PIN & _BV(BTN2)))
      {
        _delay_ms(10);
      }
    } 
    //resetowanie kodu
    if (!(BTN_PIN & _BV(BTN3))){
      i = 0;
      while (!(BTN_PIN & _BV(BTN3)))
      {
        _delay_ms(10);
      }
    } 

    to_Gray(i);
  }
}