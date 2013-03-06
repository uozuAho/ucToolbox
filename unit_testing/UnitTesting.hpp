#ifndef WOZ_UNIT_H
#define WOZ_UNIT_H

typedef int TEST_FUNCTION;
typedef TEST_FUNCTION (*TEST_FUNCTION_ptr)();

struct TestSuite {
    const char* name;
    const int num_tests;
    const TEST_FUNCTION_ptr* tests;
};

void runTestSuite(const TestSuite* suite);
void runAllTestSuites();

#define TEST_ASSERT(cond) if(!(cond)) { onAssertFail(__LINE__, __FILE__); return 1; }

void onAssertFail(int line, const char* file);

#endif // #ifndef WOZ_UNIT_H
