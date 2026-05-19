// 05-206
#include <stdbool.h>
#include <stdint.h>

#define LED0    ((volatile bool *)0xE000U)
#define TOGGLE0 ((volatile bool *)0xC000U)

void main(void) {

    volatile bool *led0    = LED0;
    volatile bool *toggle0 = TOGGLE0;

    while (true) {
        if (*toggle0) {     // 如果开关 toggle0 开，led0 E000U 关
            *led0 = false;
        } else {            // 如果开关 toggle0 关，led0 E000U 开
            *led0 = true;
        }
    }
}
// 实现了一个简单的读写操作，根据开关状态控制 LED 灯的开关状态
