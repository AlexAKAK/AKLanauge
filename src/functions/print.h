#include "./../utilities.h"

void print_func(char ** after_call, unsigned int token_count) {
    unsigned int i = 0;
    unsigned int after_token_count = token_count - 1;
    for (i;i<after_token_count;i++) {
        printf("%s ", after_call[i]);
    }
    printf("\n");

}