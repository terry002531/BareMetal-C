#include <stdint.h>
#include <stdbool.h>
#include "baremetal_binary.h"

#define KEYBOARD_ADDR ((volatile uint8_t *)0xD020U)
#define UART_ADDR     ((volatile uint8_t *)0xE040U)

// Full NATO phonetic alphabets here:
const char *WORDS[26] = {
    "alfa", "bravo", "charlie", "delta", "echo", "foxtrot",
    "golf", "hotel", "india", "juliett", "kilo", "lima",
    "mike", "november", "oscar", "papa", "quebec", "romeo",
    "sierra", "tango", "uniform", "victor", "whiskey", "xray",
    "yankee", "zulu"
};

void main(void) {
    uint8_t i;
    uint8_t key;
    
    while (true) {
        i = *KEYBOARD_ADDR;
        if(i & B8(10000000)){
            key = i & B8(01111111);
            if(key == 0x0D){
                *UART_ADDR = '\r';
            }
            if(key == 0x20){
                *UART_ADDR = '\r';
            }
            // 1. Read from Keyboard
            // remember KEYBOARD_ADDR is read-to-clear
            // 2. Check keyboard output valid bit and
            // Check if key is in valid range ('A' through 'Z')
            if(key >= 'A' && key <= 'Z') {
                static volatile bool d=true;
                // 3. Calculate Index (0-25)
                uint8_t index = key - 'A';

                // 4. Get the pointer to the start of the string
                const uint8_t *ptr = WORDS[index];

                // 5. Loop until NUL terminator
                // TODO: Write the while loop here to send *ptr to UART_ADDR
            
                while(*ptr){
                    if(d){
                        *UART_ADDR = *ptr - 32;
                        d=false;
                    }
                    else{
                        *UART_ADDR = *ptr; // Send the character to UART
                    }
                    ptr++; // Move to the next character
                }
                // 6. Print CR
                *UART_ADDR = '\r';
                d = true;
            }
        // end if for 2.
        } 
    }
}
