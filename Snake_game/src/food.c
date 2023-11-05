#include "food.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fruitX, fruitY;

void Setup_food() {
    srand(time(NULL));
    
    // Randomly position the food within the game boundaries
    fruitX = rand() % (width - 2) + 1;
    fruitY = rand() % (height - 2) + 1;
}

void Draw_food() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Print 'F' at the food's position, else print a space
            if (i == fruitY && j == fruitX)
                printf("F");
            else
                printf(" ");
        }
        printf("\n");
    }
}
