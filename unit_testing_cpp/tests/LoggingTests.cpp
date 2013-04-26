#include "conditional_logging.hpp"
#include "logging.hpp"
#include "UnitTesting.hpp"

using namespace ucToolbox;
using namespace unitTests;

#define dbg(x)      logger.print(Log::Dbg, (x))
#define dbg_hex(x)  logger.print(Log::Dbg, (x), Log::hex)

TEST_FUNCTION VerboseLoggingTest() {
    dbg("Skipping verbose logging test\n");
    return test_skipped;

    logger.setVerbosity(Log::Dbg);
    logger.print(Log::Info, "---------------------------\n");
    logger.print(Log::Info, "Stdio logging test start. \n"
                            "Testing run-time logging verbosity changes...\n");

    logger.print(Log::Info, "Log level set to Dbg\n");
    logger.print(Log::Dbg, "Debug printout\n");
    logger.print(Log::Warning, "Warning printout\n");
    logger.print(Log::Critical, "Critical printout\n");

    logger.setVerbosity(Log::Warning);
    logger.print(Log::Critical, "Log level set to Warning\n");
    logger.print(Log::Dbg, "Debug printout\n");
    logger.print(Log::Warning, "Warning printout\n");
    logger.print(Log::Critical, "Critical printout\n");

    logger.setVerbosity(Log::Critical);
    logger.print(Log::Critical, "Log level set to Critical\n");
    logger.print(Log::Dbg, "Debug printout\n");
    logger.print(Log::Warning, "Warning printout\n");
    logger.print(Log::Critical, "Critical printout\n");

    logger.setVerbosity(Log::Dbg);
    logger.print(Log::Info, "\nTesting all printing functions...\n");
    const char* str = "blah";
    dbg("Char:      "); dbg('c'); dbg("\n");
    dbg("Int:       "); dbg(1); dbg("\n");
    dbg("String:    "); dbg(str); dbg("\n");
    dbg("Hex int:   "); dbg_hex(34); dbg("\n");

    dbg("\nTesting conditional logging compilation.\n");
    dbg("NOTE: The global logging level must be changed in conditional_logging.hpp"
            " to test this part.\n");
    dbg("GLOBAL_LOGGING_LEVEL: "); dbg(GLOBAL_LOGGING_LEVEL); dbg("\n");
    LOG_CONDITIONAL(LOG_DEBUG, dbg("LOG_DEBUG printout\n"));
    LOG_CONDITIONAL(LOG_WARNING, dbg("LOG_WARNING printout\n"));
    LOG_CONDITIONAL(LOG_CRITICAL, dbg("LOG_CRITICAL printout\n"));

    logger.print(Log::Info, "Stdio logging test finished\n");
    logger.print(Log::Info, "---------------------------\n");

    return test_passed;
}
