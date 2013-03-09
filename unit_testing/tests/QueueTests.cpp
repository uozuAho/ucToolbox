#ifdef BUILD_UNIT_TESTS
#include <cstdint>
#include "ContiguousQueue.hpp"
#include "logging.hpp"
#include "Queue.hpp"
#include "UnitTesting.hpp"

using namespace ucToolbox;
using namespace unitTests;

extern Log logger;
#define dbg(x)      logger.print(Log::Dbg, (x))
#define dbg_hex(x)  logger.printHex(Log::Dbg, (x))

// Extend the Queue class with some debugging functions
template<typename T, std::size_t N>
class DebugQueue : public Queue<T,N> {
public:
    void printContents_detailed() {
        dbg("-----------------------------\n");
        dbg("numEmptyElements: "); dbg(this->numEmptyElements());
        dbg("  full: ");
        if (this->isFull())
            dbg("true\n");
        else
            dbg("false\n");
        dbg("idx\t hex\t ascii\t front/back idx\n");
        for(std::size_t i = 0; i < N; i++) {
            dbg(i);
            dbg("\t ");
            dbg_hex(this->_M_instance[i]);
            dbg("\t ");
            dbg(this->_M_instance[i]);
            dbg("\t ");
            if (this->back_idx == i)
                dbg("<--back_idx ");
            if (this->front_idx == i)
                dbg("<--front_idx");
            dbg("\n");
        }
        dbg("-----------------------------\n");
    }
};

// Extend the ContiguousQueue class with some debugging functions
template<typename T, std::size_t N>
class DebugContiguousQueue : public ContiguousQueue<T,N> {
public:
    void printContents_detailed() {
        dbg("-----------------------------\n");
        dbg("numEmptyElements: "); dbg(this->numEmptyElements());
        dbg("  full: ");
        if (this->isFull())
            dbg("true\n");
        else
            dbg("false\n");
        dbg("idx\t hex\t ascii\t front/back idx\n");
        for(std::size_t i = 0; i < N; i++) {
            dbg(i);
            dbg("\t ");
            dbg_hex(this->_M_instance[i]);
            dbg("\t ");
            dbg(this->_M_instance[i]);
            dbg("\t ");
            if (this->back_idx == i)
                dbg("<--back_idx ");
            if (this->front_idx == i)
                dbg("<--front_idx");
            dbg("\n");
        }
        dbg("-----------------------------\n");
    }
};

TEST_FUNCTION byteQueueConstructorTest() {
    DebugQueue<char, 10> q;

    TEST_ASSERT(q.isEmpty() == true);
    TEST_ASSERT(q.isFull() == false);
    TEST_ASSERT(q.numEmptyElements() == 10);
    TEST_ASSERT(q.size() == 0);

    return test_passed;
}

TEST_FUNCTION byteQueueTest() {
    DebugQueue<char, 10> q;

    q.push('a');
    TEST_ASSERT(q.readAndPop() == 'a');

    q.push("stuff", sizeof("stuff"));
    TEST_ASSERT(q.front() == 's');
    TEST_ASSERT(q.numEmptyElements() == 4);
    TEST_ASSERT(q.size() == 6);

    while (q.isFull() == false) {
        q.push('A');
    }
    TEST_ASSERT(q.isFull());
    TEST_ASSERT(q.readAndPop() == 's');
    TEST_ASSERT(q.readAndPop() == 't');

    return test_passed;
}

TEST_FUNCTION byteQueueStressTest() {
    DebugQueue<char, 10> q;

    q.push("SLDAJFAEPAREGARPGGARLAKFDLGK", sizeof("SLDAJFAEPAREGARPGGARLAKFDLGK"));
    TEST_ASSERT(q.isEmpty());

    q.push('a');
    TEST_ASSERT(q.readAndPop() == 'a');

    for (int i = 0; i < 30; i++) {
        q.push('N');
    }
    TEST_ASSERT(q.isFull());
    TEST_ASSERT(q.numEmptyElements() == 0);
    TEST_ASSERT(q.size() == 10);

    for (int i = 0; i < 10; i++) {
        TEST_ASSERT(q.readAndPop() == 'N');
    }

    TEST_ASSERT(q.isEmpty());
    for (int i = 0; i < 10; i++) {
        q.pop();
    }

    TEST_ASSERT(q.isEmpty());
    TEST_ASSERT(!q.isFull());
    TEST_ASSERT(q.numEmptyElements() == 10);
    TEST_ASSERT(q.size() == 0);

    return test_passed;
}

#endif // ifdef BUILD_UNIT_TESTS

