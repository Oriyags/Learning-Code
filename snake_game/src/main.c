#include <ncurses.h>
#include <game.h>
#include <snake.h>
#include <display.h>

int main() {
    int width, height;
    initDisplay(&width, &height); // Removed unused variable

    initGame(width, height);

    while (!isGameOver()) {
        clearDisplay();
        updateGame();
        refreshDisplay();
    }

    getch();
    closeGame();
    closeDisplay();
    return 0;
}

