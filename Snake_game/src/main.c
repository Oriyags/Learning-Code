#include "game.h"
#include <unistd.h> // Include the header for usleep

const int width = 20;
const int height = 10;

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Logic();
        usleep(100000); // Use usleep for a delay of 100 milliseconds
    }
    return 0;
}
