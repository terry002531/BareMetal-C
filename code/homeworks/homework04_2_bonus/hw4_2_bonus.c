// 讲解：https://chatgpt.com/s/t_69835b9f16148191928435c56594484c
#include <stdint.h>
#include <stdbool.h>

// VIEW
#define VIEW_LIGHT  ((volatile uint8_t * const)0xE000U)     // 0xE000 是 LED0 的寄存器地址
                                                            // 因为 LED1~LED3 紧挨着，所以可以当数组访问，如48行

// CONTROLLER
#define CONTROLLER_LEFT  ((volatile const bool * const)0xD000U)
#define CONTROLLER_RIGHT ((volatile const bool * const)0xD001U)

volatile uint8_t *g_led;    // 保存“当前点亮的是哪一个 LED 地址”
                            // 由于该程序需要操控多个led，不能仅仅使用“*VIEW_LIGHT = mp->light;”来点亮
                            // 需要g_led来保存当前点亮的是哪一个led地址，从而实现点亮不同的led

// MODEL
typedef struct {
    bool light;
} model_t;

typedef enum {
    NONE, LEFT, RIGHT
} command;

void model_init(model_t *mp){  // 初始化所有状态
    mp->light = true;
    g_led = (volatile uint8_t *)0xE000U; // 初始化当前位置为第一个led
}

void model_update(command c){  // 判断按了哪一个按钮，应该怎么做
    switch (c) {
        case LEFT: if(g_led != (volatile uint8_t *)0xE000U){
                      g_led --;
                  }
                  break;
        case RIGHT: if(g_led != (volatile uint8_t *)0xE003U){
                       g_led ++;
                   }
                   break;
        case NONE:
        default:
            break;
    }
}

// VIEW

#define VIEW_LIGHT  ((volatile uint8_t * const)0xE000U)
volatile uint8_t *g_led;    // 保存“当前点亮的是哪一个 LED 地址”
void view_update(const model_t *mp){   
    // 先关掉四盏灯（0xE000~0xE003）
    VIEW_LIGHT[0] = 0;
    VIEW_LIGHT[1] = 0;
    VIEW_LIGHT[2] = 0;
    VIEW_LIGHT[3] = 0;
    // 只点亮当前位置那一盏
    *g_led = mp->light;
}

// CONTROLLER
command controller_read(void){  // 读取按钮状态
    if (*CONTROLLER_LEFT)  return LEFT;
    if (*CONTROLLER_RIGHT) return RIGHT;
    return NONE;
}

void main(void){
    model_t m;
    model_t *mp = &m;
    command c;
    model_init(mp);   // 初始化
    while (true) {
        // VIEW  UPDATE
        view_update(mp);
        // CONTROLLER
        c = controller_read();
        // MODEL UPDATE
        model_update(c);
    }
}
