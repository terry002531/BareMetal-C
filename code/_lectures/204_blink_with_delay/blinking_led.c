// 05-204
#include <stdbool.h>
#include <stdint.h>

#define LED0 ((volatile bool *)0xE000U)
#define COUNTER ((volatile uint16_t *)0x40F0U)

void main(void) 
{

    volatile uint16_t *c = COUNTER;
    volatile bool *led = LED0;

    while (true) {
        *led = true;
        *c = 0;
        while (*c < 1000) { // delay
            *c = *c + 1;
        }  
        // 时间间隔，亮灯一定时间在熄灭
        // 设置为200 kHz ， 如果不加入延时，肉眼看不到LED灯闪烁
        // 加入 1000 次循环延迟，每次闪烁间隔 0.005 s
        // 每一次必须从硬件读取，这样才会消耗时间，不能单纯用一个变量在内存中循环累加
        *led = false;
        *c = 0;
        while (*c < 1000) {  // delay
            *c = *c + 1;
        }     
    }
}
