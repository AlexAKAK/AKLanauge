#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "functions/print.h"
#include "parse.h"
#include "structs.h"


int interpret(struct PARSE_DATA_BY_LINE parse_data_by_line) {
    // the parse data from the entire file is the parameter
    // returns 1 if error
    // returns 0 if no error

    unsigned int i = 0;
    for (i; i < parse_data_by_line.lines_count; i++) {
        interpret_line(parse_data_by_line.lines[i], number_of_tokens(parse_data_by_line.lines[i]))
    }




    return EXIT_SUCCESS;
}


int interpret_line(char ** line, unsigned int tokens_count) {
    const char * function = line[0];
    char ** after_call = line + 1;



    if (strcmp(function, "print") == 0) {
        // convert the char ** to char * because the entire structure is to be treated as one string

        print_func(after_call, tokens_count)
    }



    else (
        printf("Invalid function call: %s. Aborting runtime.", function);
        return EXIT_FAILURE;
    )




    free (line);
    return EXIT_SUCCESS
}


