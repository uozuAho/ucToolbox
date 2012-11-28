//#include "logging_iostream.hpp"

#include <stdio.h>
#include "macro_tricks.h"
#include "logging.hpp"

using namespace std;
#include <cstdint>

int main() {
    printf("hi world\n");
    LOG_STDIO_unitTest();
    return 0;
}


