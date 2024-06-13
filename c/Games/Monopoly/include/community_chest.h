#if !defined(COMMUNITY_CHEST)
#define COMMUNITY_CHEST

#include "player.h"
#include "game.h"

#define STR_DESC_MAX 256

typedef struct {
    char description[STR_DESC_MAX];
    void (*effect)(player_t *player, game_t *game);
} community_chest_t;

void draw_community_chest_card(player_t *player, game_t *game);
void advanceToGoO(player_t *player, game_t *game);
void taxes(player_t *player, game_t *game);
void surprise(player_t *player, game_t *game);
void doctor_fees(player_t *player, game_t *game);
void get_out_of_jail(player_t *player, game_t *game);

#endif