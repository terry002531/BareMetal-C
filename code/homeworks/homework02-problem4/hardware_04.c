// student name: Letao Shi
// student ID: 6838271021

#include <stdbool.h>
#include <stdint.h>

#define LED0 ((volatile bool *)0xE000U)
#define LED1 ((volatile bool *)0xE001U)
#define LED3 ((volatile bool *)0xE003U)

void main(void) {

    volatile bool *led; 
    led = LED0;

    while (true) {
        led = LED1;
       *led = true;
       *led = false;

       led = LED0;
       *led = true;
       *led = false;

       led = LED1;
       *led = true;
       *led = false;

       led = LED3;
       *led = true;
       *led = false;

       led = LED1;
       *led = true;
       *led = false;

       led = LED0;
       *led = true;
       *led = false;
    }

}
