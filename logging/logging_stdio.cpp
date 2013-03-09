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
