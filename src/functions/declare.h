#include "./../utilities.h"
#include "./../error_check_for_func.h"
#include "./../boolean.h"


BOOLEAN declare_func(char ** after_call, unsigned int token_count) {
    if (at_least_two_args_required_err_check(after_call, token_count) == TRUE) return FALSE;
    char * type = after_call[0];
    



    return TRUE;
}