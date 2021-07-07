#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "utilities.h"
#include "structs.h"

#ifndef PARSE_STRUCTS
#define PARSE_STRUCTS
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

struct PARSE_DATA_FOR_LINE parse_data_by_space(char * line) {
    struct PARSE_DATA_FOR_LINE parse_data_for_line;

    unsigned int tokens_count = number_of_tokens(line);
    char ** tokens = malloc(sizeof(char*) * tokens_count);

    char * token = strtok(line, " ");
    unsigned int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }


    parse_data_for_line.line = tokens;
    parse_data_for_line.tokens_count = tokens_count;





    return parse_data_for_line;

}
#endif