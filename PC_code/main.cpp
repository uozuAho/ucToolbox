#include <cstdint>
#include <stdio.h>
#include "macro_tricks.h"
#include "logging.hpp"
#include "byte_ring_buffer.hpp"
#include "stream.hpp"

using namespace ucToolbox;

int main() {
    LogStdio_unitTest();
    byteRingBufferUnitTest();
    streamUnitTest();
    return 0;
}


