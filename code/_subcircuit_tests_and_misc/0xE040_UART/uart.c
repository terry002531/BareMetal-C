// 06-2
#include <stdbool.h>
#include <stdint.h>
#include "baremetal_binary.h"
#include "baremetal_delay.h"

#define UART ((volatile uint8_t *)0xE040U)
#define DELAY (500U)

void write_uart_and_delay(uint8_t c, uint16_t delay) {
    *UART = c;
    baremetal_delay(delay);
}

void main(void){
    uint8_t data;

    while (true) {

        data = 'A';
        for (uint8_t i = 0; i < 26; i = i + 1) {
            write_uart_and_delay(data, DELAY);
            data = data + 1;
        }
        write_uart_and_delay('-', DELAY);

        data = 'a'; 
        for (uint8_t i = 0; i < 26; i = i + 1) {
            write_uart_and_delay(data, DELAY);
            data = data + 1;
        }
        write_uart_and_delay(' ', DELAY);
    }
}
