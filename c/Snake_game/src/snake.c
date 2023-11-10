#include "snake.h"
#include "food.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum eDirection dir;

// Variables to store the snake's position, score, and tail
int x, y, score;
int tailX[100], tailY[100];
int nTail;

// Initialize the snake
void Setup_snake() {
    dir = RIGHT;  // Set the initial direction to right
    x = width / 2;  // Set the initial x-coordinate of the snake
    y = height / 2; // Set the initial y-coordinate of the snake
    score = 0;     // Initialize the player's score
    nTail = 0;     // Initialize the length of the snake's tail
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
