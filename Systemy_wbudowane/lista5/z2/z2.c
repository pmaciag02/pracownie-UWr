#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // włącz odbiornik i nadajnik
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

// transmisja jednego znaku
int uart_transmit(char data, FILE *stream)
{
  // czekaj aż transmiter gotowy
  while(!(UCSR0A & _BV(UDRE0)));
  UDR0 = data;
  return 0;
}

// odczyt jednego znaku
int uart_receive(FILE *stream)
{
  // czekaj aż znak dostępny
  while (!(UCSR0A & _BV(RXC0)));
  return UDR0;
}

FILE uart_file;

// inicjalizacja ADC
void adc_init(){
  ADMUX   = _BV(REFS0); // referencja AVcc, wejście ADC0
  DIDR0   = _BV(ADC0D); // wyłącz wejście cyfrowe na ADC0
  // częstotliwość zegara ADC 125 kHz (16 MHz / 128)
  ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  ADCSRA |= _BV(ADEN); // włącz ADC
  ADCSRA |= _BV(ADATE) | _BV(ADIE); //Auto Trigger
  ADCSRB |= _BV(ADTS1); //INT0
}

void io_init()
{
  // ustaw pull-up na PD2 (INT0)
  PORTD |= _BV(PORTD2);
  // ustaw wyjście na PB5
//   DDRB |= _BV(DDB5);
  // ustaw wyzwalanie przerwania na INT0 zboczem narastającym
  EICRA |= _BV(ISC00) | _BV(ISC01);
  // odmaskuj przerwania dla INT0 i INT1
  EIMSK |= _BV(INT0);
}

volatile float ohm = 0;

ISR(INT0_vect){
  //   uint16_t v = ADC;
  // float u=(v*5.0)/1024.0;
  // ohm=u*10000.0/(5.0-u);
}
ISR(ADC_vect){
    // ADCSRA |= _BV(ADSC); // wykonaj konwersję
    // while (!(ADCSRA & _BV(ADIF))); // czekaj na wynik
    // ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)
  uint16_t v = ADC;
  float u = (v * 5.0) / 1024.0;
  ohm = u * 10000.0 / (5.0 - u);
  ohm /= 10;
}

int main(){
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // zainicjalizuj wejścia/wyjścia
  io_init();
  // zainicjalizuj ADC
  adc_init();
  // maska przerwan
  sei();
//   EICRA = _BV(ISC01) | _BV(ISC00);
//   EIMSK = _BV(INT0);
  while(1) {
    printf("%f\r\n", ohm);
    _delay_ms(100);
  }
}