#if !defined(IO_H)
#define IO_H

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_PINK "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"

void print_list(const int* list, int size);
int get_user_choice();
int display_menu_and_get_choice();

#endif

