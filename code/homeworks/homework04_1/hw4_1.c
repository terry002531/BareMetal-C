#include <stdint.h>
#include <stdbool.h>
#include "baremetal_delay.h"

// DELAY TIME
#define DELAY (3000)

// VIEW
#define VIEW_DECIMAL ((volatile uint8_t * const)0xE800U)

void view_update(uint8_t value){
    // WRONG                    // 把10进制转为二进制存储
    //*VIEW_DECIMAL = value;    // 把这个 8-bit 数据拆成两个 4-bit，然后把每个 4-bit 当作一个十六进制数字显示
    // 只能显示value对应的16进制数字
    uint8_t ten = value / 10;
    uint8_t unit = value % 10;
    uint8_t display_value = (ten << 4) | unit; // 高4位存十位，低4位存个位
    *VIEW_DECIMAL = display_value;      // 把value十位存储在地址前四位，个位存储在地址后四位
    // 这个是单字节数据，不存在小端序引起的倒着存储
}

void main(void){
    while (true) {
        *VIEW_DECIMAL = 0x93U;
        baremetal_delay(DELAY);
        *VIEW_DECIMAL = 0x45U;
        baremetal_delay(DELAY);
        *VIEW_DECIMAL = 0x26U;
        baremetal_delay(DELAY);
        view_update(93);
        baremetal_delay(DELAY);
        view_update(45);
        baremetal_delay(DELAY);
        view_update(26);
        baremetal_delay(DELAY);
    }
}
