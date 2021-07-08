#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "functions/print.h"
#include "functions/println.h"
#include "functions/exit.h"
#include "parse.h"
#include "structs.h"
#include "boolean.h"


BOOLEAN interpret_line(char ** line, unsigned int tokens_count, unsigned int line_number);
BOOLEAN interpret(struct PARSE_DATA_BY_LINE parse_data_by_line);

BOOLEAN interpret(struct PARSE_DATA_BY_LINE parse_data_by_line) {
    // the parse data from the entire file is the parameter
    // returns 1 if error
    // returns 0 if no error
    unsigned int line_number = 1;

    BOOLEAN result;


    unsigned int i = 0;
    for (i; i < parse_data_by_line.lines_count; i++) {
        struct PARSE_DATA_FOR_LINE parse_data_for_line = parse_data_by_space(parse_data_by_line.lines[i]);

        result = interpret_line(parse_data_for_line.line, parse_data_for_line.tokens_count, line_number);
        line_number++;
        if (result == FALSE) return EXIT_FAILURE;
    }




    return EXIT_SUCCESS;
}


BOOLEAN interpret_line(char ** line, unsigned int tokens_count, unsigned int line_number) {
    //printf("----------- COMPILING LINE -----------\n");
    const char * function = line[0];
    char ** after_call = line + 1;


    BOOLEAN result;

    if (strcmp(function, "print") == 0) {
        //printf("CALLING PRINT FUNCTION\n");
        // convert the char ** to char * because the entire structure is to be treated as one string

        result = print_func(after_call, tokens_count, line_number);
    }

    else if (strcmp(function, "exit") == 0) {
        result = exit_func(after_call, tokens_count, line_number);
    }


    else if (strcmp(function, "println") == 0) {
        result = println_func(after_call, tokens_count, line_number);
    }

    else {
        printf("Invalid function call: %s. Aborting runtime.\n", function);
        return EXIT_FAILURE;
    }


    return result;
}


