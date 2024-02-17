#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>



#define LED PB2
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PA7
#define BTN_PIN PINA
#define BTN_PORT PORTA


int bufferSize = 100;
int8_t buffer[105];

int writeIndx = 0;
int readIndx  = 0;

int put (int8_t item) 
{
  if ((writeIndx + 1) % bufferSize == readIndx)
  {
     // buffer is full, avoid overflow
     return 0;
  }
  buffer[writeIndx] = item;
  writeIndx = (writeIndx + 1) % bufferSize;
  return 1;
}

int get (int8_t * value) 
{
  if (readIndx == writeIndx)
  {
     // buffer is empty
     return 0;
  }

  *value = buffer[readIndx];
  readIndx = (readIndx + 1) % bufferSize;
  return 1;
}







static inline void initTimer0(void) {
 
  // Timer 0 
  TCCR0A |= _BV(WGM01); // CTC
  TCCR0B |= _BV(CS01) | _BV(CS00); // Prescaler 1024
  
  OCR0A = 155;
  // OCR0A = 77;

  // Compare Interrupt 
  TIMSK0 |= _BV(OCIE0A);

}




// może być potrzebny volatile
static int8_t bit, i = 0, start = 0;




ISR(TIM0_COMPA_vect) {
  if (i < 100 && start) {
      i++;
  }
  if (i >= 100 && start){
    get(& bit);
    if (bit) {
      LED_PORT |= _BV(LED);
    }
    else {
      LED_PORT &= ~_BV(LED);
    }
  }

  if (BTN_PIN & _BV(BTN) && start) {
    put(0);
  }
  else if (!(BTN_PIN & _BV(BTN))) {
    start = 1;
    put(1);
  }
}





int main() {
  // zainicjalizuj wejścia/wyjścia
  // io_init();
  // ustaw tryb uśpienia na tryb bezczynności
  set_sleep_mode(SLEEP_MODE_IDLE);
  // odmaskuj przerwania
  sei();

  BTN_PORT |= _BV(BTN);
  LED_DDR |= _BV(LED);

  
  initTimer0();
  while (1) {
    sleep_mode();
  }
}