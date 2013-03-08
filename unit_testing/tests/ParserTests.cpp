#include <cstdint>
#include "logging.hpp"
#include "UnitTesting.hpp"
#include "stream.hpp"

using namespace ucToolbox;

extern Log logger;
#define dbg(x)      logger.print(Log::Dbg, (x))
#define dbg_hex(x)  logger.printHex(Log::Dbg, (x))

// Parser not actually implemented yet. Write desired functionality here!
unitTests::TEST_FUNCTION parserTestTest() {
    uint8_t test_message[] = "asdfl asdfasd  as f sd f asdf f f f d fas d f a";
    return 0;
}
