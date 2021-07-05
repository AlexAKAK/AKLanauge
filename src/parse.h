#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "utilities.h"

struct parse_data {
    char ** lines;
    unsigned int lines_count;
};



char ** parse(char * contents) {
    char ** lines = malloc(sizeof(char*) * number_of_lines(contents));

    char * token = strtok(contents, "\n");
    unsigned int i = 0;
    while (token != NULL) {
        lines[i] = token;
        i++;
        token = strtok(NULL, "\n");
    }

    return lines;

}