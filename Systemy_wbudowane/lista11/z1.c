#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include <util/delay.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU) / 16 / (BAUD)-1)



void adc_init()
{
    ADMUX = _BV(REFS0); // referencja AVcc, wejście ADC0
    ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
    ADCSRA |= _BV(ADATE) | _BV(ADIE); // auto-trigger oraz interrupt bit
    ADCSRA |= _BV(ADEN); // włącz ADC
    ADCSRA |= _BV(ADSC); // start pierwszej konwersji adc
}


void timer_init(){
    uint16_t frequency = 50;
    uint16_t prescaler = 8;
    uint16_t icr1_value = (F_CPU / (prescaler * frequency)) - 1;
    ICR1 = icr1_value;
    TCCR1A = _BV(COM1A1) | _BV(WGM11);
    TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS10);
    DDRB |= _BV(PB1);
    TIMSK1 = _BV(TOIE1);
    OCR1A = 0;
}


volatile uint16_t speed_value = 0;

ISR(ADC_vect)
{
    ADCSRA |= _BV(ADIF);
    speed_value = ADC;
}

ISR(TIMER1_OVF_vect){
    OCR1A = speed_value << 4;
}

int main()
{
    adc_init();
    timer_init();
    sei();
    set_sleep_mode(SLEEP_MODE_IDLE);
    
    while (true)
    {
        sleep_mode();
    }
    return 0;
}