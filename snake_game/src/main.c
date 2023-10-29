#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "game.h"
#include "game_board.h"
#include "print.h"

int main() {
    initscr(); // Initialize ncurses mode
    initialize_game();

    // Main game loop
    while (!is_game_over) {
        run_game();

        // Ask the player if they want to play again
        printw("Play again? (Y/N): "); // Use printw for ncurses
        char choice = getch(); // Use getch for ncurses

        if (choice == 'n' || choice == 'N') {
            break; // Exit the game loop
        } else {
            is_game_over = 0;
            initialize_game_board(); // Reinitialize the game board
        }
    }

    endwin(); // End ncurses mode
    return 0;
}
