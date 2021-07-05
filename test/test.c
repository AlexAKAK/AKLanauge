#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    char ** array = malloc(sizeof(char*) * 10);


    char s[] = "hey guys what's going on";
    printf(strtok(s, " "));
    printf(strtok(s, " "));
    printf(strtok(s, " "));
    printf(strtok(s, " "));



    



    return EXIT_SUCCESS;
}