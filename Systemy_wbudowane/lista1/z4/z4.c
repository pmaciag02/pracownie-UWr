#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // wyczyść rejestr UCSR0A
  UCSR0A = 0;
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

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // program testowy
  printf("Hello world!\r\n");

    // int8_t a, b;
    // scanf("%"SCNd8 "%"SCNd8, &a, &b);
    // printf("dodawanie: %"PRId8", mnożenie: %"PRId8", dzielenie: %"PRId8"\r\n", a + b, a * b, a / b);

    // int16_t c, d;
    // scanf("%"SCNd16 "%"SCNd16, &c, &d);
    // printf("dodawanie: %"PRId16", mnożenie: %"PRId16", dzielenie: %"PRId16"\r\n", c + d, c * d, c / d);

    // int32_t e, f;
    // scanf("%"SCNd32 "%"SCNd32 , &e, &f);
    // printf("dodawanie: %"PRId32", mnożenie: %"PRId32", dzielenie: %"PRId32"\r\n", e + f, e * f, e / f);

    int64_t g, h, G, H;
    scanf("%"SCNd32 "%"SCNd32 "%"SCNd32 "%"SCNd32, &g, &G, &h, &H);
    g = (g << 32) + G;
    h = (h << 32) + H;
    printf("dodawanie: %"PRId32", mnożenie: %"PRId32", dzielenie: %"PRId32"\r\n", g + h, g * h, g / h);

    float i, j;
    scanf("%f %f", &i, &j);
    printf("dodawanie: %f, mnożenie: %f, dzielenie: %f\r\n", i + j, i * j, i / j);



    return 0;
}

