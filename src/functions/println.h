#include "./../utilities.h"
#include "./../error_check_for_func.h"
#include "./../boolean.h"




BOOLEAN println_func(char ** after_call, unsigned int token_count, unsigned int line_number) {
    if (at_least_one_arg_required_err_check(after_call, token_count, line_number, "println") == TRUE) return FALSE;
    unsigned int i = 0;
    unsigned int after_token_count = token_count - 1;
    for (i;i<after_token_count;i++) {
        printf("%s ", after_call[i]);
    }
    printf("\n");

    return TRUE;
}