#if !defined(GAME_H)
#define GAME_H

#include "player.h"
#include "property.h"
#include "board.h"

typedef struct {
    player_t players[4]; // Max players
    int currentPlayerIndex;
    int numPlayers;
} game_t;

void initializeGame(game_t *game, int numPlayers);
void handlePlayerTurn(game_t *game, Square board[NUM_SQUARES], Property properties[]);
void goToJail(player_t *player, game_t *game);
int rollDice();

#endif