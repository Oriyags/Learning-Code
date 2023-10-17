#include <stdio.h>
#include <string.h>
#include "io.h"

void printList(const int* list, int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int parseInput(const char* input, char* command, char* argument) {
    int result = sscanf(input, "%s %s", command, argument);
    return result;
}
