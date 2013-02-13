#ifndef LOGGING_STDIO_H
#define LOGGING_STDIO_H

#include <stdio.h>

//TODO: make this header generic. Just need to do something like:
// typedef FILE ostream_type;
//
// then the stream type can be interchanged depending on where the code is being used
// (eg. PC vs. embedded system not using standard lib)

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

    Log();
    void print(enum Level l, const char c);
    void print(enum Level l, const char* str);
    void print(enum Level l, const int i);
    void printHex(enum Level l, const int i);
    // etc...

    void setVerbosity(Level l);
    void setOutputStream(FILE* stream);

private:
    Level verbosity;
    FILE* out_stream;
};

// TODO:
//extern Log log;
// instead of:
Log* getLogger();
// Then you won't need pointers everywhere to use the logger.

void LogStdio_unitTest();

}// end namespace ucToolbox
#endif // LOGGING_STDIO_H
