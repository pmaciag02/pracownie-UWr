#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem


#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB


// mors[0...9, a...z]
int16_t mors[] = {160, 176, 184, 188, 190, 191, 175, 167, 163, 161, 66, 135, 133, 99, 33, 141, 97, 143, 67, 136, 98, 139, 64, 65, 96, 137, 130, 101, 103, 32, 102, 142, 100, 134, 132, 131};



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



void trans(int16_t code) {
  int length, bit;

  length = (code & 0xe0) >> 5;
  length = 1 << (length - 1);

  while(length) {
    bit = code & length;

    if (bit) {
      printf("KROPKA ");
      LED_PORT |= _BV(LED);
      _delay_ms(800);
      LED_PORT &= ~_BV(LED);
      _delay_ms(800);
    }
    else {
      printf("KRESKA ");
      LED_PORT |= _BV(LED);
      _delay_ms(2000);
      LED_PORT &= ~_BV(LED);
      _delay_ms(800);
    }

    length >>= 1;
  }
  printf("\r\n");

}



int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // program testowy
  // printf("Hello world!\r\n");


//     int16_t a = 1;
//     scanf("%"SCNd16, &a);


  while(1) {
    LED_DDR |= _BV(LED);
    char c;
    // int length, bit, code;

    while(1) {
        scanf("%c", &c);
        if (c == '\n' || c == '\r') {
          // putchar('\n');
          printf("\r\n");
            // break;
        }
        else{
        // printf("%hd\r\n", c);
        if (c >= '0' && c <= '9') {
            printf("%"PRId16"\r\n", mors[c - 48]);
            trans(mors[c - 48]);
        }
        else if (c >= 'a' && c <= 'z') {
            printf("%"PRId16"\r\n", mors[c - 87]);
            trans(mors[c - 87]);
        }
        else if (c >= 'A' && c <= 'Z') {
            printf("%"PRId16"\r\n", mors[c - 55]);
            trans(mors[c - 55]);
        }
        }
    }
  }
}

