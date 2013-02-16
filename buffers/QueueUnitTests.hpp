#ifndef QUEUE_UNIT_TEST_H
#define QUEUE_UNIT_TEST_H

namespace ucToolbox {

class QueueUnitTests {
public:
    void byteQueueUnitTest();
};

} // end namespace ucToolbox

// For some reason I get a "undefined reference to `ucToolbox::queueUnitTests()'"
// error if I put this in the ucToolbox namespace.
// TODO: find out why...later
void queueUnitTests();


#endif // #ifndef QUEUE_UNIT_TEST_H
