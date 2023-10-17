#ifndef LIST_H
#define LIST_H

typedef struct {
    int* data;
    int size;
} List;

void initializeList(List* list);
void push(List* list, int number);
void removeItem(List* list, int index);
int item_count(const List* list);
int number_at_index(const List* list, int index);
void change_item(List* list, int index, int number);
void clearList(List* list);

#endif

