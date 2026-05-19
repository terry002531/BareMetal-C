// 06-209
#include <stdlib.h>
#include <stdbool.h>
#include "baremetal_binary.h" // for B8() // 引入二进制
#include "baremetal_delay.h"  // for baremetal_delay()， 延时函数

#define LED_STRIP ((volatile uint8_t *)0xE008U)

void main(void) {
    volatile uint8_t *s = LED_STRIP;

    while (true) {
        *s = B8(10101111);     // X.X.XXXX
        baremetal_delay(2000);
        *s = B8(11110101);     // XXXX.X.X
        baremetal_delay(2000);
        *s = B8(01010101);     // .X.X.X.X
        baremetal_delay(2000);
    }
}
// pointer s 指向 LED_STRIP 地址 E008U，
// 通过不断改变 s 指向的值，实现 8 个 LED 灯的点亮熄灭
