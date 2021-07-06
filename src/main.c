#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "interpret.h"

#define FILE_READ_BUFFER_SIZE 10000

/*
steps in compilation
----
open the file
load the file
parse the const char * from the file
    look for the first whitespace, then stop. That is the command
    everything else is input
*/




int main(int argc, char * argv[]) {
    printf("Running program\n");
    if (argc == 1) {
        printf("%s\n", "No input file provided");
        return EXIT_FAILURE;
    }
    if (argc > 2) {
        printf("%s\n", "Too many arguments provided");
        return EXIT_FAILURE;
    }
    char * run_dir = argv[1];



    FILE * input_file_p = fopen(run_dir, "r");
    char * contents = malloc(sizeof(char) * FILE_READ_BUFFER_SIZE);
    fread(contents, 1, FILE_READ_BUFFER_SIZE, input_file_p);

    struct PARSE_DATA_BY_LINE parse_data_by_line = parse_to_by_line(contents);

    // check if there are errors. interpret(parse_data_by_line) returns 1 if there is an error
    const unsigned char result_from_interpretation = interpret(parse_data_by_line);
    if (result_from_interpretation == 1) return EXIT_FAILURE;
    else return EXIT_SUCCESS;
}




