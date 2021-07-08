#include "./boolean.h"
#include "./raise_error.h"

#ifndef _ERROR_CHECK_FOR_FUNC
#define _ERROR_CHECK_FOR_FUNC

// new feature. If errors occur, the line will be printed and the error will be name. Also, the line number will be named.

BOOLEAN at_least_one_arg_required_err_check(char ** after_call, unsigned int token_count, unsigned int line_number, char * function_called) {
    unsigned int after_token_count = token_count - 1;
    if (after_token_count == 0) {
        printf("ERROR: you must provide at least one argument for the function - \"%s\". Aborting runtime.", function_called);
        return TRUE;
    }
    else return FALSE;
}

BOOLEAN at_least_two_args_required_err_check(char ** after_call, unsigned int token_count, unsigned int line_number, char * function_called) {
    unsigned int after_token_count = token_count - 1;
    if (after_token_count < 2) {
        printf("ERROR: you must provide at least two arguments for the function - \"%s\". Aborting runtime.", function_called);
        return TRUE;
    }
    else return FALSE;
}

BOOLEAN is_real_type(char * type) {
    
}
#endif