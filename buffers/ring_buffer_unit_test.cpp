#include <iostream>
#include "ring_buffer.hpp"

using namespace std;
using namespace ucToolbox;

void ringBufferUnitTest() {
    RingBuffer<int,4> int_ring_buf;
    cout << "int_ring_buf.capacity: " << int_ring_buf.capacity() << endl;
}
