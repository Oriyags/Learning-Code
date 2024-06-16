#if !defined(GAME_H)
#define GAME_H

#define MAX_PLAYERS 4 // max players in the game
#define ATG_MONEY 200 // money given to the player after passing the start point
// #define 200
// #define 150
// #define 50
// #define 50
// #define 20
// #define 20
// #define 10
// #define

#include "player.h"
#include "property.h"
#include "board.h"

// 
typedef struct {
    player_t players[MAX_PLAYERS]; // array of players
    int player_num; // 
} game_t;

void initialize_game(game_t *game, int player_num);
//void player_turn(game_t *game, Square board[NUM_SQUARES], property_t properties[]); // handles the each player's turn
//void go_to_jail(player_t *player, game_t *game); // sends the player to jail /--might be static so no need it here--/
int roll_dice(); // rolls the dice

#endif