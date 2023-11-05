#if !defined(GAME_H)
#define GAME_H

#include "snake.h"

extern int gameOver;

void Setup(); // Initialize the game
void Draw();  // Draw the game board
void Logic(); // Perform game logic

#endif
