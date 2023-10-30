#include <stdio.h>
#include "list.h"
#include "logic.h"
#include "colors.h"

int main() {
    List my_list;
    initialize_list(&my_list);

    printf(ANSI_COLOR_GREEN "Welcome to the List Manipulation Program!\n" ANSI_COLOR_RESET);

/* 
[CR] Already told you this in the last CR: this function (run_list_program) should not exist at all, "run list program" is what the main function do, its whole purpose.
The main function should have the main program loop (while(1)) that calls other functions and utils.
The code from run_list_program SHOULD be in the main function.
*/
    run_list_program(&my_list);

    clear_list(&my_list); // Clear the list before exiting
    
    return 0;
}
