#include "stream.hpp"

#ifdef BUILD_UNIT_TESTS
#include "logging.hpp"

void ucToolbox::streamUnitTest() {
    int8_t storage[10];
    Stream stream(storage, 10);
    logstr(LOG_DEBUG, "streamUnitTest():\n");
    ByteRingBuffer::return_value result = stream.write('a');
    logstr(LOG_DEBUG, "stream.write('a') result: ");
    lognum(LOG_DEBUG, result);
    logch(LOG_DEBUG, '\n');
    result = stream.get();
    logstr(LOG_DEBUG, "stream.get() result: ");
    lognum(LOG_DEBUG, result);
    logch(LOG_DEBUG, '\n');
    result = stream.get();
    logstr(LOG_DEBUG, "stream.get() result: ");
    lognum(LOG_DEBUG, result);
    logch(LOG_DEBUG, '\n');
}

#endif // BUILD_UNIT_TESTS
