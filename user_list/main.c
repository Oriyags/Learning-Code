#include <stdio.h>
#include "io.h" // [CR] you don't use anything from io.h in here, there is no need to include it
#include "list.h"
#include "logic.h"
#include "colors.h" 

// [CR] you have a bug: for some reason entering a letter as an input will break your program.

int main() {
    List my_list;
    initialize_list(&my_list);

    printf(ANSI_COLOR_GREEN "Welcome to the List Manipulation Program!\n" ANSI_COLOR_RESET);

    run_list_program(&my_list);

    return 0;
}

