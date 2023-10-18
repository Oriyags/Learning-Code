#ifndef IO_H // [CR] instead of #ifndef it is better to use "#if !defined(IO_H)"
#define IO_H

// Define ANSI color escape codes
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_PINK "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Function to print the list
void print_list(const int* list, int size);

#endif
