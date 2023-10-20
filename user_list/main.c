#include <stdio.h>
#include "io.h"
#include "list.h"
#include "logic.h"

int main() {
    List my_list;
    initialize_list(&my_list);

    int choice;

    printf(ANSI_COLOR_GREEN "Welcome to the List Manipulation Program!\n" ANSI_COLOR_RESET);

    while (1) {
        choice = display_menu_and_get_choice();

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

