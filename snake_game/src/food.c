#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_board.h"
#include "food.h"

// Constants for defining the game board size
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

// Variable to store the position of the food
int foodX, foodY;

// Generate food at a random position on the game board
void generate_food() {
    srand(time(NULL)); // Seed the random number generator

    // Generate random coordinates for food within the game board's boundaries
    foodX = rand() % (BOARD_WIDTH - 2) + 1; // Avoid border
    foodY = rand() % (BOARD_HEIGHT - 2) + 1;
}

// Check if the snake has eaten the food
int food_eaten(int headX, int headY) {
    return (headX == foodX && headY == foodY);
}
