#include "UnitTesting.h"
#include "UnitTesting_conf.h"

void UnitTesting_vOnAssertFail(const char* msg, const char* file, int line) {
    print_cstr("Assertion failed: "); print_cstr(msg); print_cstr(" File: ");
    print_cstr(file); print_cstr(", line "); print_ui(line); print_cstr("\n");
}

struct TestTotals_st {
    int run;
    int passed;
    int failed;
    int skipped;
} TestTotals;

void UnitTesting_vRunTestSuite(const TestSuite* suite) {
    int test;
    int tests_failed = 0;
    int tests_skipped = 0;

    for (test = 0; test < suite->num_tests; test++)
    {
        TestTotals.run++;
        switch (suite->tests[test]())
        {
        case test_passed:
            TestTotals.passed++;
            break;
        case test_failed:
            tests_failed++;
            TestTotals.failed++;
            break;
        case test_skipped:
            tests_skipped++;
            TestTotals.run--;
            TestTotals.skipped++;
            break;
        default:
            break;
        }
    }
    print_cstr("Test suite '"); print_cstr(suite->name); print_cstr("':\tTotal tests: "); print_ui(test);
    print_cstr(",\tfailed: "); print_ui(tests_failed);
    print_cstr(",\tskipped: "); print_ui(tests_skipped); print_cstr("\n");
}

void UnitTesting_vRunAllTestSuites() {
    unsigned int suite = 0;

    for (suite = 0; suite < TOTAL_SUITES; suite++)
    {
        UnitTesting_vRunTestSuite(all_suites[suite]);
    }
    print_cstr("Tests complete. Totals: Run: "); print_ui(TestTotals.run); print_cstr(", Failed: ");
    print_ui(TestTotals.failed); print_cstr(", Skipped: "); print_ui(TestTotals.skipped); print_cstr("\n");
}

