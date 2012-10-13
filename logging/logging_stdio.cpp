#include <stdio.h>
#include "logging.hpp"

void __logch(char c) {
    if (c == 0) {
        printf(" ");
        fflush(stdout);
    }
    else {
        printf("%c", (c));
        fflush(stdout);
    }
}

void __logstr(const char * str) {
    printf("%s",(str));
    fflush(stdout);
}


