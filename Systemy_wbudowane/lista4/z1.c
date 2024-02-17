#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <inttypes.h>

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

int main(){
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;

  TCCR1B = _BV(CS10); // inicjowanie podzielnika zegara, samo zliczanie
  //Timer/Counter Control Register
//Źródło zegara jest wybierane przez Clock Select, który jest kontrolowany przez bity Clock Select znajdujące się w rejestrze sterującym Timer/Counter Control Regis B (TCCR1B). 

  volatile uint8_t A, a;
  volatile uint16_t B, b;
  volatile uint32_t C, c;
  volatile uint64_t D, d;
  volatile float F, f;

  TCNT1 = 0;
  A = a + a;
  uint16_t a1 = TCNT1;
  TCNT1 = 0;
  A = a * a;
  uint16_t a2 = TCNT1;
  TCNT1 = 0;
  A = a / a;
  uint16_t a3 = TCNT1;
  printf("uint8_t: add %"PRIu16", mult %"PRIu16", div %"PRIu16", cycles\r\n", a1, a2, a3);

  TCNT1 = 0;
  B = b + b;
  uint16_t b1 = TCNT1;
  TCNT1 = 0;
  B = b * b;
  uint16_t b2 = TCNT1;
  TCNT1 = 0;
  B = b / b;
  uint16_t b3 = TCNT1;
  printf("uint16_t: add %"PRIu16", mult %"PRIu16", div %"PRIu16", cycles\r\n", b1, b2, b3);

  TCNT1=0;
  C= c + c;
  uint16_t c1 = TCNT1;
  TCNT1 = 0;
  C = c * c;
  uint16_t c2 = TCNT1;
  TCNT1 = 0;
  C = c / c;
  uint16_t c3 = TCNT1;
  printf("uint32_t: add %"PRIu16", mult %"PRIu16", div %"PRIu16", cycles\r\n", c1, c2, c3);

  TCNT1 = 0;
  D = d + d;
  uint16_t d1= TCNT1;
  TCNT1 = 0;
  D= d * d;
  uint16_t d2 = TCNT1;
  TCNT1 = 0;
  D = d / d;
  uint16_t d3 = TCNT1;
  printf("uint64_t: add %"PRIu16", mult %"PRIu16", div %"PRIu16", cycles\r\n", d1, d2, d3);

  TCNT1=0;
  F = f + f;
  uint16_t f1 = TCNT1;
  TCNT1 = 0;
  F = f * f;
  uint16_t f2 = TCNT1;
  TCNT1 = 0;
  F = f / f;
  uint16_t f3 = TCNT1;
  printf("float: add %"PRIu16", mult %"PRIu16", div %"PRIu16", cycles\r\n", f1, f2, f3);
 
  while(1) {
  }
}