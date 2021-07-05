#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "utilities.h"

char ** parse_1(const char * contents) {
    char ** contents_by_line = (char **) malloc(sizeof(char*) * number_of_lines(contents));
    size_t length = strlen(contents);
    
    // then loop through the string. Everything there is a space, take everything before and add it to the array. Then, move the contents pointer up to that index + 1 ands continue.
    unsigned int i = 0;
    size_t last_new_line = 0;
    unsigned int x = 0;
    for (i; i< length; i++) {
        if (contents[i] == '\n') {
            // add the line to the x element
            contents_by_line[x] = '\0'; // add the null byte to the block of memory pointed to by the pointer at block 0 of the char**
            strncat(contents_by_line[x], contents, i - 1);
            x++;
            // moves the pointer 
            contents += i + 1;
        }
        if (contents[i] == EOF) break;
    }


    //free((void*) contents);
    return contents_by_line;
}

char ** parse(const char * contents) {
    
}