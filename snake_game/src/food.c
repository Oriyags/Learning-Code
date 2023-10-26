#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <food.h>

Food createFood(int maxX, int maxY) {
    Food food;
    srand(time(NULL)); // Seed the random number generator
    food.x = rand() % maxX;
    food.y = rand() % maxY;
    return food;
}

void drawFood(Food food) {
    mvaddch(food.y, food.x, 'F');
}

int isFoodEaten(Food food, int x, int y) {
    return food.x == x && food.y == y;
}

