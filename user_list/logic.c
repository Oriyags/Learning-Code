#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "list.h"
#include "logic.h"
#include "colors.h"

// Add an item to the list
void process_add_item(List* my_list) {
    int number;
    printf(ANSI_COLOR_PINK "Enter a number to add: " ANSI_COLOR_RESET);
    scanf("%d", &number);
    push(my_list, number);
}

// Removing an item from the list
void process_remove_item(List* my_list) {
    int index;
    printf(ANSI_COLOR_PINK "Enter the index to remove: " ANSI_COLOR_RESET);
    scanf("%d", &index);
    remove_item(my_list, index);
}

// Clearing the list
void process_clear_list(List* my_list) {
    clear_list(my_list);
    printf(ANSI_COLOR_PINK "List cleared.\n" ANSI_COLOR_RESET);
}

// Listing items in the list
void process_list_items(List* my_list) {
    printf(ANSI_COLOR_YELLOW "Current list: " ANSI_COLOR_RESET);
    print_list(my_list->data, my_list->size);
    printf(ANSI_COLOR_RESET);
}

// Process user choice
void process_choice(List* my_list, int choice) {
    switch (choice) {
        case 1:
            process_add_item(my_list);
            break;
        case 2:
            process_remove_item(my_list);
            break;
        case 3:
            process_clear_list(my_list);
            break;
        case 4:
            process_list_items(my_list);
            break;
        default:
            printf(ANSI_COLOR_PINK "Invalid choice. Please enter a number between 1 and 4.\n" ANSI_COLOR_RESET);
    }
}

// Run the program
void run_list_program(List* my_list) {
    int choice;
    while (1) {
        display_menu();
        choice = get_user_choice();

        if (choice == 5) {
            clear_list(my_list);
            printf(ANSI_COLOR_PINK "Goodbye! :)\n" ANSI_COLOR_RESET);
            break;
        } else {
            process_choice(my_list, choice);
        }
    }
}

