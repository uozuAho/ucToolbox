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

ByteRingBuffer::return_value ByteRingBuffer::write(const char byte) {
    if (isFull())
        return FAIL;
    else {
        uint16_t temp = put_idx;
        if (++put_idx == storage_capacity)
            put_idx = 0;
        if (put_idx == get_idx)
            full = true;
        storage[temp] = byte;
        return OK;
    }
}

//ByteRingBuffer::return_value ByteRingBuffer::write(int8_t* buf, size_t len) {
//    if (space() < len)
//        return FAIL;
//    else {
//        size_t i = 0;
//        for(; i < len; i++) {
//            put(buf[i]);
//        }
//        return OK;
//    }
//}

ByteRingBuffer::return_value ByteRingBuffer::write(const char* buf, size_t len) {
    if (space() < len)
        return FAIL;
    else {
        size_t i = 0;
        for(; i < len; i++) {
            write(buf[i]);
        }
        return OK;
    }
}

ByteRingBuffer::return_value ByteRingBuffer::write(const char* buf) {
    if (space() < sizeof(buf))
        return FAIL;
    else {
        size_t i = 0;
        for(; i < sizeof(buf); i++) {
            write(buf[i]);
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

#ifdef BUILD_UNIT_TESTS
#include "logging.hpp"
Log* logger = getLogger();
#define dbg(x)      logger->print(Log::Dbg, (x))
#define dbg_hex(x)  logger->printHex(Log::Dbg, (x))

//TODO: use the new logging module calls
void ByteRingBuffer::printContents() {
    int i = 0;
    for (; i < storage_capacity; i++) {
        dbg(storage[i]);
    }
}

void ByteRingBuffer::printContents_detailed() {
    int i = 0;
    dbg("-----------------------------\n");
    dbg("space: "); dbg(space());
    dbg("  full: ");
    if (isFull())
        dbg("true\n");
    else
        dbg("false\n");
    dbg("idx   hex   ascii  get/putIdx\n");
    for(; i < storage_capacity; i++) {
        dbg(i);
        dbg("     ");
        dbg(storage[i]);
        dbg("  ");
        dbg(storage[i]);
        dbg("       ");
        if (put_idx == i)
            dbg("<--putIdx ");
        if (get_idx == i)
            dbg("<--getIdx");
        dbg("\n");
    }
    dbg("-----------------------------\n");
}

static void fillBuffer(ByteRingBuffer &buf) {
    char c = 'a';
    while (true) {
        if (buf.write(c) == ByteRingBuffer::FAIL)
            break;
        if (++c == ('z' + 1))
            c = 'a';
    }
}

void ucToolbox::byteRingBufferUnitTest() {
    int8_t storage[10];
    ByteRingBuffer buf(storage, 10);
    dbg("byteRingBufferUnitTest():\n");
    ByteRingBuffer::return_value result = buf.write('a');
    dbg("buf.write('a') result: ");
    dbg(result);
    dbg('\n');
    result = buf.get();
    dbg("buf.get() result: ");
    dbg(result);
    dbg('\n');
    result = buf.get();
    dbg("buf.get() result: ");
    dbg(result);
    dbg('\n');
    dbg("buf.peek() result: ");
    dbg(buf.peek());
    dbg('\n');
    dbg("Writing 'stuff' to buffer. Buffer contents:\n");
    buf.write("stuff", sizeof("stuff"));
    buf.printContents_detailed();
    dbg("Filling buffer. Buffer contents:\n");
    fillBuffer(buf);
    buf.printContents_detailed();
    dbg("buf.write('yeah') result: ");
    result = buf.write("yeah", sizeof("yeah"));
    dbg(result);
    dbg("\nbuf.get() result: ");
    dbg(buf.get());
    buf.printContents_detailed();
    dbg("buf.get() result: ");
    dbg(buf.get());
}
#endif // ifdef BUILD_UNIT_TESTS

