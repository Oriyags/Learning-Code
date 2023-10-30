#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "list.h"
#include "colors.h"

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
        case 5:
            printf(ANSI_COLOR_PINK "Goodbye! :)\n" ANSI_COLOR_RESET);
            clear_list(my_list); // Clear the list before exiting
            exit(0); // Exit the program when the user enters 5
        default:
            printf(ANSI_COLOR_PINK "Invalid choice. Please enter a number between 1 and 5.\n" ANSI_COLOR_RESET);
    }
}

// Run the list manipulation program [CR] move this code into the main function, this function is useless
void run_list_program(List* my_list) {
    int choice;
    while (1) {
        display_menu();
        choice = get_user_choice();

        process_choice(my_list, choice); // Call process_choice for all choices
    }
}
