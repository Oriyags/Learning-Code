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

/*
[CR] after you will move the snake data into a single struct in main, all the setup functions are useless.
Anyway, you should **init** the data in the main script as it is in there.
*/
// Initialize the snake
void setup_snake() {
    dir = RIGHT;  // Set the initial direction to right
    x = width / 2;  // Set the initial x-coordinate of the snake
    y = height / 2; // Set the initial y-coordinate of the snake
    score = 0;     // Initialize the player's score
    nTail = 0;     // Initialize the length of the snake's tail
}

// Check for collisions with food and update the score
void check_food_collision() {
    if (x == fruitX && y == fruitY) {
        score += 10; // Increase the player's score
        nTail++;      // Increase the length of the snake
        fruitX = rand() % width; // Generate new coordinates for the food
        fruitY = rand() % height;
    }
}