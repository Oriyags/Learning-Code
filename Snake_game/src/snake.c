#include "snake.h"
#include "food.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Variables to store the snake's position, score, and tail
int x, y, score;
int tailX[100], tailY[100];
int nTail;

// Enum to represent the snake's direction
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;

// Initialize the snake
void Setup_snake() {
    dir = RIGHT;  // Set the initial direction to right
    x = width / 2;  // Set the initial x-coordinate of the snake
    y = height / 2; // Set the initial y-coordinate of the snake
    score = 0;     // Initialize the player's score
    nTail = 0;     // Initialize the length of the snake's tail
}

// Draw the snake on the game board
void Draw_snake() {
    system("clear"); // Clear the console

    // Draw the top border
    for (int i = 0; i < width + 2; i++)
        printf("#");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printf("#"); // Draw left border

            int isPrinted = 0;
            if (i == y && j == x) {
                printf("O"); // Print the snake's head
                isPrinted = 1;
            }

            for (int k = 0; k < nTail; k++) {
                if (tailX[k] == j && tailY[k] == i) {
                    printf("o"); // Print the snake's tail
                    isPrinted = 1;
                }
            }

            if (isPrinted == 0)
                printf(" "); // Print an empty space

            if (j == width - 1)
                printf("#"); // Draw right border
        }
        printf("\n");
    }

    // Draw the bottom border
    for (int i = 0; i < width + 2; i++)
        printf("#");
    printf("\n");

    // Display the player's score
    printf("Score: %d\n", score);
}

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

// Check for collisions with the snake's tail
int Check_collision() {
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            return 1; // Collision detected
    }
    return 0; // No collision
}

// Check for collisions with food and update the score
void Check_food_collision() {
    if (x == fruitX && y == fruitY) {
        score += 10; // Increase the player's score
        nTail++;      // Increase the length of the snake
        fruitX = rand() % width; // Generate new coordinates for the food
        fruitY = rand() % height;
    }
}

// Check for collisions with corners
int Check_corner_collision() {
    if ((x == 0 && (y == 0 || y == height - 1)) || 
        (x == width - 1 && (y == 0 || y == height - 1))) {
        return 1; // Collision with a corner detected
    }
    return 0; // No collision
}