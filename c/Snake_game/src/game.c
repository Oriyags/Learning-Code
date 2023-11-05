#include "game.h"
#include "food.h"
#include "snake.h"
#include <stdio.h>
#include <unistd.h>

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

void Draw() {
    ClearConsole(); // Clear the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    Draw_snake(); // Draw the snake on the game board
    Draw_food();  // Draw the food on the game board
}

void Logic() {
    Move_snake();     // Move the snake
    if (Check_collision()) {
        gameOver = 1;  // Set the game over flag if there's a collision
        return;
    }
    if (Check_corner_collision()) {
        gameOver = 1;  // Set the game over flag if there's a corner collision
        return;
    }
    Check_food_collision(); // Check for collisions with food
}
