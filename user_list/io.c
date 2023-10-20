#include <stdio.h>
#include <stdlib.h>
#include "io.h"


void print_list(const int* list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// [CR] sounds like 2 functions to me... Single responsibility!!!, each function does one thing and one thing only!
int display_menu_and_get_choice() {
    int choice;

    printf(ANSI_COLOR_GREEN "\nMENU:\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_PINK "1. Add an item\n");
    printf("2. Remove an item\n");
    printf("3. Clear the list\n");
    printf("4. List all items\n");
    printf("5. Exit\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_PINK "Enter your choice (1-5): " ANSI_COLOR_RESET);

    char input[100];
    fgets(input, sizeof(input), stdin);
    choice = atoi(input);

    return choice;
}


int get_user_choice() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    int choice = atoi(input);
    return choice;
}
