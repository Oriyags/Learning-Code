#if !defined(FOOD_H)
#define FOOD_H

// Constants for game width and height
extern const int width;
extern const int height;

// Variables to store the coordinates of the food
extern int fruitX;
extern int fruitY;

void Setup_food(); // Set up the food
void Draw_food();  // Draw the food on the game board

#endif
