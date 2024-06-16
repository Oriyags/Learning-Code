#if !defined(MSGS_H)
#define MSGS_H

/*
#define MSG_COMMUNITY_CARD_BASE(player_name, card_msg) do { \
    printf("%s draws a Community Chest card: %s", player_name, card_msg); \
} while(0)
*/

// Global message when taking a community chest card
#define MSG_COMMUNITY_CARD_BASE(player_name, card_msg) printf("%s draws a Community Chest card: %s", player_name, card_msg)

// The player is told to go to start point and get money
#define MSG_COMMUNITY_CARD_ATG(player_name) MSG_COMMUNITY_CARD_BASE(player_name, "Advance to Go. Collect $200.")

// The player is told to pay taxes
#define MSG_COMMUNITY_CARD_TAXES(player_name) MSG_COMMUNITY_CARD_BASE(player_name, "Pay $50 in taxes.")

// The player is told he won money
#define MSG_COMMUNITY_CARD_SURPRISE(player_name) MSG_COMMUNITY_CARD_BASE(player_name, "Surprise! +20$ for your amazing gardening skills.")

// The player is told to pay money
#define MSG_COMMUNITY_CARD_DOCTOR(player_name) MSG_COMMUNITY_CARD_BASE(player_name, "Oh no, you are sick. Pay 50$ for the treatment.")

// The player is told he got a ticket to get out of jail
#define MSG_COMMUNITY_CARD_GOOJ(player_name) MSG_COMMUNITY_CARD_BASE(player_name, "Get-out-of-jail ticket!")


// Global message when taking a chance card
#define MSG_CHANCE_CARD_BASE(player_name, card_msg) printf("%s draws a Chance card: %s", player_name, card_msg)

// The player is told to go to start point and get money
#define MSG_CHANCE_CARD_PEP(player_name) MSG_CHANCE_CARD_BASE(player_name, "Pay each player 10$.")

// The player is told to pay taxes
#define MSG_CHANCE_CARD_GTJ(player_name) MSG_CHANCE_CARD_BASE(player_name, "Go to jail.")

// The player is told he won money
#define MSG_CHANCE_CARD_MONEY(player_name) MSG_CHANCE_CARD_BASE(player_name, "Collect 150$ for your fashion show.")

// The player is told to pay money
#define MSG_CHANCE_CARD_FORWARD(player_name) MSG_CHANCE_CARD_BASE(player_name, "Move two steps forward.")

// The player is told he got a ticket to get out of jail
#define MSG_CHANCE_CARD_BACK(player_name) MSG_CHANCE_CARD_BASE(player_name, "Move 3 steps backwards.")

#endif