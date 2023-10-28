#ifndef SNAKE_H
#define SNAKE_H

void initialize_snake(int startX, int startY);
void move_snake_auto();
void move_snake(char key);
int check_collision();
int get_snakeX(int index);
int get_snakeY(int index);

#endif