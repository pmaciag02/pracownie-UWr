#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <stdio.h>
#include "hd44780.h"



int hd44780_transmit(char data, FILE *stream)
{
    LCD_WriteData(data);
    return 0;
}

FILE hd44780_file;



int main()
{
    LCD_Initialize();
    LCD_Clear();
    fdev_setup_stream(&hd44780_file, hd44780_transmit, NULL, _FDEV_SETUP_WRITE);
    stdin = stdout = stderr = &hd44780_file;

    uint8_t arr[5] = {0b10000, 0b11000, 0b11100, 0b11110, 0b11111};
    for(uint8_t i = 0; i < 5; i++) {
        uint8_t offset = i * 8;
        LCD_WriteCommand(HD44780_CGRAM_SET | offset);
        for(uint8_t j = 0; j < 8; j++){
            LCD_WriteData(arr[i]);
        }
        // LCD_WriteData(0);
    }
    

    for(uint8_t i = 0; i < 16; i++) {
        for(uint8_t j = 0; j < 5; j++) {
            LCD_GoTo(i, 0);
            printf("%c",j);
            _delay_ms(300);
        }
    }
    while(1){};
}