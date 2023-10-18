#ifndef LIST_H
#define LIST_H

// Define the List structure
typedef struct {
    int* data;
    int size;
} List;

// Function prototypes for list manipulation
void initialize_list(List* list);
void push(List* list, int number);
void remove_item(List* list, int index);
int item_count(const List* list);
int number_at_index(const List* list, int index);
void change_item(List* list, int index, int number);
void clear_list(List* list);

#endif
