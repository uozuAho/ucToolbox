/* I have a feeling that this may be pretty inefficient for low-level byte buffers.
 * TODO: Compare with a dedicated byte buffer class (eg. when used as a uart buffer)
 */
#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include "stddef.h"

namespace ucToolbox {

enum return_value_e {
    OK,
    FAIL
};

template<class T, size_t N>
class RingBuffer {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    RingBuffer();
    bool isFull();
    bool isEmpty();
    return_value_e get(T* item);
    return_value_e put(T item);

    constexpr size_type
    capacity() const { return N; }

private:
    value_type _storage[N];
    int get_idx;
    int put_idx;
    bool full;  // flag used since get_idx == put_idx could mean the buffer is empty or full
};

template<class T, size_t N>
RingBuffer<T, N>::RingBuffer() {
    get_idx = put_idx = 0;
    full = false;
}

template<class T, size_t N>
inline bool RingBuffer<T, N>::isFull() {
    if (get_idx == put_idx && full)
        return true;
    else
        return false;
}

template<class T, size_t N>
inline bool RingBuffer<T, N>::isEmpty() {
    if (get_idx == put_idx && full)
        return false;
    else
        return true;
}

template<class T, size_t N>
return_value_e RingBuffer<T, N>::get(T* item) {
    if (isEmpty())
        return FAIL;
    else {
        full = false;
        int temp_idx = get_idx;
        if (++get_idx == capacity())
            get_idx = 0;
        *item = _storage[temp_idx];
        return OK;
    }
}

template<class T, size_t N>
return_value_e RingBuffer<T, N>::put(T item) {
    if (isFull())
        return FAIL;
    else {
        int temp_idx = put_idx;
        if (++put_idx == capacity())
            put_idx = 0;
        _storage[temp_idx] = item;

        if (put_idx == get_idx)
            full = true;
        return OK;
    }
}

} // end namespace ucToolbox
#endif // RING_BUFFER_H
