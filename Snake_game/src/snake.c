#include "snake.h"
#include "food.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x, y, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;

void SetupSnake() {
    dir = RIGHT; // Initial direction (e.g., right)
    x = width / 2;
    y = height / 2;
    score = 0;
    nTail = 0;
}

void DrawSnake() {
    system("clear"); // Use "clear" to clear the terminal (for Unix-like systems)
    for (int i = 0; i < width + 2; i++)
        printf("#");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printf("#");

            int isPrinted = 0;
            if (i == y && j == x) {
                printf("O");
                isPrinted = 1;
            }

            for (int k = 0; k < nTail; k++) {
                if (tailX[k] == j && tailY[k] == i) {
                    printf("o");
                    isPrinted = 1;
                }
            }
            if (isPrinted == 0)
                printf(" ");

            if (j == width - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < width + 2; i++)
        printf("#");
    printf("\n");
    printf("Score: %d\n", score);
}

void MoveSnake() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
}

int CheckCollision() {
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            return 1;
    }
    return 0;
}

void CheckFoodCollision() {
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
