#include <cstdint>
#include <stdio.h>
#include "macro_tricks.h"
#include "logging.hpp"
#include "ring_buffer_unit_test.hpp"

using namespace std;
using namespace ucToolbox;

int main() {
    printf("hi world\n");
    LOG_STDIO_unitTest();
    ringBufferUnitTest();
    return 0;
}


