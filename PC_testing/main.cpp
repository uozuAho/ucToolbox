//#include "logging_iostream.hpp"

#include <stdio.h>
#include "macro_tricks.h"
#include "logging.hpp"

using namespace std;

int main() {
    printf("hi world\n");
    LOG_RUN(LOG_CRITICAL, printf("run_1 test\n"));
    LOG_RUN(LOG_DEBUG, printf("run_2 test\n"));

    logch(LOG_CRITICAL, 'a');
    logch(LOG_DEBUG, 'a');

    lognum(LOG_CRITICAL, 4);
    lognum(LOG_DEBUG, 4);

    return 0;
}


