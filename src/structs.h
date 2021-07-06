#ifndef STRUCTS
#define STRUCTS

struct PARSE_DATA_BY_LINE {
    char ** lines;
    unsigned int lines_count;
};

struct PARSE_DATA_FOR_LINE {
    char ** line;
    unsigned int tokens_count;
};

#endif