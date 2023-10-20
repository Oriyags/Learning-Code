#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "list.h"
#include "logic.h"

void process_choice(List* my_list, int choice) {
    switch (choice) {
        case 1:
            printf(ANSI_COLOR_PINK "Enter a number to add: " ANSI_COLOR_RESET);
            char input[100];
            fgets(input, sizeof(input), stdin);
            int number = atoi(input);
            push(my_list, number);
            break;
        case 2:
            printf(ANSI_COLOR_PINK "Enter the index to remove: " ANSI_COLOR_RESET);
            fgets(input, sizeof(input), stdin);
            int index = atoi(input);
            remove_item(my_list, index);
            break;
        case 3:
            clear_list(my_list);
            printf(ANSI_COLOR_PINK "List cleared.\n" ANSI_COLOR_RESET);
            break;
        case 4:
            printf(ANSI_COLOR_YELLOW "Current list: " ANSI_COLOR_RESET);
            print_list(my_list->data, my_list->size);
            printf(ANSI_COLOR_RESET); // Reset to default color
            break;
        case 5:
            clear_list(my_list);
            printf(ANSI_COLOR_PINK "Goodbye! :)\n" ANSI_COLOR_RESET);
            break;
        default:
            printf(ANSI_COLOR_PINK "Invalid choice. Please enter a number between 1 and 5.\n" ANSI_COLOR_RESET);
    }
}

