// 05-205
#include <stdbool.h>
#include <stdint.h>

#define LED0 ((volatile bool *)0xE000U)
#define COUNTER ((volatile uint16_t *)0x40F0U)

void delay(uint16_t n) {  // 使用void，因为不需要返回值
    volatile uint16_t *c = COUNTER;
    *c = 0;
    while (*c < n) {
        *c = *c + 1;
    }
}

void main(void) {

    volatile bool *led = LED0;

    while (true) {
        *led = true;
        delay(1500);   // function call
        *led = false;
        delay(1500);   // function call
    }
}
