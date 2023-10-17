#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initializeList(List* list) {
    list->data = NULL;
    list->size = 0;
}

void push(List* list, int number) {
    list->data = (int*)realloc(list->data, (list->size + 1) * sizeof(int));
    list->data[list->size] = number;
    list->size++;
}

void removeItem(List* list, int index) {
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

int item_count(const List* list) {
    return list->size;
}

int number_at_index(const List* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return -1;
    }
    return list->data[index];
}

void change_item(List* list, int index, int number) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }
    list->data[index] = number;
}

void clearList(List* list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
}
