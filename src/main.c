#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"

#define FILE_READ_BUFFER 10000

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
    if (argc == 1) {
        printf("%s\n", "No input file provided");
        return EXIT_FAILURE;
    }
    if (argc > 2) {
        printf("%s\n", "Too many arguments provided");
        return EXIT_FAILURE;
    }
    char * run_dir = argv[1];
    printf("Running file [%s]", run_dir);


    FILE * input_file_p = fopen(run_dir, "r");
    char * contents = malloc(sizeof(char) * FILE_READ_BUFFER);
    contents[0] = '\0';
    
    size_t contents_length = fread(contents, 1, FILE_READ_BUFFER, input_file_p);
    
    int i = 0;
    for (i; i < strlen(contents); i++) {
        printf("%c\n", contents[i]);
    }

    char ** contents_by_line = parse_1(contents);
    printf("%s", contents_by_line[0]);



    return EXIT_SUCCESS;
}




