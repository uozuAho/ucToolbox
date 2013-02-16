#ifdef BUILD_UNIT_TESTS
#include <cstdint>
#include "ContiguousQueue.hpp"
#include "logging.hpp"
#include "Queue.hpp"
#include "QueueUnitTests.hpp"

using namespace ucToolbox;

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

void QueueUnitTests::byteQueueUnitTest() {
    dbg("byteQueueUnitTest():\n");
    dbg("Creating DebugQueue<char, 10> q:\n");
    DebugQueue<char, 10> q;

    dbg("q.push('a')\n");
    q.push('a');

    char result = q.readAndPop();
    dbg("q.readAndPop() result: "); dbg(result); dbg('\n');
    result = q.readAndPop();
    dbg("q.readAndPop() result: "); dbg(result); dbg('\n');

    result = q.front();
    dbg("q.front() result: "); dbg(result); dbg('\n');

    dbg("q.push(\"stuff\", sizeof(\"stuff\"));\n");
    q.push("stuff", sizeof("stuff"));
    dbg("Buffer contents:\n");
    q.printContents_detailed();

    dbg("Filling queue with chars, starting with 'A'\n");
    char rand_char = 'A';
    while (q.isFull() == false) {
        q.push(rand_char++);
    }
    q.printContents_detailed();

    dbg("q.readAndPop() result: "); dbg(q.readAndPop()); dbg('\n');
    q.printContents_detailed();
    dbg("q.readAndPop() result: "); dbg(q.readAndPop()); dbg('\n');
    q.printContents_detailed();
}

void queueUnitTests() {
    QueueUnitTests a;
    a.byteQueueUnitTest();
}

#endif // ifdef BUILD_UNIT_TESTS

