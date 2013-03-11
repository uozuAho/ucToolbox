#ifndef LOGGING_STDIO_H
#define LOGGING_STDIO_H

#include <cstddef>

//TODO: rename this file to logging, and the current logging.hpp to logging_conf or similar
//      everything in this header is now generic....apart from the following definitions. They
//      should be in logging.conf
// Define the type of stream used for logging output
#define STREAM_TYPE_STDIO
//#define STREAM_TYPE_IOSTREAM
//#define STREAM_TYPE_CUSTOM

#ifdef STREAM_TYPE_STDIO
    #include "stdio.h"
    typedef FILE ostream_type;
#endif

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
