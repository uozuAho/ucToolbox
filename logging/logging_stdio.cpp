#include <stdio.h>
#include "logging_stdio.hpp"

using namespace ucToolbox;

Log::Log() {
    verbosity = Dbg;
    out_stream = stdout;
}

void Log::setVerbosity(Level l) {
    verbosity = l;
}

void Log::setOutputStream(FILE* stream) {
    out_stream = stream;
}

void Log::print(enum Level l, const char c) {
    // Need to check for zeros since printf interprets them as EOL characters (I think)
    if (c == 0) {
        fprintf(out_stream, " ");
        fflush(out_stream);
    }
    else {
        fprintf(out_stream, "%c", c);
        fflush(out_stream);
    }
}

void Log::print(enum Level l, const char* str) {
    if (l >= verbosity) {
        fprintf(out_stream, "%s", str);
        fflush(out_stream);
    }
}

void Log::print(enum Level l, const int i) {
    if (l >= verbosity) {
        fprintf(out_stream, "%d", i);
        fflush(out_stream);
    }
}

void Log::print(enum Level l, const std::size_t i) {
    if (l >= verbosity) {
        fprintf(out_stream, "%zu", i);
        fflush(out_stream);
    }
}

void Log::printHex(enum Level l, const int i) {
    if (l >= verbosity) {
        fprintf(out_stream, "0x%02X", i);
        fflush(stdout);
    }
}
// logger instantiated locally - all files that use
// logging_stdio.hpp have access to this logger instance
Log logger;

#ifdef BUILD_UNIT_TESTS

#include "conditional_logging.hpp"
#define dbg(x)      logger.print(Log::Dbg, (x))
#define dbg_hex(x)  logger.printHex(Log::Dbg, (x))

void LogStdio_unitTest() {
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
}

#endif // #ifdef BUILD_UNIT_TESTS
