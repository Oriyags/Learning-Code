#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "list.h"
#include "logic.h"
#include "colors.h"

// Add an item to the list
void process_add_item(List* my_list) {
    int number;
// [CR] this function should not handle user input.
    printf(ANSI_COLOR_PINK "Enter a number to add: " ANSI_COLOR_RESET);
    scanf("%d", &number);
    push(my_list, number);
}

// Removing an item from the list
void process_remove_item(List* my_list) {
    int index;
// [CR] you have an IO script that should handle Input and Output. This is a logic script that only handles logic.
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
// [CR] the function prints 3 things... it should not be in the logic script, it should be in the IO
// you already have a print_list function, it should handle all the printing and not let the function that calls it to do it.
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
// [CR] this function does way too much
// you already havea process list function, why do you process choice number 5 in here?
// [CR] this function should not exist at all, "run list program" is what the main function do, its whole purpose.
// the main function should have the main program loop (while(1)) that calls other functions and utils.
// moving the same code from the main to another function does not solve the problem.
void run_list_program(List* my_list) {
    int choice;
    while (1) {
        display_menu();
        choice = get_user_choice();

	// [CR] you already have a process choice function. only this function and this function only should handle choice processing.
        if (choice == 5) {
            clear_list(my_list);
            printf(ANSI_COLOR_PINK "Goodbye! :)\n" ANSI_COLOR_RESET);
            break;
        } else {
            process_choice(my_list, choice);
        }
    }
}

