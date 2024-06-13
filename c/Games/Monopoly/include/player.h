#if !defined(PLAYER_H)
#define PLAYER_H

#include <stdbool.h>
#include <property.h>

typedef struct {
    char name[20];
    int money;
    bool bankRupt;
    int position;
    bool isJail;
    int jailCards;
    int jailTurns;
    int numOfHouses;
    int numOfHotels;
    property_t propertiesOwned[];
} player_t;

#endif