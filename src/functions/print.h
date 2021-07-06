#include "./../utilities.h"

void print_func(char ** after_call, unsigned int token_count) {
    char * after_concatenated = char_pp_to_char_p(after_call, number_of_tokens(after_call));

    printf(after_concatenated);




}