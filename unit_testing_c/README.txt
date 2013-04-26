Module Description
==================

This module provides a central place to write all unit tests,
and provides a script to automatically generate tests suites
that can be called from main() or wherever.

All you need to do is write your test functions, run
TestSuiteGenerator.py (requires python), then call
UnitTesting_vRunAllTestSuites() to run the tests.


How to write a test function
============================

A test function must follow the form:

TEST_FUNCTION func(void) {
    return <test_result>;
}

where <test_result> can be one of:
- test_passed,
- test_failed,
- test_skipped

You can write your own pass/fail tests, or use the provided
TEST_ASSERT() macro. This will automatically return test_failed
if the assert is false.

Write your test code under the tests directory. You don't need
to declare your test functions anywhere - the script takes care
of this.

Each source file under the tests directory can contain multiple
test functions, as well as other functions and data which can
be used within test functions.


A very simple test function
===========================

TEST_FUNCTION func(void) {
    TEST_ASSERT(1+1 == 2);
    return test_passed;
}

