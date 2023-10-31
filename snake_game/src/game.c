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
int game_board[BOARD_HEIGHT][BOARD_WIDTH];
int score;
int is_game_over = 0;
int game_in_progress = 0;
int game_stage = 0;
int food_displayed = 0; // Keep track of food display

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

// Initialize the game
void initialize_game() {
    initscr(); // Initialize ncurses mode
    cbreak(); // Disable line buffering
    noecho(); // Disable automatic echoing of input
    nodelay(stdscr, TRUE); // Enable non-blocking input
    curs_set(0); // Hide the cursor

    initialize_game_board();
    initialize_snake(BOARD_WIDTH / 2, BOARD_HEIGHT / 2); // Set the initial position of the snake
    score = 0;
    is_game_over = 0;
    game_stage = 0; // Start at stage 0
    food_displayed = 0;
}

// Define the kbhit function using ncurses
int kbhit() {
    int ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

void run_game() {
    game_in_progress = 1;
    int key;
    int gameStarted = 0;  // Indicates if the game has started

    clear_screen();
    print_board(score);

    while (!is_game_over) {
        if (kbhit()) {
            key = getch();
            if (!gameStarted && key == '\n') {
                gameStarted = 1;
                game_stage++; // Increment the game stage

                if (game_stage == 1) {
                    initialize_game_board(); // Clear the board
                    clear_screen();
                    print_board(score);
                } else if (game_stage == 2) {
                    clear_screen();
                    initialize_snake(BOARD_WIDTH / 2, BOARD_HEIGHT / 2); // Reset the snake
                    print_board(score);
                } else if (game_stage == 3) {
                    clear_screen();
                    generate_food();
                    print_board(score);
                    food_displayed = 1;
                } else if (game_stage == 4) {
                    move_snake_auto();
                    clear_screen();
                    print_board(score);
                } else if (game_stage == 5) {
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
                } else if (game_stage == 6) {
                    is_game_over = 1;
                    game_over(is_game_over);
                }
            }
        }

        usleep(GAME_SPEED * 1000);
    }

    while (1) {
        key = getch();
        if (key == '\n') {
            break;
        }
    }

    clear_screen();
    refresh();
    game_in_progress = 0;
}