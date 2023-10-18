#include <stdio.h>
#include <string.h>
#include "io.h"

// Function to print the list
void print_list(const int* list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
