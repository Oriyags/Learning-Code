#include <stdio.h>
#include <stdlib.h>
#include "game_board.h"
#include "snake.h"

// Constants for defining the game board size
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

// Global variables to store the snake's state
int snakeX[BOARD_WIDTH * BOARD_HEIGHT];
int snakeY[BOARD_WIDTH * BOARD_HEIGHT];
int length;
int direction;

// Initialize the snake at the specified coordinates
void initialize_snake(int startX, int startY) {
    snakeX[0] = startX;
    snakeY[0] = startY;
    length = 1;
    direction = 1; // 0: up, 1: right, 2: down, 3: left
}

// Move the snake according to the current direction
void move_snake_auto() {
    int prevX = snakeX[0];
    int prevY = snakeY[0];
    int prev2X, prev2Y;
    snakeX[0] = snakeX[0] + (direction == 1) - (direction == 3);
    snakeY[0] = snakeY[0] + (direction == 2) - (direction == 0);
    for (int i = 1; i < length; i++) {
        prev2X = snakeX[i];
        prev2Y = snakeY[i];
        snakeX[i] = prevX;
        snakeY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
}

// Move the snake based on user input
void move_snake(char key) {
    switch (key) {
        case 'w':
            if (direction != 2)
                direction = 0;
            break;
        case 'd':
            if (direction != 3)
                direction = 1;
            break;
        case 's':
            if (direction != 0)
                direction = 2;
            break;
        case 'a':
            if (direction != 1)
                direction = 3;
            break;
    }
}

// Check for collisions with walls and itself
int check_collision() {
    if (snakeX[0] < 1 || snakeX[0] >= BOARD_WIDTH - 1 || snakeY[0] < 1 || snakeY[0] >= BOARD_HEIGHT - 1)
        return -1; // Wall collision

    for (int i = 1; i < length; i++) {
        if (snakeX[i] == snakeX[0] && snakeY[i] == snakeY[0]) {
            return -1; // Self-collision
        }
    }
    return 0; // No collision
}
