#if !defined(PLAYER_H)
#define PLAYER_H

#include <stdbool.h>
#include <property.h>

typedef struct {
    char name[20];                 // player's name
    int money;                     // player's personal money in $
    bool bankrupt;                 // checks if the player's out of money
    int position;                  // player's current position on the board
    bool is_in_jail;               // checks if the player is in jail
    int jail_cards;                // player's amount of jail cards
    int jail_turns;                // player's number of turns in jail
    int houses_num;                // number of houses the player  owns
    int hotels_num;                // number of hotels the player  owns
    property_t properties_owned[]; // .............
} player_t;

#endif