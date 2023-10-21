#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "colors.h"

// Print a list of integers
void print_list(const int* list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Get the user's choice
int get_user_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Display the menu
void display_menu() {
    printf(ANSI_COLOR_GREEN "\nMENU:\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_PINK "1. Add an item\n");
    printf("2. Remove an item\n");
    printf("3. Clear the list\n");
    printf("4. List all items\n");
    printf("5. Exit\n" ANSI_COLOR_RESET);
}

