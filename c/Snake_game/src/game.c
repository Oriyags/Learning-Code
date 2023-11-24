#include "game.h"
#include "food.h"
#include "snake.h"
#include "ui.h"
#include <stdio.h>
#include <unistd.h>

// [CR] this script seems pretty useless. And why is there a ClearConsole (clear_console*) function in here? move it to UI
int gameOver;

void Setup() {
    gameOver = 0;
    Setup_snake(); // Initialize the snake
    Setup_food();  // Initialize the food
}

void ClearConsole() {
    // ANSI escape code to clear the console
    printf("\033[H\033[J");
}
