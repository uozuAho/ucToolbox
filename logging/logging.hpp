#ifndef LOGGING_STDIO_H
#define LOGGING_STDIO_H

#include <cstddef>
#include "logging_conf.hpp"

namespace ucToolbox {

class Log {
public:
    enum Level {
        Dbg,    // Dbg used since DEBUG is too commonly used
        Info,
        Warning,
        Error,
        Critical,
    };

    enum Format {
        ascii,
        dec,
        hex
    };

    Log();
    void print(enum Level l, const char c, Format f=ascii);
    void print(enum Level l, const char* str, Format f=ascii);
    void print(enum Level l, const int i, Format f=dec);
    void print(enum Level l, const std::size_t i, Format f=dec);
    // etc...

    void setVerbosity(Level l);
    void setOutputStream(ostream_type* stream);

private:
    Level verbosity;
    ostream_type* out_stream;
};

}// end namespace ucToolbox

// Logger in instantiated within logging_stdio.cpp
extern ucToolbox::Log logger;

#endif // LOGGING_STDIO_H
