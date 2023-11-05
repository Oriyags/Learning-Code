#if !defined(SNAKE_H)
#define SNAKE_H

// Game board's width and height
extern const int width;
extern const int height;

void Setup_snake();         // Initialize the snake
void Draw_snake();          // Draw the snake on the game board
void Move_snake();          // Move the snake
int Check_collision();      // Check for collisions with the snake
void Check_food_collision(); // Check for collisions with food
int Check_corner_collision(); // Check for collisions with corners

#endif
