#include <cstdint>
#include "logging.hpp"
#include "UnitTesting.hpp"
#include "Stream.hpp"

using namespace ucToolbox;
using namespace unitTests;

extern Log logger;
#define dbg(x)      logger.print(Log::Dbg, (x))
#define dbg_hex(x)  logger.printHex(Log::Dbg, (x))

// Parser not actually implemented yet. Write desired functionality here!
TEST_FUNCTION parserTestTest() {
    uint8_t test_message[] = "asdfl asdfasd  as f sd f asdf f f f d fas d f a";
    return test_passed;
}
