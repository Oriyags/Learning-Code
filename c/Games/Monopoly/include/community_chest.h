#if !defined(COMMUNITY_CHEST)
#define COMMUNITY_CHEST

#include <player.h>
#include <game.h>
#include <msgs.h>

#define STR_DESC_MAX 256 // max string

// Community chest's struct
typedef struct {
    void (*effect)(player_t *player, game_t *game);    // calls the Community chest's functions
} community_chest_t;

void draw_chance_card(player_t *player, game_t *game); // runs on the array of chance cards


#endif