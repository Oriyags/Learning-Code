#include "food.h"
#include <stdio.h>
#include <stdlib.h>

int fruitX, fruitY;

void SetupFood() {
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void DrawFood() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == fruitY && j == fruitX)
                printf("F");
            else
                printf(" ");
        }
        printf("\n");
    }
}
