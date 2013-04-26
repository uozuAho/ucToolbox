#ifndef UNIT_TESTING_H
#define UNIT_TESTING_H

typedef enum TEST_RESULT_e {
    test_passed,
    test_failed,
    test_skipped
} TEST_RESULT;

typedef TEST_RESULT TEST_FUNCTION;
typedef TEST_FUNCTION (*TEST_FUNCTION_ptr)(void);

typedef struct TestSuite_st {
    const char* name;
    const int num_tests;
    TEST_FUNCTION_ptr* tests;
} TestSuite;

void UnitTesting_vRunTestSuite(const TestSuite* suite);
void UnitTesting_vRunAllTestSuites();

#define TEST_ASSERT(cond)       if(!(cond)) { UnitTesting_vOnAssertFail("(" #cond ") is false.", __FILE__, __LINE__); \
                                        return test_failed; }

#define TEST_ASSERT_FALSE(cond) if((cond))  { UnitTesting_vOnAssertFail("(" #cond ") is true.", __FILE__, __LINE__); \
                                        return test_failed; }

void UnitTesting_vOnAssertFail(const char* msg, const char* file, int line);

#endif // #ifndef UNIT_TESTING_H

