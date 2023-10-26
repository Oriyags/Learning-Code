#ifndef FOOD_H
#define FOOD_H

typedef struct {
    int x, y;
} Food;

Food createFood(int maxX, int maxY);
void drawFood(Food food);
int isFoodEaten(Food food, int x, int y);

#endif

