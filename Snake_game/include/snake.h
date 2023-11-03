#ifndef SNAKE_H
#define SNAKE_H

extern const int width;
extern const int height;

void SetupSnake();
void DrawSnake();
void MoveSnake();
int CheckCollision();
void CheckFoodCollision();

#endif
