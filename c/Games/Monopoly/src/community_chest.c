#include <community_chest.h>
#include <msgs.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Declarations of the community chest functions */
static void advance_to_go(player_t *player, game_t *game);
static void taxes(player_t *player, game_t *game);
static void surprise(player_t *player, game_t *game);
static void doctor_fees(player_t *player, game_t *game);
static void get_out_of_jail(player_t *player, game_t *game);

// Array of the community chest's functions (cards)
static const community_chest_t community_cards[] = {
    {advance_to_go},
    {taxes},
    {surprise},
    {doctor_fees},
    {get_out_of_jail}
};

// Runs on the arr of community chest's functions (cards)
void draw_community_chest_card(player_t *player, game_t *game) {
    int card = rand() % (sizeof(community_cards) / sizeof(community_cards[0])); //
    community_cards[card].effect(player, game);                                 //
}

/* Sets the player's current position to 0 
    and adds 200$ to their personal money */
static void advance_to_go(player_t *player, game_t *game) {
    MSG_COMMUNITY_CARD_ATG(player->name);      // prints the current acts on the screen
    player->position = 0;                 
    player->money += ATG_MONEY;
}

/* Charges the player with 50$
    from their personal money */
static void taxes(player_t *player, game_t *game) {
    MSG_COMMUNITY_CARD_TAXES(player->name);    // prints the current acts on the screen
    player->money -= 50;
}

/* Adds 20$ to the player's
    personal money */
static void surprise(player_t *player, game_t *game) {
    MSG_COMMUNITY_CARD_SURPRISE(player->name); // prints the current acts on the screen
    player->money += 20;
}

/* Charges the player with 50$
    from their personal money */
static void doctor_fees(player_t *player, game_t *game) {
    MSG_COMMUNITY_CARD_DOCTOR(player->name);   // prints the current acts on the screen
    player->money -= 50;
}

/* Adds 1 get-out-of-jail card
    to the player's personal amount */
static void get_out_of_jail(player_t *player, game_t *game) {
    MSG_COMMUNITY_CARD_GOOJ(player->name);     // prints the current acts on the screen
    player->jail_cards += 1;
}