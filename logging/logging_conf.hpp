/* Configuration of logging module */


#ifndef LOGGING_CONF_H
#define LOGGING_CONF_H

// Define the type of stream used for logging output
#define STREAM_TYPE_STDIO
//#define STREAM_TYPE_IOSTREAM
//#define STREAM_TYPE_CUSTOM

#ifdef STREAM_TYPE_STDIO
    #include <stdio.h>
    typedef FILE ostream_type;
#endif

#endif // LOGGING_CONF_H
