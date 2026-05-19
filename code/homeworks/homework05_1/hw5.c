#include <stdint.h>
#include <stdbool.h>
#include "baremetal_binary.h" 

#define MAX_TICK (60)

#define VIEW_LIGHT  ((volatile uint8_t * const)0xE020U)  // 0xE020~0xE02F
#define VIEW_SCORE  ((volatile uint8_t * const)0xE800U)   

#define RANDOM_DISP ((volatile uint8_t * const)0xE808U)  

#define CONTROLLER  ((volatile const uint8_t * const)0xD010U)  

// MODEL
typedef struct {
    uint8_t matrix[16];
    uint8_t player_col; // Player is always Row 0
    uint8_t coin_row;
    uint8_t coin_col;
    uint8_t score;      // Range 0-99
    uint8_t tick;       // Speed control (Time State)
} model_t;

typedef struct {
    bool ch;
    uint8_t player_col_previous;
}view_state;


// CONTROLLER
typedef enum {
    NONE, LEFT, RIGHT, RESTART
} command;

void view_reset(void)
{
    for (uint8_t i = 0; i < 16; i++) {
        *(VIEW_LIGHT + i) = B8(00000000);
    }
    *VIEW_SCORE = 0;
}

// MODEL
void model_init(model_t *mp, view_state *wp, uint8_t random)
{  
    for (uint8_t i = 0; i < 16; i++) {
        mp->matrix[i] = B8(00000000);
    }
    mp->player_col = 7;
    wp->player_col_previous = 7;
    mp->coin_row = 7;
    mp->coin_col = random % 16;
    mp->score = 0;
    mp->tick = 0;
    wp->ch = true;
}

void model_update(model_t *mp, view_state *wp, uint8_t random, command c)
{
    wp->ch = false;
    switch(c)
    {
        case LEFT: 
            if (mp->player_col != 0) 
            {
                wp->player_col_previous = mp->player_col;
                mp->player_col --;
            }
            wp->ch = true;
            break;
        case RIGHT:
            if (mp->player_col != 15) 
            {
                wp->player_col_previous = mp->player_col;
                mp->player_col ++;
            }
            wp->ch = true;
            break;
        case RESTART:
            model_init(mp,wp, random);
            view_reset();
            break;
        case NONE: 
            break;
    }

    if (mp->coin_row == 0 && mp->coin_col == mp->player_col)
        {
            if(mp->score <= 96) mp->score += 3;
            mp->coin_row = 7;
            mp->coin_col = random % 16;
        }
    else
    {
        mp->tick ++;
        if (mp->tick == MAX_TICK) 
        {
            mp->tick = 0;
            wp->ch = true;
            if (mp->coin_row > 0) mp->coin_row --;
            else if(mp->coin_row == 0)
            {
                mp->coin_row = 7;
                if(mp->score > 0) mp->score --;
            }
        }
    }
}

// VIEW

uint8_t change(uint8_t a)
{
    uint8_t value = a;
    uint8_t ten = value / 10;
    uint8_t unit = value % 10;
    uint8_t display_value = (ten << 4) | unit;  // 高4位存十位，低4位存个位
    return display_value;                       // 把value十位存储在地址前四位，个位存储在地址后四位
}

void view_update(const model_t *mp, const view_state *wp){
    if(wp->ch == false) return;
    *VIEW_SCORE = change(mp->score);
    if(mp->player_col != wp->player_col_previous)
    {
        *(VIEW_LIGHT + wp->player_col_previous) = B8(00000000);
    }
    if(mp->coin_col == mp->player_col)
    {
        *(VIEW_LIGHT + mp->player_col) = B8(00000001) | (1 << mp->coin_row);
    }
    else{
        *(VIEW_LIGHT + mp->player_col) = B8(00000001);
        *(VIEW_LIGHT + mp->coin_col) = (1 << mp->coin_row);
    }
}

// CONTROLLER
command controller_read(void)
{  
    uint8_t key = *CONTROLLER;
    switch (key)
    {
        case B8(10100000):
            return LEFT;
        case B8(10100010):
            return RIGHT;
        case B8(10000010):
            return RESTART;
        default:
            return NONE;
    }
}

void main(void){
    model_t m;
    model_t *mp = &m;
    view_state w;
    view_state *wp = &w;
    command c;
    uint8_t random = 0;
    model_init(mp,wp, random);
    while (true){
        c = controller_read();
        model_update(mp,wp, random, c);
        view_update(mp,wp);
        *RANDOM_DISP = random;
        random = random + 1 + (uint8_t ) c;
    }
}
