#include "food.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fruitX, fruitY;

void Setup_food() {
    srand(time(NULL));
    
    // Randomly position the food
    fruitX = rand() % (width - 2) + 1;
    fruitY = rand() % (height - 2) + 1;
}
