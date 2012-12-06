#include "stddef.h"
#include "byte_ring_buffer.hpp"

using namespace ucToolbox;

// Not bothering with this constructor - otherwise every function would need to check if
// storage had been set
//ByteRingBuffer::ByteRingBuffer() {
//    storage = NULL;
//    get_idx = put_idx = storage_capacity = 0;
//    full = false;
//}

ByteRingBuffer::ByteRingBuffer(int8_t* storage_location, uint16_t capacity) {
    setStorage(storage_location, capacity);
}

void ByteRingBuffer::setStorage(int8_t* storage_location, uint16_t capacity) {
    storage = storage_location;
    storage_capacity = capacity;
    get_idx = put_idx = 0;
    full = false;
}

bool ByteRingBuffer::isFull() {
    return full;
}

bool ByteRingBuffer::isEmpty() {
    if (get_idx == put_idx && full == false)
        return true;
    else
        return false;
}

ByteRingBuffer::return_value ByteRingBuffer::peek() {
    if (isEmpty())
        return FAIL;
    else
        return static_cast<return_value>(storage[get_idx]);
}

ByteRingBuffer::return_value ByteRingBuffer::get() {
    if (isEmpty())
        return FAIL;
    else {
        full = false;
        uint16_t temp = get_idx;
        if (++get_idx == storage_capacity)
            get_idx = 0;
        return static_cast<return_value>(storage[temp]);
    }
}

ByteRingBuffer::return_value ByteRingBuffer::put(int8_t byte) {
    if (isFull())
        return FAIL;
    else {
        uint16_t temp = put_idx;
        if (++put_idx == storage_capacity)
            put_idx = 0;
        if (put_idx == get_idx)
            full = true;
        return OK;
    }
}

ByteRingBuffer::return_value ByteRingBuffer::write(int8_t* buf, uint16_t len) {
    if (space() < len)
        return FAIL;
    else {
        int i = 0;
        for(; i < len; i++) {
            put(buf[i]);
        }
        return OK;
    }
}

uint16_t ByteRingBuffer::space() {
    if (full)
        return 0;
    else {
        int32_t len = get_idx - put_idx;
        if (len <= 0)
            len += storage_capacity;
        return static_cast<uint16_t>(len);
    }
}
