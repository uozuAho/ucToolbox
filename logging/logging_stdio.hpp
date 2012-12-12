#ifndef LOGGING_STDIO_H
#define LOGGING_STDIO_H

/* Declare/#define any functions you want to use for logging here. The LOG_RUN macro includes the
 * code if it is at or above the global logging level.
 *
 * TODO: figure out how to "overload" these macros so that the debug level is optional (ie.
 * implicitly uses LOG_DEFAULT_LEVEL)
 */
#include <stdio.h>

#define LOG_DEFAULT_LEVEL   LOG_DEBUG

namespace ucToolbox {

void __logch(char c);
#define logch(level, ch)    LOG_RUN(level, __logch(ch))
#define logstr(level, str)  LOG_RUN(level, {printf("%s",str); fflush(stdout);})

#define lognum(level, num)      LOG_RUN(level, {printf("%d", num); fflush(stdout);})
#define lognum_hex(level, num)  LOG_RUN(level, {printf("0x%02X",(num)); fflush(stdout);})

void LOG_STDIO_unitTest();

}// end namespace ucToolbox
#endif // LOGGING_STDIO_H
