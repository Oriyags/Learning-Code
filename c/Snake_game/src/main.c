#include "game.h"
#include "food.h"
#include "snake.h"
#include "ui.h"
#include "logic.h"
#include <unistd.h>

const int width = 35;
const int height = 20;

int main() {
    Setup(); // Initialize the game
    while (!gameOver) {
        Draw();  // Draw the game board
        Logic(); // Execute game logic
        usleep(100000); // Delay for 100 milliseconds
    }
    return 0;
}
