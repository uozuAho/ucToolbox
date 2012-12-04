//#include "logging_iostream.hpp"

#include <array>
#include <stdio.h>
#include "macro_tricks.h"
#include "logging.hpp"
#include "ring_buffer_unit_test.hpp"

using namespace std;
using namespace ucToolbox;
#include <cstdint>

int main() {
//    printf("hi world\n");
//    LOG_STDIO_unitTest();

    ringBufferUnitTest();
    return 0;
}


