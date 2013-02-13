#include <stdio.h>
#include "logging_stdio.hpp"

namespace ucToolbox {

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

void Log::printHex(enum Level l, const int i) {
    if (l >= verbosity) {
        fprintf(out_stream, "0x%02X", i);
        fflush(stdout);
    }
}

// Logger instance is created locally
// TODO: make this extern
Log log;

// Return pointer to the logger instance
Log* getLogger() {
    return &log;
}

#ifdef BUILD_UNIT_TESTS

#include "conditional_logging.hpp"
#define dbg(x)      mylog->print(Log::Dbg, (x))
#define dbg_hex(x)  mylog->printHex(Log::Dbg, (x))

void LogStdio_unitTest() {
    Log* mylog = getLogger();

    mylog->setVerbosity(Log::Dbg);
    mylog->print(Log::Info, "---------------------------\n");
    mylog->print(Log::Info, "Stdio logging test start. \n"
                            "Testing run-time logging verbosity changes...\n");

    mylog->print(Log::Info, "Log level set to Dbg\n");
    mylog->print(Log::Dbg, "Debug printout\n");
    mylog->print(Log::Warning, "Warning printout\n");
    mylog->print(Log::Critical, "Critical printout\n");

    mylog->setVerbosity(Log::Warning);
    mylog->print(Log::Critical, "Log level set to Warning\n");
    mylog->print(Log::Dbg, "Debug printout\n");
    mylog->print(Log::Warning, "Warning printout\n");
    mylog->print(Log::Critical, "Critical printout\n");

    mylog->setVerbosity(Log::Critical);
    mylog->print(Log::Critical, "Log level set to Critical\n");
    mylog->print(Log::Dbg, "Debug printout\n");
    mylog->print(Log::Warning, "Warning printout\n");
    mylog->print(Log::Critical, "Critical printout\n");

    mylog->setVerbosity(Log::Dbg);
    mylog->print(Log::Info, "\nTesting all printing functions...\n");
    char* str = "blah";
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

    mylog->print(Log::Info, "Stdio logging test finished\n");
    mylog->print(Log::Info, "---------------------------\n");
}

#endif // #ifdef BUILD_UNIT_TESTS

} // end namespace ucToolbox
