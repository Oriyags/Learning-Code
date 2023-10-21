#include <stdio.h>
#include "io.h"
#include "list.h"
#include "logic.h"
#include "colors.h" 

int main() {
    List my_list;
    initialize_list(&my_list);

    printf(ANSI_COLOR_GREEN "Welcome to the List Manipulation Program!\n" ANSI_COLOR_RESET);

    run_list_program(&my_list);

    return 0;
}

