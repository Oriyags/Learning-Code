#include "game.h"
#include "food.h"
#include "snake.h"
#include "ui.h"
#include "logic.h"
#include <unistd.h>

const int width = 35;
const int height = 20;

int main() {
    struct game_state state;
    setup(&state); // Initialize the game
    while (!state.gameOver) {
        // [CR] [PROTOYPE] auto_snake(const [game state], *[snake's direction]);
        draw(&state);  // Draw the game board
        logic(&state); // Execute game logic
        usleep(100000); // Delay for 100 milliseconds
    }
    return 0;
}