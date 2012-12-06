#include <iostream>
#include "byte_ring_buffer.hpp"
#include "ring_buffer.hpp"

using namespace std;
namespace ucToolbox {

//void ringBufferUnitTest() {
//    RingBuffer<int,10> int_ring_buf;
//    cout << "int_ring_buf.capacity: " << int_ring_buf.capacity() << endl;
//
//    int_ring_buf.put(0);
//    int_ring_buf.put(1);
//    int_ring_buf.put(2);
//    int_ring_buf.put(3);
//    int_ring_buf.put(4);
//    int_ring_buf.put(5);
//    int_ring_buf.put(6);
//    int i = 123;
//    for(int j = 0; j < 4; j++) {
//        if (int_ring_buf.get(&i) != FAIL)
//            cout << i << endl;
//        else
//            cout << "empty" << endl;
//    }
//}

void byteRingBufferUnitTest() {
    int8_t storage[10];
    ByteRingBuffer buf(storage, 10);
    cout << "byteRingBufferUnitTest():" << endl;
    buf.put('a');
    printf("%c\n",buf.peek());
}

} // end namespace ucToolbox
