#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "list.h"
#include "colors.h"

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
            clear_list(my_list);
            exit(0);
        default:
            printf(ANSI_COLOR_PINK "Invalid choice. Please enter a number between 1 and 5.\n" ANSI_COLOR_RESET);
    }
}