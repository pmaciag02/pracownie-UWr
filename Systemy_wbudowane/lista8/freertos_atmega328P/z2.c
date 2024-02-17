#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>




#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

static void vBlinkLed(void* pvParameters);
static void vSerial(void* pvParameters);

int uart_transmit(char c, FILE *stream);
int uart_receive(FILE *stream);
void uart_init(void);

FILE uart_file = FDEV_SETUP_STREAM(uart_transmit, uart_receive, _FDEV_SETUP_RW);

// inicjalizacja UART
void uart_init(void)
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

int uart_transmit(char c, FILE *stream) {
  while (!(UCSR0A & _BV(UDRE0))) taskYIELD();
  UDR0 = c;
  return 0;
}

int uart_receive(FILE *stream) {
  while (!(UCSR0A & _BV(RXC0))) taskYIELD();
  return UDR0;
}

QueueHandle_t Q;

int main(void)
{
    Q = xQueueCreate(100, sizeof(uint16_t));
    // Create task.
    xTaskHandle blink_handle;
    xTaskHandle read_handle;

    xTaskCreate
        (
         vBlinkLed,
         "blink",
         configMINIMAL_STACK_SIZE,
         NULL,
         1,
         &blink_handle
        );

    xTaskCreate
        (
         vSerial,
         "uart",
         200,
         NULL,
         1,
         &read_handle
        );

    // Start scheduler.
    vTaskStartScheduler();

    return 0;
}


void vApplicationIdleHook(void)
{

}

static void vBlinkLed(void* pvParameters)
{
    DDRB |= _BV(PB5);
    uint16_t buffer;
    
    while(1)
    {
        if (xQueueReceive(Q, &buffer, 0) == pdPASS) {
            PORTB |= _BV(PB5);
            vTaskDelay(buffer);
            PORTB &= ~_BV(PB5);
            vTaskDelay(1000);
        }
    }
}


static void vSerial(void* pvParameters)
{
    uart_init();
    stdin = stdout = stderr = &uart_file;

    uint16_t buffer;
    while(1)
    {
        scanf("%" SCNu16 ,&buffer);
        printf("%" PRIu16 "\r\n", buffer);

        if (uxQueueMessagesWaitingFromISR(Q) < 99) {
            xQueueSendToBack(Q, &buffer, portMAX_DELAY);
        }
    }
}