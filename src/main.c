#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_file.h"
#include "parse.h"
#include "interpret.h"
#include "raise_error.h"

#define FILE_READ_BUFFER_SIZE 10000

/*
Figure out how memory will work
*/

int main(int argc, char * argv[]) {
    printf("[AKScript]\n\n\n\n");
    if (argc == 1) {
        raise_error("No input file provided");
        return EXIT_FAILURE;
    }
    if (argc > 2) {
        raise_error("Too many arguments provided");
        return EXIT_FAILURE;
    }

    char * run_dir = argv[1];
    FILE * fp = fopen(run_dir, "r");

    if (fp == NULL) {
        raise_error("Source code directory non existant");
        return EXIT_FAILURE;
    }


    
    char * contents = read_file(fp);

    struct PARSE_DATA_BY_LINE parse_data_by_line = parse_to_by_line(contents);
    //parse_data_by_line.lines_count--;

    // check if there are errors. interpret(parse_data_by_line) returns 1 if there is an error
    const unsigned char result_from_interpretation = interpret(parse_data_by_line);
    if (result_from_interpretation == 1) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}




