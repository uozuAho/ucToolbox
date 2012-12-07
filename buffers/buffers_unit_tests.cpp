#include <iostream>
#include <stdio.h>
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
    ByteRingBuffer::return_value result = buf.put('a');
    cout << "buf.put('a') result: " << result << endl;
    result = buf.get();
    cout << "buf.get() result: " << result << endl;
    result = buf.get();
    cout << "buf.get() result: " << result << endl;
    cout << "buf.peek() result: " << buf.peek() << endl;
    buf.write("stuff", sizeof("stuff"));
    cout << "buffer detailed contents:" << endl;
    buf.printContents_detailed();
}

} // end namespace ucToolbox
