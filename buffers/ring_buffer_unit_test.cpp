#include <iostream>
#include "ring_buffer.hpp"

using namespace std;

namespace ucToolbox {

void ringBufferUnitTest() {
    RingBuffer<int,4> int_ring_buf;
    cout << "int_ring_buf.capacity: " << int_ring_buf.capacity() << endl;
}

} // end namespace ucToolbox
