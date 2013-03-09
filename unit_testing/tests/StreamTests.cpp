#include "logging.hpp"
#include "Stream.hpp"
#include "UnitTesting.hpp"

using namespace ucToolbox;
using namespace unitTests;

extern Log logger;
#define dbg(x)      logger.print(Log::Dbg, (x))
#define dbg_hex(x)  logger.printHex(Log::Dbg, (x))

TEST_FUNCTION streamTest() {
    int8_t storage[10];
    Stream stream(storage, 10);
    TEST_ASSERT(stream.write('a') == Stream::OK);
    TEST_ASSERT(stream.get() == 'a');
    TEST_ASSERT(stream.get() == Stream::FAIL);

    return test_passed;
}
