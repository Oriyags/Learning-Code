#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "game.h"
#include "game_board.h"
#include <unistd.h>
#include "print.h"
#include "snake.h"
#include "food.h"

// Variables to store the game state
int game_board[BOARD_HEIGHT][BOARD_WIDTH]; // Use the constants from game_board.h
int score;
int is_game_over = 0;

// Function to initialize the game board
void initialize_game_board() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (i == 0 || i == BOARD_HEIGHT - 1 || j == 0 || j == BOARD_WIDTH - 1) {
                game_board[i][j] = '#'; // Border of the game board
            } else {
                game_board[i][j] = ' '; // Empty space
            }
        }
    }
}

// Function to check if a key has been pressed
int kbhit() {
    int ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

// Initialize the game
void initialize_game() {
    initscr(); // Initialize ncurses mode
    cbreak(); // Disable line buffering
    noecho(); // Disable automatic echoing of input
    nodelay(stdscr, TRUE); // Enable non-blocking input
    curs_set(0); // Hide the cursor

    initialize_snake(BOARD_WIDTH / 2, BOARD_HEIGHT / 2);
    initialize_game_board();
    generate_food();
    score = 0;
    is_game_over = 0;
}

// Update and render the game in a loop
void run_game() {
    while (!is_game_over) {
        if (kbhit()) {
            char key = getch();
            move_snake(key);
        }

        move_snake_auto();
        int collision = check_collision();

        if (collision == -1) {
            is_game_over = 1;
            game_over(is_game_over);
        } else if (collision == 1) {
            score++;
            generate_food();
        }

        clear_screen();
        print_board(score);
        usleep(GAME_SPEED * 1000);
    }
}

// Clean up resources when the game ends
void clean_up_game() {
    endwin(); // End ncurses mode
}