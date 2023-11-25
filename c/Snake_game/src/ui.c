#include "ui.h"
#include "food.h"
#include "snake.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void clear_console() {
    // ANSI escape code to clear the console
    printf("\033[H\033[J");
}

void draw(struct game_state *state) {
    clear_console(); // Clear the console

    // Draw the top border
    for (int i = 0; i < width + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printf("#"); // Draw left border

            int isPrinted = 0;

            // Check if the current position is the snake's head
            if (i == state->y && j == state->x) {
                printf("O"); // Print the snake's head
                isPrinted = 1;
            }

            // Check if the current position is the snake's tail
            for (int k = 0; k < state->nTail; k++) {
                if (tailX[k] == j && tailY[k] == i) {
                    printf("o"); // Print the snake's tail
                    isPrinted = 1;
                }
            }

            // Check if the current position is the food
            if (i == fruitY && j == fruitX) {
                printf("F"); // Print the food
                isPrinted = 1;
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
    printf("Score: %d\n", state->score);
}