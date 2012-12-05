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
    bool isFull();
    bool isEmpty();
    void setStorage(int8_t* location, uint16_t capacity);

private:
    int8_t* storage;
    uint16_t storage_capacity;
    uint16_t get_idx, put_idx;
    bool full; // flag used since get_idx == put_idx could mean the buffer is empty or full
};

} // end namespace ucToolbox

//typedef struct {
//    uc* ucpBuffer;
//    const us usBufSize;
//    REG16 usPutIdx, usGetIdx;
//} Ringbuf;
//
//bool RINGBUF_bIsFull(Ringbuf* ringbuf);
//bool RINGBUF_bIsEmpty(Ringbuf* ringbuf);
//us RINGBUF_usSpace(Ringbuf* ringbuf);
//us RINGBUF_usBytesInStream(Ringbuf* buf);
//ss RINGBUF_ssPeek(Ringbuf* ringbuf);
//ss RINGBUF_ssGetByte(Ringbuf* ringbuf);
//ss RINGBUF_ssPutByte(Ringbuf* ringbuf, uc byte);
//us RINGBUF_ssWrite(Ringbuf* ringbuf, uc* input_buf, us len);
//
//// Debugging functions
//void RINGBUF_vPrintToStdout(Ringbuf* ringbuf);
//void RINGBUF_vPrintToStdout_detailed(Ringbuf* buf);
//void RINGBUF_vUnitTest();

#endif // #ifndef BYTE_RING_BUFFER_H
