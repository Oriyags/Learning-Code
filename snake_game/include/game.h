#ifndef GAME_H
#define GAME_H
extern int is_game_over;

void initialize_game();
void run_game();
void clean_up_game();
int kbhit();
#endif