#include <cstdint>
#include <stdio.h>

#include "byte_ring_buffer.hpp"
#include "logging.hpp"
#include "macro_tricks.h"
#include "QueueUnitTests.hpp"
#include "stream.hpp"

using namespace ucToolbox;

int main() {
//    LogStdio_unitTest();
//    byteRingBufferUnitTest();
//    streamUnitTest();

    queueUnitTests();
    return 0;
}


