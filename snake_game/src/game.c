#include <stdlib.h>
#include <ncurses.h>
#include <game.h>
#include <snake.h>
#include <food.h>

static int gameWidth, gameHeight;
static Food food;
extern Snake snake;

void initGame(int width, int height) {
    gameWidth = width;
    gameHeight = height;
    initSnake(width / 2, height / 2);
    food = createFood(gameWidth, gameHeight);
}

void updateGame() {
    moveSnake();

    if (isFoodEaten(food, snake.body[0].x, snake.body[0].y)) {
        snake.length++;
        food = createFood(gameWidth, gameHeight);
    }

    if (isGameOver()) {
        mvprintw(gameHeight / 2, gameWidth / 2 - 10, "Game Over! Press 'q' to quit.");
    }
}

void closeGame() {
    free(snake.body);
}

int isGameOver() {
    int headX = snake.body[0].x;
    int headY = snake.body[0].y;

    // Check if the snake has hit a wall (assuming gameWidth and gameHeight define your game area's boundaries).
    if (headX <= 0 || headX >= gameWidth - 1 || headY <= 0 || headY >= gameHeight - 1) {
        return 1; // Game over, as the snake has hit a wall.
    }

    // Check if the snake has collided with itself.
    for (int i = 1; i < snake.length; i++) {
        if (headX == snake.body[i].x && headY == snake.body[i].y) {
            return 1; // Game over, as the snake has collided with itself.
        }
    }

    return 0; // The game is not over.
}

