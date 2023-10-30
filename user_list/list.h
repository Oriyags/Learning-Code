#if !defined(LIST_H)
#define LIST_H

#include "colors.h"

// Structure to represent a list
typedef struct {
    int* data;
    int size;
} List;

// Initialize a list
void initialize_list(List* list);

// Add an item to the list
void push(List* list, int number);

// Remove an item from the list
void remove_item(List* list, int index);

// Get the number of items in the list
int item_count(const List* list);

// Get the number at a specific index
int number_at_index(const List* list, int index);

// Change an item at a specific index
void change_item(List* list, int index, int number);

// Clear the list
void clear_list(List* list);

#endif
