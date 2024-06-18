#include <game.h>
#include <board.h>
#include <stdio.h>
#include <stdlib.h>


void initializeGame(game_t *game, int player_num) {
    game->player_num = player_num;

    for (int i = 0; i < game->player_num; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", game->players[i].name);  // Assuming `name` is a char array in player_t
        game->players[i].position = 0;       // Start at Go
        game->players[i].money = 1500;     // Starting balance
        game->players[i].is_in_jail = false;
        game->players[i].jail_turns = 0;
    }

    game->current_player_index = 0;
    game->num_properties = 40;
}

// void handlePlayerTurn(game_t *game, Square board[NUM_SQUARES], Property properties[]) {
//     player_t *currentPlayer = &game->players[game->currentPlayerIndex];
    
//     printf("It's %s's turn.\n", currentPlayer->name);
//     int diceRoll = rollDice();
//     printf("%s rolled a %d.\n", currentPlayer->name, diceRoll);

//     currentPlayer->position = (currentPlayer->position + diceRoll) % NUM_SQUARES;
//     Square *currentSquare = &board[currentPlayer->position];

//     handleLanding(currentPlayer, currentSquare, game);

//     game->currentPlayerIndex = (game->currentPlayerIndex + 1) % game->player_num;
// }