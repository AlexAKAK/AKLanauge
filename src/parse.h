#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "utilities.h"

struct PARSE_DATA_BY_LINE {
    char ** lines;
    unsigned int lines_count;
};



struct PARSE_DATA_BY_LINE parse_to_by_line(char * contents) {

    struct PARSE_DATA_BY_LINE parse_data;
    
    parse_data.lines = malloc(sizeof(char*) * number_of_lines(contents));

    char * token = strtok(contents, "\n");
    unsigned int i = 0;
    while (token != NULL) {
        parse_data.lines[i] = token;
        i++;
        token = strtok(NULL, "\n");
    }

    parse_data.lines_count = i + 1;


    return parse_data;

}


char ** parse_data_by_space(char * line) {
    char ** tokens = malloc(sizeof(char*) * number_of_tokens(line));

    char * token = strtok(line, " ");
    unsigned int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }




    return tokens;

}

