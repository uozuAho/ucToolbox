#include "logging.hpp"
#include "UnitTesting.hpp"
#include "test_suites.hpp"

using namespace ucToolbox;

extern Log logger;
#define dbg(x)      logger.print(Log::Dbg, (x))
#define dbg_hex(x)  logger.printHex(Log::Dbg, (x))

void ucToolbox::unitTests::onAssertFail(int line, const char* file) {
    dbg("Assertion failed: File: "); dbg(file); dbg(", line "); dbg(line); dbg("\n");
}

struct TestTotals_st {
    int run;
    int passed;
    int failed;
} TestTotals;

void ucToolbox::unitTests::runTestSuite(const ucToolbox::unitTests::TestSuite* suite) {
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
    dbg("Test suite '"); dbg(suite->name); dbg("':\tTests run: "); dbg(test);
    dbg(",\tTests failed: "); dbg(tests_failed); dbg("\n");
}

void ucToolbox::unitTests::runAllTestSuites() {
    unsigned int suite = 0;

    for (suite = 0; suite < TOTAL_SUITES; suite++)
    {
        ucToolbox::unitTests::runTestSuite(&all_suites[suite]);
    }
    dbg("Tests complete. Totals: Run: "); dbg(TestTotals.run); dbg(", Failed: ");
    dbg(TestTotals.failed); dbg("\n");
}
