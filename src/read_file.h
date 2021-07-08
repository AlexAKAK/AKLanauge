#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
I'm not really sure why but fread was acting wierd.
It was adding random characters to the back of the char * so I made my own
function for reading the file.
It reads the file on char at a time and adds it to a block of memory allocated to a pointer.
It then returns the pointer.
*/

char * read_file(FILE * fp) {
    char * contents = malloc(sizeof(char) * 10000);

    char ch;
    ch = fgetc(fp);
    unsigned int i = 0;
    while (ch != EOF) {
        contents[i] = ch;
        ch = fgetc(fp);
        i++;
    }

    contents[i] = '\0';
    fclose(fp);

    return contents;
}

