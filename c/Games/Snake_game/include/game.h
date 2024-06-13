#ifndef GAME_H
#define GAME_H

#include "snake.h"

struct game_state {
    int gameOver;
    int score;
    int x;         // Add the snake's x
    int y;         // Add the snake's y
    int nTail;     // Add the length of the snake's tail
};

void clear_console();
void setup(struct game_state *state);

#endif
