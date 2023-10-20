#include <stdio.h>
#include "io.h"
#include "list.h"
#include "logic.h"

// [CR] COMMENT AS YOU WRITE

int main() {
    List my_list;
    initialize_list(&my_list);

    int choice;

    printf(ANSI_COLOR_GREEN "Welcome to the List Manipulation Program!\n" ANSI_COLOR_RESET);

    while (1) {
        choice = display_menu_and_get_choice();

	// [CR] should not be here!, main function should not handle logic. You already have a function for precessing input (process_choice)
	// [CR] why not just passing the parameters to it?. You can also exit the program from there (google it). 
        if (choice == 5) {
            clear_list(&my_list);
            printf(ANSI_COLOR_PINK "Goodbye! :)\n" ANSI_COLOR_RESET);
            break; // Exit the program
        } else {
            process_choice(&my_list, choice);
        }
    }

    return 0;
}

