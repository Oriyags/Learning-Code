#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "io.h"
#include "list.h"

int main() {
    List my_list;
    initialize_list(&my_list);

    char input[100];
    char command[10];
    char argument[10];

    printf(ANSI_COLOR_GREEN "Welcome to the List Manipulation Program!\n" ANSI_COLOR_RESET);

    while (1) {
        // Print the "MENU" in green
        printf(ANSI_COLOR_GREEN "\nMENU:\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "1. Add an item\n");
        printf("2. Remove an item\n");
        printf("3. Clear the list\n");
        printf("4. List all items\n");
        printf("5. Exit\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "Enter your choice (1-5): " ANSI_COLOR_RESET);

        // Read the user's choice and convert it to an integer
        fgets(input, sizeof(input), stdin);
        int choice = atoi(input);

        switch (choice) {
            case 1:
                printf(ANSI_COLOR_PINK "Enter a number to add: " ANSI_COLOR_RESET);
                fgets(input, sizeof(input), stdin);
                int number = atoi(input);
                push(&my_list, number);
                break;
            case 2:
                printf(ANSI_COLOR_PINK "Enter the index to remove: " ANSI_COLOR_RESET);
                fgets(input, sizeof(input), stdin);
                int index = atoi(input);
                remove_item(&my_list, index);
                break;
            case 3:
                clear_list(&my_list);
                printf(ANSI_COLOR_PINK "List cleared.\n" ANSI_COLOR_RESET);
                break;
            case 4:
                printf(ANSI_COLOR_YELLOW "Current list: " ANSI_COLOR_RESET);
                print_list(my_list.data, my_list.size);
                printf(ANSI_COLOR_RESET); // Reset to default color
                break;
            case 5:
                clear_list(&my_list);
                printf(ANSI_COLOR_PINK "Goodbye! :)\n" ANSI_COLOR_RESET);
                return 0;
            default:
                printf(ANSI_COLOR_PINK "Invalid choice. Please enter a number between 1 and 5.\n" ANSI_COLOR_RESET);
        }
    }
}

