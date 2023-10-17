#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // Include this line
#include "io.h"
#include "list.h"

int main() {
    List my_list;
    initializeList(&my_list);

    char input[256];
    char command[20];
    char argument[20];

    while (1) {
        printList(my_list.data, my_list.size);
        printf("Enter a command ('list', 'add', 'rem', 'clear', 'exit'): ");
        fgets(input, sizeof(input), stdin);
        int result = parseInput(input, command, argument);

        if (result == 2) {
            if (strcmp(command, "list") == 0) {
                printList(my_list.data, my_list.size);
            } else if (strcmp(command, "add") == 0) {
                int number = atoi(argument);
                push(&my_list, number);
            } else if (strcmp(command, "rem") == 0) {
                int index = atoi(argument);
                removeItem(&my_list, index);
            } else if (strcmp(command, "clear") == 0) {
                clearList(&my_list);
            } else if (strcmp(command, "exit") == 0) {
                break;
            } else {
                printf("Invalid command. Please try again.\n");
            }
        }
    }

    clearList(&my_list);

    return 0;
}

