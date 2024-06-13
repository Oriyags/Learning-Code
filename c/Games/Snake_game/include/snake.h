#ifndef SNAKE_H
#define SNAKE_H

#include "game.h"

/*
[CR]
extern=global variable : everyone can change it=disaster
using extern is really rare (moslty for linking assembly function and some global error variables), 
avoid using it as it can cause some horrible bugs and disorder.

instead, make a game_state struct type to store all of your game data, initialize it in the main script and pass it 
as needed to all the other functions.

that way you can control which functions can read/write the data. Safety :)
*/

extern const int width;
extern const int height;
extern int x, y, nTail;
extern int tailX[100], tailY[100];

enum eDirection {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

extern enum eDirection dir;

void setup_snake();
void check_food_collision();

#endif
