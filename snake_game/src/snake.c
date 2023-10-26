#include <stdlib.h>
#include <snake.h>
#include <food.h>
#include <ncurses.h>

Snake snake;

void initSnake(int x, int y) {
    snake.body = (SnakeSegment*)malloc(100 * sizeof(SnakeSegment));
    if (snake.body == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    snake.length = 1;
    snake.body[0].x = x;
    snake.body[0].y = y;
    snake.direction = KEY_RIGHT;
}

