#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include "stddef.h"

namespace ucToolbox {

template<class T, size_t N>
class RingBuffer {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    RingBuffer();

    constexpr size_type
    capacity() const { return N; }

private:
    value_type _storage[N];
    int get_idx;
    int put_idx;
};

template<class T, size_t N>
RingBuffer<T, N>::RingBuffer() {
    get_idx = put_idx = 0;
}

} // end namespace ucToolbox
#endif // RING_BUFFER_H
