#if !defined(CHANCE)
#define CHANCE

#include <player.h>
#include <game.h>
#include <msgs.h>

// Chance card's struct
typedef struct {
    void(*effect)(player_t *player, game_t *game);     // calls the Chance's functions
} chance_card_t;

void draw_chance_card(player_t *player, game_t *game); // runs on the array of community chest cards

#endif