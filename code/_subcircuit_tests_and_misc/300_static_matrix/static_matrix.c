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
    for (uint8_t i = 0; i < 16; i = i+1) {
        *(MATRIX + i) = *(STATE + i);
    }
}

void main(void){

    *(STATE +  0) = B8(11001010);
    *(STATE +  2) = B8(01010101);
    *(STATE + 15) = B8(00110011);
    update_view();

    while (true) {
    }
}
