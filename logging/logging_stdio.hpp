#ifndef LOGGING_STDIO_H
#define LOGGING_STDIO_H

void __logch(char c);
#define logch(level, ch)    LOG_RUN(level, __logch(ch))
#define logstr(level, str)  LOG_RUN(level, __logstr(str))

#define lognum(level, num)      LOG_RUN(level, {printf("%d", num); fflush(stdout);})
#define lognum_hex(level, num)  LOG_RUN(level, {printf("0x%02X",(num)); fflush(stdout);})


#endif // LOGGING_STDIO_H
