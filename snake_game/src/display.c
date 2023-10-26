#include <ncurses.h>
#include <display.h>

WINDOW* initDisplay(int* width, int* height) {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    getmaxyx(stdscr, *height, *width);
    start_color(); // Initialize color support, if needed
    return stdscr;
}

void clearDisplay() {
    clear();
}

void refreshDisplay() {
    refresh();
}

void closeDisplay() {
    endwin();
}

