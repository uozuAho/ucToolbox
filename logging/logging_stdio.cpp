#include <stdio.h>
#include "logging.hpp"

using namespace ucToolbox;

Log::Log() {
    verbosity = Dbg;
    out_stream = stdout;
}

void Log::setVerbosity(Level l) {
    verbosity = l;
}

void Log::setOutputStream(ostream_type* stream) {
    out_stream = stream;
}

void Log::print(enum Level l, const char c, Format f) {
    switch (f)
    {
    default:
    case ascii:
        // Need to check for zeros since printf interprets them as EOL characters (I think)
        if (c == 0) {
            fprintf(out_stream, " ");
            fflush(out_stream);
        }
        else {
            fprintf(out_stream, "%c", c);
            fflush(out_stream);
        }
        break;
    }
}

void Log::print(enum Level l, const char* str, Format f) {
    switch (f)
    {
    default:
    case ascii:
        if (l >= verbosity) {
            fprintf(out_stream, "%s", str);
            fflush(out_stream);
        }
        break;
    }
}

void Log::print(enum Level l, const int i, Format f) {
    switch (f)
    {
    default:
    case dec:
        if (l >= verbosity) {
            fprintf(out_stream, "%d", i);
            fflush(out_stream);
        }
        break;
    case hex:
        if (l >= verbosity) {
            fprintf(out_stream, "0x%2x", i);
            fflush(out_stream);
        }
        break;
    case ascii:
        break;
    }
}

void Log::print(enum Level l, const std::size_t i, Format f) {
    switch (f)
    {
    default:
    case dec:
        if (l >= verbosity) {
            fprintf(out_stream, "%zu", i);
            fflush(out_stream);
        }
        break;
    case ascii:
        break;
    }
}

// logger instantiated locally - all files that use
// logging_stdio.hpp have access to this logger instance
Log logger;
