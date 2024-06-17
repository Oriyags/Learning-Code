#include <chance.h>
#include <msgs.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Declarations of the chance's functions */
static void pay_each_player(player_t *player, game_t *game);
static void go_to_jail(player_t *player, game_t *game);           
static void collect_money(player_t *player, game_t *game);       
static void move_forward_two_spaces(player_t *player, game_t *game);           
static void move_back_three_spaces(player_t *player, game_t *game);

// Array of the chance's functions (cards)
static const chance_card_t chance_cards[] = {
    {pay_each_player},
    {go_to_jail},
    {collect_money},
    {move_forward_two_spaces},
    {move_back_three_spaces}
};

// Runs on the arr of chance's functions (cards)
void draw_chance_card(player_t *player, game_t *game) {
    int card = rand() % (sizeof(chance_cards) / sizeof(chance_cards[0])); //
    chance_cards[card].effect(player, game);                              //
}

/* Money goes from the current player's personal money
    and divided between the other players' personal money. */
static void pay_each_player(player_t *player, game_t *game) {
    MSG_CHANCE_CARD_PEP(player->name);      // prints the current acts on the screen
    for (int i = 0; i < game->player_num; i++)
    {
        /* code */
    }
    

}

/* Sets the current player's position to jail's,
    changes their statuse to isInJail
        and makes them wait for two rounds. */
static void go_to_jail(player_t *player, game_t *game) {
    MSG_CHANCE_CARD_GTJ(player->name);      // prints the current acts on the screen


}           

/* Adds 150$ to the current
    player's personal money */
static void collect_money(player_t *player, game_t *game) {
    MSG_CHANCE_CARD_MONEY(player->name);    // prints the current acts on the screen
    player->money += 150;
}    

/* Moves the player position
    2 steps forward. */
static void move_forward_two_spaces(player_t *player, game_t *game) {
    MSG_CHANCE_CARD_FORWARD(player->name);  // prints the current acts on the screen
    player->position += 2;
}         

/* Moves the player position
    3 steps backwards. */
static void move_back_three_spaces(player_t *player, game_t *game) {
    MSG_CHANCE_CARD_BACK(player->name);     // prints on screen the current acts
    player->position -= 3;
}