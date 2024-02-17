#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PB4
#define BTN_PIN PINB
#define BTN_PORT PORTB


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







int main() {
  BTN_PORT |= _BV(BTN);
  LED_DDR |= _BV(LED);

  int8_t bit, i = 0, start = 0;

  while (1) {
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

    _delay_ms(10);


  }
}