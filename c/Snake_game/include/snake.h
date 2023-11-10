#ifndef SNAKE_H
#define SNAKE_H

#include "game.h"

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

void Setup_snake();
int Check_collision();
void Check_food_collision();
int Check_corner_collision();

#endif
