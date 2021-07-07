#include <string.h>
#include <stdlib.h>



#ifndef UTILITIES
#define UTILITIES

unsigned int number_of_lines(const char * s) {
    unsigned int lines = 1;

    unsigned int i = 0;
    for (i; i < strlen(s); i++) {
        if (s[i] == '\n') lines++;
    }
    return lines;
}

unsigned int number_of_tokens(const char * s) {
    unsigned int lines = 1;

    unsigned int i = 0;
    for (i; i < strlen(s); i++) {
        if (s[i] == ' ') {
            lines++;
            
        }
    }
    return lines;
}



char * char_pp_to_char_p(char ** pp, unsigned int length_of_pp) {
    unsigned int x = 0;
    for (x; x<length_of_pp; x++) {
    }



    char * p = malloc(sizeof(char) * length_of_pp);
    p[0] = '\0';

    unsigned int i = 0;
    for (i; i < length_of_pp; i++) {
        //strncat(p, pp[i], strlen(pp[i]));
        //strncat(p, " ", 1);
        strcat(p, pp[i]);
        strcat(p, " ");
    }

    // remove the last space by replacing it with a null byte
    p[strlen(p) - 1] = '\0';


    return p;
} 

#endif
