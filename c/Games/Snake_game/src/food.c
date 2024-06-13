#include "food.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// [CR] food is nothing more than a data structure, it does not need a script and should be initiated at main.
int fruitX, fruitY;

void setup_food() {
    srand(time(NULL));
    
    // Randomly position the food
    fruitX = rand() % (width - 2) + 1;
    fruitY = rand() % (height - 2) + 1;
}
