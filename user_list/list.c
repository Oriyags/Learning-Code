#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Function to initialize the list
void initialize_list(List* list) {
    list->data = NULL;
    list->size = 0;
}

// Function to add an item to the list
void push(List* list, int number) {
    list->data = (int*)realloc(list->data, (list->size + 1) * sizeof(int));
    list->data[list->size] = number;
    list->size++;
}

// Function to remove an item by index from the list
void remove_item(List* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
    list->data = (int*)realloc(list->data, list->size * sizeof(int));
}

// Function to get the number of items in the list
int item_count(const List* list) {
    return list->size;
}

// Function to get an item by index from the list
int number_at_index(const List* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return -1;
    }
    return list->data[index];
}

// Function to modify an item by index in the list
void change_item(List* list, int index, int number) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }
    list->data[index] = number;
}

// Function to delete the list and free associated memory
void clear_list(List* list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
}

