#include <stdio.h>
#include "UnitTesting.hpp"
#include "test_suites.hpp"

void onAssertFail(int line, const char* file) {
    printf("Assertion failed: File: %s, line %d\n", file, line);
}

struct TestTotals_st {
    int run;
    int passed;
    int failed;
} TestTotals;

void runTestSuite(const TestSuite* suite) {
    int test;
    int tests_failed = 0;

    for (test = 0; test < suite->num_tests; test++)
    {
        TestTotals.run++;
        if (suite->tests[test]() == 0)
            TestTotals.passed++;
        else {
            tests_failed++;
            TestTotals.failed++;
        }
    }
    printf("Test suite '%s':\tTests run: %d,\tTests failed: %d\n", suite->name, test, tests_failed);
}

void runAllTestSuites() {
    unsigned int suite = 0;

    for (suite = 0; suite < TOTAL_SUITES; suite++)
    {
        runTestSuite(&all_suites[suite]);
    }
    printf("Tests complete. Totals: Run: %d, Failed: %d\n", TestTotals.run, TestTotals.failed);
}
