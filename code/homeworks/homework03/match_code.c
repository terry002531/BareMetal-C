// student name: Letao Shi
// student ID: 6838271021

#include <stdbool.h>
#include <stdint.h>
#include "baremetal_binary.h"   

#define LED_MATCH   (*(volatile bool*)0xE000U)

#define SW1 (*(volatile uint8_t*)0xC010U) 
#define SW2 (*(volatile uint8_t*)0xC011U) 
#define SW3 (*(volatile uint8_t*)0xC012U) 
#define SW4 (*(volatile uint8_t*)0xC013U) 
#define SW5 (*(volatile uint8_t*)0xC014U) 
#define SW6 (*(volatile uint8_t*)0xC015U) 
#define SW7 (*(volatile uint8_t*)0xC016U) 
#define SW8 (*(volatile uint8_t*)0xC017U) 

uint8_t read_code(void)
{
    return (SW1 << 7) |
           (SW2 << 6) |
           (SW3 << 5) |
           (SW4 << 4) |
           (SW5 << 3) |
           (SW6 << 2) |
           (SW7 << 1) |
           (SW8 << 0);
}

void main(void)
{
    uint8_t key = B8(10001100);   

    while (true)
    {
        if (read_code() == key)
            LED_MATCH = true;   // ON
        else
            LED_MATCH = false;   // OFF
    }
}

/*
#include <stdbool.h>
#include <stdint.h>

#define LED_MATCH ((volatile uint8_t *)0xE000U)

#define s1 (*(volatile uint8_t *)0xc010U)
#define s2 (*(volatile uint8_t *)0xc011U)
#define s3 (*(volatile uint8_t *)0xc012U)
#define s4 (*(volatile uint8_t *)0xc013U)
#define s5 (*(volatile uint8_t *)0xc014U)
#define s6 (*(volatile uint8_t *)0xc015U)
#define s7 (*(volatile uint8_t *)0xc016U)
#define s8 (*(volatile uint8_t *)0xc017U)

void main(void) {

    while (true) {
        if(s1==1 && s2==0 && s3==0 && s4==0 && s5==1 && s6==1 && s7==0 && s8==0){
            *LED_MATCH = 0xFF; // 全亮
        }
        else{
            *LED_MATCH = 0x00; // 全灭
    }

}}
*/
/*
#include <stdbool.h>
#include <stdint.h>

#define LED_MATCH ((volatile uint8_t *)0xE000U)

#define s1 (*(volatile uint8_t *)0xc010U)
#define s2 (*(volatile uint8_t *)0xc011U)
#define s3 (*(volatile uint8_t *)0xc012U)
#define s4 (*(volatile uint8_t *)0xc013U)
#define s5 (*(volatile uint8_t *)0xc014U)
#define s6 (*(volatile uint8_t *)0xc015U)
#define s7 (*(volatile uint8_t *)0xc016U)
#define s8 (*(volatile uint8_t *)0xc017U)

void main(void) {

    while (true) {
        if (s1==1 && s2==0 && s3==1 && s4==0 && s5==0 && s6==0 && s7==1 && s8==0){
            *LED_MATCH = 0xFF; 
        }
        else{
            *LED_MATCH = 0x00;
        }
    }}
*/
