#ifndef _RAISE_ERROR
#define _RAISE_ERROR
void raise_error(const char * s) {
    printf("ERROR: %s. Aborting runtime.\n", s);
}
#endif