#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <inttypes.h>
#include <string.h>
#include "hd44780.h"
#include <avr/io.h>
#include <stdint.h>
// #include <util/delay.h>
#include <stdio.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

volatile uint8_t data;

// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // wyczyść rejestr UCSR0A
  UCSR0A = 0;
  // włącz odbiornik i nadajnik oraz włącz przerwania
  UCSR0B = _BV(RXEN0) | _BV(TXEN0) | _BV(RXCIE0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

char c;
uint8_t i = 0;
char current_line[17] = "                \0";

// ISR(USART_TX_vect){
//   UCSR0B |= _BV(RXCIE0);
// }


ISR(USART_RX_vect){
//   UCSR0B &= ~_BV(RXCIE0);
    data = UDR0;
    UDR0 = data;
    if (data == '\r') {
        UDR0 = '\n';
        LCD_Clear();
        LCD_GoTo(0, 0);
        LCD_WriteText(current_line);
        LCD_GoTo(0, 1);
        i = 0;
        strncpy(current_line, "                \0", 17);
        return;
    }
    else {
        LCD_WriteData(data);
        current_line[i] = data;
        i++;
        if (i == 16) {
            LCD_GoTo(0, 1);
            i = 0;
        }
    }
}

// int hd44780_transmit(char data, FILE *stream)
// {
//     LCD_WriteData(data);
//     return 0;
// }

FILE hd44780_file;

int main(){
    uart_init();
    LCD_Initialize();
    LCD_Clear();
    LCD_WriteCommand(HD44780_DISPLAY_ONOFF | HD44780_DISPLAY_ON | HD44780_CURSOR_ON | HD44780_CURSOR_BLINK);
    
    sei();
    //   UCSR0B |= _BV(RXCIE0);
    //   UCSR0B |= _BV(TXCIE0);
    set_sleep_mode(SLEEP_MODE_IDLE);
    while(1) {
        sleep_mode();
    }
}