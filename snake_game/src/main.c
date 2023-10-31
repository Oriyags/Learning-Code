#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "game.h"
#include "game_board.h"
#include "print.h"

int main() {
    initscr();
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {
        clear();
        printw("Press Enter to start the game.");
        refresh();
        getch(); // Wait for Enter key press
        clear();

        initialize_game();
        run_game();

        // Ask the player if they want to play again
        if (!is_game_over) {
            printw("Play again? (Y/N): ");
            choice = getch();
        } else {
            printw("Game Over. Play again? (Y/N): ");
            choice = getch();
        }

        if (choice == 'n' || choice == 'N') {
            break;
        }

        is_game_over = 0;
        initialize_game_board();
    }

    endwin();
    return 0;
}