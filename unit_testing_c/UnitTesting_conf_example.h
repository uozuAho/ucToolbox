#ifndef UNIT_TESTING_CONF_H
#define UNIT_TESTING_CONF_H

// Include the header(s) that declares all your test suites
#include "test_suites.h"

// Define string-printing and unsigned integer printing functions
#define print_cstr(x)   log_cstr(x, ascii)
#define print_ui(x)     log_si(x, ascii)

#endif // #ifndef UNIT_TESTING_CONF_H
