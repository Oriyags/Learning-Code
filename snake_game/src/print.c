#include <stdio.h>
#include <ncurses.h>
#include "print.h"
#include "game_board.h"

// Clear the screen
void clear_screen() {
    refresh(); // Refresh the screen using ncurses
}

// Print the game board and score
void print_board(int score) {
    clear_screen();
    printw("Snake Game\n");
    printw("Score: %d\n", score);

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printw("%c", game_board[i][j]);
        }
        printw("\n");
    }
    refresh(); // Update the screen
}

// Display the "Game Over" message
void game_over(int is_game_over) {
    clear_screen();
    printw("Game Over\n");
    refresh(); // Update the screen
}

// Set the cursor position on the terminal
void gotoxy(int x, int y) {
    move(x, y);
}