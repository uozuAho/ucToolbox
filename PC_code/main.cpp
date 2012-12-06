#include <cstdint>
#include <stdio.h>
#include "macro_tricks.h"
#include "logging.hpp"
#include "buffers_unit_tests.hpp"

using namespace std;
using namespace ucToolbox;

int main() {
    printf("hi world\n");
    //LOG_STDIO_unitTest();
    byteRingBufferUnitTest();
    return 0;
}


