#include <stdio.h>
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
    if (scanf("%d", &choice) != 1) {
        printf(ANSI_COLOR_PINK "Invalid input. Please enter a number.\n" ANSI_COLOR_RESET);
        while (getchar() != '\n'); // Clear the input buffer
        return get_user_choice(); // Retry getting the choice
    }
    while (getchar() != '\n'); // Clear the newline character
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

// Add an item to the list
void process_add_item(List* my_list) {
    int number;
    printf(ANSI_COLOR_PINK "Enter a number to add: " ANSI_COLOR_RESET);
    if (scanf("%d", &number) != 1) {
        printf(ANSI_COLOR_PINK "Invalid input. Please enter a number.\n" ANSI_COLOR_RESET);
        // Clear the input buffer to prevent an infinite loop.
        while (getchar() != '\n');
        return;
    }
    push(my_list, number);
}

// Removing an item from the list
void process_remove_item(List* my_list) {
    int index;
    printf(ANSI_COLOR_PINK "Enter the index to remove: " ANSI_COLOR_RESET);
    if (scanf("%d", &index) != 1) {
        printf(ANSI_COLOR_PINK "Invalid input. Please enter a number.\n" ANSI_COLOR_RESET);
        // Clear the input buffer to prevent an infinite loop.
        while (getchar() != '\n');
        return;
    }
    remove_item(my_list, index);
}

// Clear the list
void process_clear_list(List* my_list) {
    clear_list(my_list);
    printf(ANSI_COLOR_PINK "List cleared.\n" ANSI_COLOR_RESET);
}

// List items in the list
void process_list_items(const List* my_list) {
    printf(ANSI_COLOR_YELLOW "Current list: " ANSI_COLOR_RESET);
    print_list(my_list->data, my_list->size);
    printf(ANSI_COLOR_RESET);
}
