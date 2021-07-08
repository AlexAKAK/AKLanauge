#include "./../utilities.h"

void exit_func(char ** after_call, unsigned int token_count) {
    printf("-----------Aborting runtime-----------\n");
    if (after_call[0] == "0") exit(0);
    else exit(1);
}