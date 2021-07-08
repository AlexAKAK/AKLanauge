#include "./boolean.h"

#ifndef _ERROR_CHECK_FOR_FUNC
#define _ERROR_CHECK_FOR_FUNC
BOOLEAN at_least_one_arg_required_err_check(char ** after_call, unsigned int token_count) {
    unsigned int after_token_count = token_count - 1;
    if (after_token_count == 0) return TRUE;
    else return FALSE;
}

#endif