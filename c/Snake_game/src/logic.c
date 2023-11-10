#include "snake.h"
#include "game.h"
#include "food.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Move the snake based on its direction
void Move_snake() {
    int prevX, prevY; // Declare variables at the beginning of the function
    int prev2X, prev2Y;
    int diffX = fruitX - x;
    int diffY = fruitY - y;
    enum eDirection new_dir = dir;

    prevX = tailX[0];
    prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;

    // Update the position of the snake's tail
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Calculate direction to the food
    if (abs(diffX) > abs(diffY)) {
        // Move horizontally
        if (diffX > 0)
            new_dir = RIGHT;
        else if (diffX < 0)
            new_dir = LEFT;
    } else {
        // Move vertically
        if (diffY > 0)
            new_dir = DOWN;
        else if (diffY < 0)
            new_dir = UP;
    }

    // Check if the new direction is valid (not opposite to the current direction)
    if ((new_dir == LEFT && dir != RIGHT) ||
        (new_dir == RIGHT && dir != LEFT) ||
        (new_dir == UP && dir != DOWN) ||
        (new_dir == DOWN && dir != UP)) {
        dir = new_dir;
    }

    // Move the snake based on its direction
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    // Wrap snake around the game board if it goes out of bounds
    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;
    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;
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