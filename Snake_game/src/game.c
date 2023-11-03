#include "game.h"
#include "food.h"
int gameOver;

void Setup() {
    gameOver = 0;
    SetupSnake();
    SetupFood();
}

void Draw() {
    DrawSnake();
    DrawFood();
}

void Logic() {
    MoveSnake();
    if (CheckCollision()) {
        gameOver = 1;
        return;
    }
    CheckFoodCollision();
}
