#if !defined(IO_H)
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "list.h"

// Print a list of integers
void print_list(const int* list, int size);

// Get the user's choice
int get_user_choice();

// Display the menu
void display_menu();

// Add an item to the list
void process_add_item(List* my_list);

// Removing an item from the list
void process_remove_item(List* my_list);

// Clear the list
void process_clear_list(List* my_list);

// List items in the list
void process_list_items(const List* my_list);

#endif
