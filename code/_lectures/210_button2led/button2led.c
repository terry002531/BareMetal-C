#include <stdint.h>
#include <stdbool.h>
#include "baremetal_binary.h"

// MODEL and initializer
uint8_t state = B8(00000000);
// CONTROLLER
#define PUSHBUTTON_BASE ((volatile uint8_t *)0xD000U)
// VIEW
#define LED_STRIP ((volatile uint8_t *)0xE008U)

void main(void){
    
    uint8_t bit_mask;

    while (true) {
        // CONTROLLER, clear bit mask
        bit_mask = B8(00000000);
        for (uint8_t i = 0; i < 8; i = i + 1) {
            if (*(PUSHBUTTON_BASE + i)) {
                bit_mask = bit_mask | ( 1U << (7-i) );
            }
        }
        // UPDATE MODEL
        state = state ^ bit_mask;
        // VIEW
        *LED_STRIP = state;
    }
}
