#if !defined(SNAKE_H)
#define SNAKE_H

extern const int width;
extern const int height;

void Setup_snake();
void Draw_snake();
void Move_snake();
int Check_collision();
void Check_food_collision();

#endif
