#include "community_chest.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const community_chest_t cards[] = {
    {"Advance to Go. Collect $200.", advance_to_go},
    {"Pay $50 in taxes.", taxes},
    {"Surprise! +20$ for your amazing gardening skills.", surprise},
    {"Oh no, you are sick. Pay 50$ for the treatment.", doctor_fees},
    {"Get-out-of-jail ticket!", get_out_of_jail}
};

void draw_community_chest_card(player_t *player, game_t *game) {
    int card = rand() % 5;
    cards[card].effect(player, game);
}
void advance_to_go(player_t *player, game_t *game) {
    printf("%s draws a Community Chest card: Advance to Go. Collect 200$.\n", player->name);
    player->position = 0;
    player->money += 200;
}

void taxes(player_t *player, game_t *game) {
        printf("%s draws a Community Chest card: Pay 50$ in taxes.\n", player->name);
    player->money -= 50;
}
void surprise(player_t *player, game_t *game) {
        printf("%s draws a Community Chest card: +20$ for amazing gardening skills.\n", player->name);
    player->money -= 200;
}
void doctor_fees(player_t *player, game_t *game);
void get_out_of_jail(player_t *player, game_t *game);