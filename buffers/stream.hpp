#include "byte_ring_buffer.hpp"

namespace ucToolbox {

class Stream: public ByteRingBuffer {
public:
    Stream(int8_t* storage_location, uint16_t capacity) :
            ByteRingBuffer(storage_location, capacity) { }

    return_value operator<<(const char);
};

#ifdef BUILD_UNIT_TESTS
void streamUnitTest();
#endif

} // end namespace ucToolbox
