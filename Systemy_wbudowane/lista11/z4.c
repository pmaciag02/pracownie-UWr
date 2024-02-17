#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>

void adc_init(){
  ADMUX  |= _BV(REFS0); // referencja AVcc, wejście ADC0
  ADCSRA |= _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  ADCSRA |= _BV(ADATE) | _BV(ADIE); // auto-trigger oraz interrupt bit
  ADCSRA |= _BV(ADEN); // włącz ADC
  ADCSRA |= _BV(ADSC); // start pierwszej konwersji adc
}


ISR(ADC_vect){
  OCR1A = 1023 - ADC;
}

void timer_init(){
  TCCR1A |= _BV(COM1A1) | _BV(WGM11);
  TCCR1B |= _BV(WGM13) | _BV(WGM12) | _BV(CS11) | _BV(CS10); // fast pwm, preskaler 64
  ICR1 = 4999;
  DDRB |= _BV(PB1);
}

int main(){
  adc_init();
  timer_init();
  sei();
  set_sleep_mode(SLEEP_MODE_IDLE);

  while(1) { 
    sleep_mode();
  }
}