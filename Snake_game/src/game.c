#include "game.h"
#include "food.h"
#include "snake.h"
#include <stdio.h>
#include <unistd.h>

int gameOver;

void Setup() {
    gameOver = 0;
    Setup_snake();
    Setup_food();
}

void ClearConsole() {
    // ANSI escape code to clear the console
    printf("\033[H\033[J");
}

void Draw() {
    ClearConsole();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    Draw_snake();
    Draw_food();
}

void Logic() {
    Move_snake();
    if (Check_collision()) {
        gameOver = 1;
        return;
    }
    Check_food_collision();
}
