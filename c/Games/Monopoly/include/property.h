#if !defined(PROPERTY_H)
#define PROPERTY_H

typedef struct
{
    char name[50];
    int id;
    int ownerId;
    int cost;
    int rent;
    int housecost;
    int hotelCost;
    int numOfHouses;
    bool hasHotel;
} property_t;

#endif