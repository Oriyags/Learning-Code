#include <stdio.h>
#include "list.h"
#include "logic.h"
#include "colors.h"
#include "io.h"

int main() {
    List my_list;
    initialize_list(&my_list);

    printf(ANSI_COLOR_GREEN "Welcome to the List Manipulation Program!\n" ANSI_COLOR_RESET);

    int choice;
    while (1) {
        display_menu();
        choice = get_user_choice(); 
        process_choice(&my_list, choice);
    }

    clear_list(&my_list);

    return 0;
}
