#ifndef SNAKE_H
#define SNAKE_H
#include "food.h"

// Define the Snake structure
typedef struct {
    int x, y;
} SnakeSegment;

typedef struct {
    SnakeSegment* body;
    int length;
    int direction;
} Snake;

void initSnake(int x, int y);
void moveSnake();
void changeSnakeDirection(int newDirection);
int isGameOver();

#endif

