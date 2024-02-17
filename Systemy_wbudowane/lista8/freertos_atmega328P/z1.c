#include "FreeRTOS.h"
#include "task.h"
#include <avr/io.h>


static void vBlinkLed(void* pvParameters);
static void vButton(void* pvParameters);

int main(void)
{
    // Create task.
    xTaskHandle blink_handle;
    xTaskHandle button_handle;

    xTaskCreate
        (
         vBlinkLed,
         "zad",
         configMINIMAL_STACK_SIZE,
         NULL,
         1,
         &blink_handle
        );

    xTaskCreate
        (
         vButton,
         "serial",
         configMINIMAL_STACK_SIZE,
         NULL,
         1,
         &button_handle
        );

    vTaskStartScheduler();

    return 0;
}


void vApplicationIdleHook(void)
{

}

static void vBlinkLed(void* pvParameters)
{
    UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);

    DDRD=0xFF;
    
    while(1) {
        for(int i = 0; i < 8; i++) {
      PORTD |= _BV(i);
      vTaskDelay(100);
      PORTD &= ~_BV(i);
    }
    vTaskDelay(100);
    for(int i = 6; i > 0; i--) {
      PORTD |= _BV(i);
      vTaskDelay(100);
      PORTD &= ~_BV(i);
    }
    vTaskDelay(100);
  }
}




uint8_t buffer[100];

static void vButton(void* pvParameters)
{
    uint8_t i = 0;
    
    PORTB |= _BV(PB4);
    DDRB |= _BV(PB5);

    while (1) {
        if (buffer[i] == 0) {
            PORTB |= _BV(PB5);
        }
        else {
            PORTB &= ~_BV(PB5);
        }

        buffer[i] = PINB & _BV(PB4);
        i++;

        if(i >= 100) {
            i=0;
        }
        vTaskDelay(10);
    }
}