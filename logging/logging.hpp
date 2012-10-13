#ifndef LOGGING_H
#define LOGGING_H

#include "macro_tricks.h"

#define LOG_OFF         0
#define LOG_CRITICAL    1
#define LOG_ERROR       2
#define LOG_WARNING     3
#define LOG_INFO        4
#define LOG_DEBUG       5

#define LOG_RUN(level, code)    JOIN_MACROS(LOGGING_RUN_CODE_, level)(code)
#include "logging_conf.hpp"

#define LOGGING_RUN_CODE_ALWAYS(code) (code)

#if GLOBAL_LOGGING_LEVEL >= 1
    #define LOGGING_RUN_CODE_1(code) (code)
#else
#   define LOGGING_RUN_CODE_1(code)
#endif

#if GLOBAL_LOGGING_LEVEL >= 2
    #define LOGGING_RUN_CODE_2(code) (code)
#else
#   define LOGGING_RUN_CODE_2(code)
#endif

#if GLOBAL_LOGGING_LEVEL >= 3
    #define LOGGING_RUN_CODE_3(code) (code)
#else
#   define LOGGING_RUN_CODE_3(code)
#endif

#if GLOBAL_LOGGING_LEVEL >= 4
    #define LOGGING_RUN_CODE_4(code) (code)
#else
#   define LOGGING_RUN_CODE_4(code)
#endif

#if GLOBAL_LOGGING_LEVEL >= 5
    #define LOGGING_RUN_CODE_5(code) (code)
#else
#   define LOGGING_RUN_CODE_5(code)
#endif

#endif // LOGGING_H
