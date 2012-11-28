#include <stdio.h>
#include "logging.hpp"
#include "logging_stdio.hpp"

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

void LOG_STDIO_unitTest() {
    LOG_RUN(LOG_CRITICAL, printf("run_1 test\n"));
    LOG_RUN(LOG_DEBUG, printf("run_2 test\n"));

    logch(LOG_CRITICAL, 'a');
    logch(LOG_DEBUG, 'rrrrrrrr');

    lognum(LOG_CRITICAL, 4);
    lognum(LOG_DEBUG, 234);
}


