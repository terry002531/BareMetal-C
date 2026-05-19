// 05-207 (NEW!!!)
#include <stdbool.h>
#include <stdint.h>

#define LED0    ((volatile bool *)0xE000U) // LED等起始的地址，E000U 到 E003U 共4个地址
#define TOGGLE0 ((volatile bool *)0xC000U) // 开关等起始的地址，C000U 到 C003U 共4个地址

void main(void) {
    volatile bool *led    = LED0;
    volatile bool *toggle = TOGGLE0;

    while (true) {

        for (uint8_t i = 0; i < 4; i = i + 1) { // 不停扫描4个开关的状态，控制对应的LED灯
            if (*(toggle + i)) {
                *(led + i) = false;
            } else {
                *(led + i) = true;
            }
        }
    }
}
