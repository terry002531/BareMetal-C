#include <stdbool.h>
#include <stdint.h>
#include "baremetal_binary.h"

#define MATRIX ((volatile uint8_t *)0xE020U)
#define STATE ((uint8_t *)0x4010U)
#define COUNTER ((volatile uint16_t *)0x4000U)

void delay(uint16_t n) {
    volatile uint16_t *c = COUNTER;
    *c = 0;
    while (*c < n) {
        *c = *c + 1;
    }
}

void update_view(void){
    for (uint8_t i = 0; i < 8; i = i+1) {
        *(MATRIX + i) = *(STATE + i);
    }
}

void main(void){
/*
    *(STATE + 0) = B8(01010101);
    *(STATE + 1) = B8(00110011);
    *(STATE + 2) = B8(00001111);
    *(STATE + 3) = B8(01010000);
    *(STATE + 4) = B8(10101010);
    *(STATE + 5) = B8(11001100);
    *(STATE + 6) = B8(11110000);
    *(STATE + 7) = B8(11111111);
*/
    *(STATE + 0) = B8(00111100);
    *(STATE + 1) = B8(01000010);
    *(STATE + 2) = B8(10010101);
    *(STATE + 3) = B8(10000101);
    *(STATE + 4) = B8(10000101);
    *(STATE + 5) = B8(10010101);
    *(STATE + 6) = B8(01000010);
    *(STATE + 7) = B8(00111100);
    update_view();

    while (true) {
        // update MODEL
        uint8_t save = 0; // = 0 to make compiler happy
        for (int8_t i = 7; i >= 0; i = i - 1) {
            if (i == 7) {
                save = *(STATE + i);
                *(STATE + i) = *(STATE + i -1);
            } else if (i > 0) {
                *(STATE + i) = *(STATE + i -1);
            } else {
                *(STATE) = save;
            }
        }
        delay(800);
        // update VIEW
        update_view();
    }
}
