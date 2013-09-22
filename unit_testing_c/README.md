unit_testing_c
==============

This module provides a central place to write all unit tests,
and provides a script to automatically generate tests suites
that can be called from main() or wherever. This module only
supports C, for C++ support see the unit_testing_cpp module.

To get started, edit "UnitTesting_conf.h" to suit your platform.
There's currently only a few lines you need to change in there.

Next, run TestSuiteGenerator.py (requires python). Any test code
under tests/ will be read and included in the generated test
suites.

Now you have all you need to compile and run your unit tests.
To run the tests within your code, call UnitTesting_vRunAllTestSuites().
You'll need to include "UnitTesting.h" to the file that makes
this function call.


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


Current limitations
===================

- Test names must be globally unique
