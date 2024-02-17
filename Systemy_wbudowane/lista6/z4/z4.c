#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

void spi_init(){
    // ustaw piny MOSI, SCK i ~SS jako wyjścia
    DDRB |= _BV(DDB3) | _BV(DDB5) | _BV(DDB2);
    // DDRB |= _BV(PB1) | _BV(PB5) | _BV(PB2) | _BV(PB3);
    // włącz SPI w trybie master z zegarem 250 kHz
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR1);
}

// transfer jednego bajtu
uint8_t spi_transfer(uint8_t data){
    // rozpocznij transmisję
    SPDR = data;
    // czekaj na ukończenie transmisji
    while (!(SPSR & _BV(SPIF)));
    // wyczyść flagę przerwania
    SPSR |= _BV(SPIF);
    // zwróć otrzymane dane
    return SPDR;
}

int8_t numbers[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xBF};


int main(){
  // zainicjalizuj SPI
  spi_init();
  DDRB |= _BV(PB1) | _BV(PB2);
  uint8_t i=0;
  PORTB &= ~_BV(PB2);

  while(1) {
    PORTB &= ~_BV(PB1);
    spi_transfer(~numbers[i]);
    _delay_ms(1000);
    PORTB |= _BV(PB1);

    i++;
    if (i>=10) {
        i-=10;
    }
  }
}