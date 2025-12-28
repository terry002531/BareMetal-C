#include <stdbool.h>
#include <stdint.h>

#define LED0    ((volatile bool *)0xE000U)
#define SWITCH0 ((volatile bool *)0xC000U)

void main(void) {

    volatile bool *led0    = LED0;
    volatile bool *switch0 = SWITCH0;

    while (true) {
        if (*switch0) {
            *led0 = false;
        } else {
            *led0 = true;
        }
    }
}
