#include <string.h>

unsigned int number_of_lines(const char * s) {
    unsigned int lines = 1;

    unsigned int i = 0;
    for (i; i < strlen(s); i++) {
        if (s[i] == '\n') lines++;
    }
    return lines;
}