#include <stdint.h>
#include <stdbool.h>
#include "baremetal_binary.h"

#define READ2CLR_BASE ((volatile uint8_t *)0xD000U)
#define OUTPUT_BYTE ((volatile uint8_t *)0xE010U)

void main(void) {

    uint8_t data;
    uint8_t state;
    uint8_t mask;
    uint8_t position;

    state = B8(00000000); // clear state

    while(true) {
        // state to output
        *OUTPUT_BYTE = state;

        // modify state if button pressed
        for (uint8_t i = 0; i < 8; i = i+1) {
            position = 7 - i;
            data = *(READ2CLR_BASE + i); // read pushbutton
            data = data & B8(00000001);  // get only LSB
            if (data) {
                mask = 1U << position;
                state = state ^ mask;   // modify
            }
        }
    }
}
