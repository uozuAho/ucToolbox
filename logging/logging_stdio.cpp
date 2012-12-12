#include <stdio.h>
#include "logging.hpp"
#include "logging_stdio.hpp"

namespace ucToolbox {

void __logch(char c) {
    // Need to check for zeros since printf interprets them as EOL characters (I think)
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
    logstr(LOG_DEBUG, "rrrrrrrr");

    lognum(LOG_CRITICAL, 4);
    lognum(LOG_DEBUG, 234);
}

} // end namespace ucToolbox
