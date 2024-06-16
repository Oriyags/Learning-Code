#if !defined(PROPERTY_H)
#define PROPERTY_H

// Property's struct
typedef struct
{
    char name[50];  // property's name
    int id;         // property's id
    int ownerId;    // id of the property'sowner
    int cost;       // property's cost
    int rent;       // property's rent
    int housecost;  // how much a house costs on the property
    int hotelCost;  // how much a hotel costs on the property
    int houses_num; // how many houses are on the property
    bool hasHotel;  // checks if there's a hotel on the property
} property_t;

#endif