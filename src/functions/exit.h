#include "./../utilities.h"
#include "./../error_check_for_func.h"
#include "./../boolean.h"


BOOLEAN exit_func(char ** after_call, unsigned int token_count) {
    if (at_least_one_arg_required_err_check(after_call, token_count) == TRUE) return FALSE;


    printf("-----------Aborting runtime-----------\n");
    if (after_call[0] == "0") exit(0);
    else exit(1);

    return TRUE;
}