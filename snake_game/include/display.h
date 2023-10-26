#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h> // Include ncurses.h for the WINDOW type

WINDOW* initDisplay(int* width, int* height);
void clearDisplay();
void refreshDisplay();
void closeDisplay();

#endif

