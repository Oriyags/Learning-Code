#if !defined(CHANCE)
#define CHANCE

#include "player.h"
#include "game.h"

typedef struct {
    char description[200];
    void(*effect)(player_t *player, game_t *game);
}ChanceCard;

#endif