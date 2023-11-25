#include "game.h"
#include "food.h"
#include "snake.h"
#include "ui.h"
#include <stdio.h>
#include <unistd.h>

int gameOver;

void setup(struct game_state *state) {
    state->gameOver = 0;
    setup_snake(state); // Initialize the snake
    setup_food();       // Initialize the food
}