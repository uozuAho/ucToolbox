#include "stream.hpp"

#ifdef BUILD_UNIT_TESTS
#include "logging.hpp"

namespace ucToolbox {

Log* logger = getLogger();
#define dbg(x)      logger->print(Log::Dbg, (x))
#define dbg_hex(x)  logger->printHex(Log::Dbg, (x))

void streamUnitTest() {
    int8_t storage[10];
    Stream stream(storage, 10);
    dbg("streamUnitTest():\n");
    ByteRingBuffer::return_value result = stream.write('a');
    dbg("stream.write('a') result: ");
    dbg(result);
    dbg('\n');
    result = stream.get();
    dbg("stream.get() result: ");
    dbg(result);
    dbg('\n');
    result = stream.get();
    dbg("stream.get() result: ");
    dbg(result);
    dbg('\n');
}

} // end namespace ucToolbox

#endif // BUILD_UNIT_TESTS
