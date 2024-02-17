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



void adc_init()
{
  ADMUX   = _BV(REFS0) | 0b1110; // referencja AVcc, wejście ADC0
  // DIDR0   = _BV(ADC0D); // wyłącz wejście cyfrowe na ADC0
  // częstotliwość zegara ADC 125 kHz (16 MHz / 128)
  ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  ADCSRA |= _BV(ADEN); // włącz ADC
}


volatile float arr1[100], arr2[100];
volatile uint8_t j = 0;

ISR(ADC_vect){
  uint16_t v = ADC;
  float vref = 1.1 * 1023 / v;
  j++;
  arr2[j] = vref;
}


int main(){
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // zainicjalizuj ADC
 
  adc_init();
  
  for (int i = 0; i < 64; i++){
    ADCSRA |= _BV(ADSC); // wykonaj konwersję
    while (!(ADCSRA & _BV(ADIF))); // czekaj na wynik
    ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)
    uint16_t v = ADC; // weź zmierzoną i zmień do zbioru (0..1023)
    float vref = 1.1 * 1023 / v;
    arr1[i] = vref;
  }
  ADCSRA |= _BV(ADIE);
  // ADCSRA |= _BV(ADATE) | _BV(ADIE);
  sei();
  
  set_sleep_mode(SLEEP_MODE_ADC);
// SMCR = _BV(SM0);
  for (int i = 0; i < 64; i++) {
    sleep_mode();
    // printf("%d\r\n", i);
  }
  // sleep_disable();
  cli(); 

  float sum1 = 0, sum2 = 0, w1 = 0, w2 = 0;
  
  for (int i = 0; i < 64; i++) {
    sum1 += arr1[i];
    sum2 += arr2[i];
  }
  sum1 /= 64.0;
  sum2 /= 64.0;

  for (int i = 0; i < 64; i++) {
    w1 += (sum1 - arr1[i]) * (sum1 - arr1[i]);
    w2 += (sum2 - arr2[i]) * (sum2 - arr2[i]);
  }
  w1 /= 64.0;
  w2 /= 64.0;

  printf("%f %f\r\n", w1, w2);
  
  while(1) {
  }
}