#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "functions/print.h"
#include "functions/println.h"
#include "functions/exit.h"
#include "parse.h"
#include "structs.h"
#include "boolean.h"

int interpret_line(char**, unsigned int);
int interpret(struct PARSE_DATA_BY_LINE);


int interpret(struct PARSE_DATA_BY_LINE parse_data_by_line) {
    // the parse data from the entire file is the parameter
    // returns 1 if error
    // returns 0 if no error

    unsigned int i = 0;
    for (i; i < parse_data_by_line.lines_count; i++) {
        struct PARSE_DATA_FOR_LINE parse_data_for_line = parse_data_by_space(parse_data_by_line.lines[i]);

        interpret_line(parse_data_for_line.line, parse_data_for_line.tokens_count);
    }




    return EXIT_SUCCESS;
}


int interpret_line(char ** line, unsigned int tokens_count) {
    //printf("----------- COMPILING LINE -----------\n");
    const char * function = line[0];
    char ** after_call = line + 1;



    if (strcmp(function, "print") == 0) {
        //printf("CALLING PRINT FUNCTION\n");
        // convert the char ** to char * because the entire structure is to be treated as one string

        BOOLEAN result = print_func(after_call, tokens_count);
    }

    else if (strcmp(function, "exit") == 0) {
        BOOLEAN result = exit_func(after_call, tokens_count);
    }


    else if (strcmp(function, "println") == 0) {
        BOOLEAN result = println_func(after_call, tokens_count);
    }

    else {
        printf("Invalid function call: %s. Aborting runtime.", function);
        return EXIT_FAILURE;
    }



    //printf("----------- FINISHED COMPILING LINE -----------\n");
    //free (line);
    return EXIT_SUCCESS;
}


