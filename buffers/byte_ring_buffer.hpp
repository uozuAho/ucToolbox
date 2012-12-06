/* Use this as an alternative to ring_buffer.hpp for a (potentially) faster byte buffer. Also my
 * ring_buffer template doesn't work at the moment...
 */

#ifndef BYTE_RING_BUFFER_H
#define BYTE_RING_BUFFER_H

#include <stdint.h>

namespace ucToolbox {

class ByteRingBuffer {
public:
    ByteRingBuffer(int8_t* storage_location, uint16_t capacity);

    enum return_value {
        OK = 0,
        FAIL = -1,
    };

    return_value peek();
    return_value get();
    return_value put(int8_t byte);
    return_value write(int8_t* buf, uint16_t len);
    bool isFull();
    bool isEmpty();
    void setStorage(int8_t* location, uint16_t capacity);

private:
    int8_t* storage;
    uint16_t storage_capacity;
    uint16_t get_idx, put_idx;
    bool full; // flag used since get_idx == put_idx could mean the buffer is empty or full

    uint16_t space();
};

} // end namespace ucToolbox

#endif // #ifndef BYTE_RING_BUFFER_H
