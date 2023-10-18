#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "io.h"
#include "list.h"

/* [CR]
Your program structure (AKA design) is one of the most important things to keep in mind in order to write good code.
The goal of the program can be achieved by combining many small tasks. 
Each task should have its own "area" in the program, and that "area" will handle this task and this task only (AKA single responsibilty).
E.g., if you need to handle input, you will create a script (file) for handling the input.
This file is the only file that should handle input, so if another script want to get input, it will include the input.h file and use its services.
Each function of a file should also follow the single responsibility rule, meaning each function will do one thing and one thing only.
E.g, if you have a function "get_input" in input.c with the purpose of getting a string input from the user, this function should not
also process the input (e.g. checking if the input is equal to "exit" and exit the program), yet another function (e.g. process_input function)
should process the string recieved and call the corresponding function to handle the command.

!!IMPORTANT!!
Same thing with your main function.
The goal of the main function is to connect the utils/tasks/function of your program into a single program and nothing more.
The main function should not handle input, output, memory allocation or any other stuff that is not related to initializing and connecting your program.
*/

int main() {
// [CR] this part is a *good* example for what the main function should do (initializing)
    List my_list;
    initialize_list(&my_list);

// [CR] this is a bad example for what the main function should do (handling input)
    char input[100];
    char command[10];
    char argument[10];

// [CR] a welcome message to the program is fine in the main file
    printf(ANSI_COLOR_GREEN "Welcome to the List Manipulation Program!\n" ANSI_COLOR_RESET);

// [CR] looping forever and calling the needed function is a good thing to do in main
// [CR] but you handled input, output and logic in there (not good). that's why you create an io.c file, to handle input/output and input processing.
    while (1) {
//[CR] should not be here
        // Print the "MENU" in green
        printf(ANSI_COLOR_GREEN "\nMENU:\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "1. Add an item\n");
        printf("2. Remove an item\n");
        printf("3. Clear the list\n");
        printf("4. List all items\n");
        printf("5. Exit\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "Enter your choice (1-5): " ANSI_COLOR_RESET);

// [CR] should not be here
        // Read the user's choice and convert it to an integer
        fgets(input, sizeof(input), stdin);
        int choice = atoi(input);

// [CR] should not be here
        switch (choice) {
            case 1: // [CR] when using switch comment on each case what does it mean (see case 2 for example)
                printf(ANSI_COLOR_PINK "Enter a number to add: " ANSI_COLOR_RESET);
                fgets(input, sizeof(input), stdin);
                int number = atoi(input);
                push(&my_list, number);
                break;
            case 2: // [CR] (example comment) Command 2: remove an item from the list
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

