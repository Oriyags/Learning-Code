#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;   /* Number of elements in the list */
} List;

/* Initialize a list (allocate memory to the list) */
void initialize_list(List* list) {
    list->data = NULL;  /* Initialize data pointer to NULL */
    list->size = 0;    /* Initialize the number of elements in the list to 0 */
}

/* Add an item to the end of the list */
void push(List* list, int number) {
    /* Increase its size by one */
    list->data = (int*)realloc(list->data, (list->size + 1) * sizeof(int));
    /* Assign 'number' to the end of the list */
    list->data[list->size] = number;
    /* Increment the 'size' of the list */
    list->size++;
}

/* Remove an item by index from the list */
void remove_from_list(List* list, int index) {
    /* Check if the index is valid */
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }
    /* Shift elements to fill the gap */
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    /* Reduce the size of the list */
    list->size--;
    /* Shrink the memory */
    list->data = (int*)realloc(list->data, list->size * sizeof(int));
}

/* Get the number of items in the list */
int item_count(const List* list) {
    return list->size;
}

/* Get an item by index from the list */
int number_at_index(const List* list, int index) {
    /* Check if the index is valid */
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return -1;
    }
    return list->data[index];
}

/* Modify an item by index in the list */
void change_item(List* list, int index, int number) {
    /* Check if the index is valid */
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }
    list->data[index] = number;
}

/* Delete the list and free associated memory */
void delete_list(List* list) {
    if (list->data) { /* Check to avoid double-freeing memory */
        free(list->data); /* Free the memory allocated for the data array */
        list->data = NULL; /* Set the data pointer to NULL */
    }
    list->size = 0; /* Reset the size of the list to zero */
}

int main() {
    List my_list;
    initialize_list(&my_list); /* Initialize the list */

    /* Add to the list */
    push(&my_list, 42);
    push(&my_list, 17);
    push(&my_list, 95);

    /* Print the items in the list */
    printf("First list:\n");
    for (int i = 0; i < item_count(&my_list); i++) {
        printf("Item %d: %d\n", i, number_at_index(&my_list, i));
    }

    /* Modify an item in the list */
    change_item(&my_list, 1, 56);

    printf("Second list:\n");
    /* Print the modified list */
    for (int i = 0; i < item_count(&my_list); i++) {
        printf("Item %d: %d\n", i, number_at_index(&my_list, i));
    }

    /* Remove an item from the list */
    remove_from_list(&my_list, 0);

    printf("Third list:\n");
    /* Print the final list */
    for (int i = 0; i < item_count(&my_list); i++) {
        printf("Item %d: %d\n", i, number_at_index(&my_list, i));
    }

    /* Clean up and free the memory */
    delete_list(&my_list);

    return 0;
}