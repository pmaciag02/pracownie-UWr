#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PB4
#define BTN_PIN PINB
#define BTN_PORT PORTB


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




char morse[31] = {' ' ,' ' ,'e' ,'t' ,'i' ,'a' ,'n' ,'m' ,'s' ,'u' ,'r' ,'w' ,'d' ,'k' ,'g' ,'o' ,'h' ,'v' ,'f' ,' ' ,'l' ,' ' ,'p' ,'j' ,'b' ,'x' ,'c' ,'y' ,'z' ,'q'};



int main() {
// zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;

  BTN_PORT |= _BV(BTN);
  LED_DDR |= _BV(LED);

  int pushTime = 0, fromFirst = 0, notPushed = 0;
  char c;
  // program testowy
  printf("Hello world!\r\n");
    int start = 0, i = 1;
  while (1) {
    if (BTN_PIN & _BV(BTN)) {
    //   printf("Nie swieci sie.\r\n");
      notPushed = 0;
      while (BTN_PIN & _BV(BTN) && start && notPushed < 500) {
        notPushed++;
        _delay_ms(10);
      }

      int code;
    
      if (notPushed >= 100 && notPushed < 500) { // nowy znak
        c = morse[i];
        i = 1;
        putchar(c);
        
      } else if (notPushed >= 500) { // nowe słowo
        c = morse[i];
        i = 1;
        putchar(c);
        putchar(' ');
        start = 0;
      } 
    }
    else {

    //   printf("Swieci sie.\r\n");
    start = 1;
      pushTime = 0;
      while (!(BTN_PIN & _BV(BTN))) {
        pushTime++;
        _delay_ms(10);
        if (pushTime > 50) {
          LED_PORT |= _BV(LED);
          _delay_ms(500);
          LED_PORT &= ~_BV(LED);
        }
      }

      if (pushTime <= 50) {
        i *= 2;
      }
      else {
        i = i * 2 + 1;
      }
    }
  }
  
}