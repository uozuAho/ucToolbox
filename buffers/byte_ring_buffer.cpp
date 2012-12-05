#include "stddef.h"
#include "byte_ring_buffer.hpp"

using namespace ucToolbox;

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

ByteRingBuffer::return_value ByteRingBuffer::get() {
    if (isEmpty())
        return FAIL;
    else {
        full = false;
        uint16_t temp = get_idx;
        if (++get_idx == storage_capacity)
            get_idx = 0;
        return storage[temp];
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
        return storage[temp];
    }
}
