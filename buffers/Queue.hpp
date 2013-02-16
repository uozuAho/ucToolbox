/* Attempting to write a fixed-size Queue template to replace std::queue. Supports all the
 * std::queue member functions (apart from constructor), however I may have renamed some since I
 * think names like "isEmpty()" is more readily understood than "empty()".
 *
 * Notes:
 * - No random access //TODO: this may be useful - needs custom iterators that handle
 *                            buffer wrapping
 * - Doesn't perform element construction & destruction
 * - Onus is on user to check for empty/full conditions before reading/writing
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

// Unit tests need special access to private members
#ifdef BUILD_UNIT_TESTS
    #define INCLUDE_DEBUG_FUNCTIONS
#endif

namespace ucToolbox {

template<typename _Tp, std::size_t _Nm>
class Queue {
public:
    typedef _Tp                           value_type;
    typedef _Tp*                          iterator;

    Queue() : front_idx(0), back_idx(0), full(false)
    {
    }

    // Returns a read-only reference to the next (oldest) element in the queue
    // No checking for empty queue is done
    const value_type& front() const {
        return &_M_instance[front_idx];
    }

    // Returns a copy of the element at the front of the queue
    // No checking for empty queue is done
    value_type front() {
        return _M_instance[front_idx];
    }

    // Returns a read-only reference to the last (newest) element in the queue
    // No checking for empty queue is done
    const value_type& back() const {
        return &_M_instance[back_idx];
    }

    // Remove the next (oldest) item in the queue
    void pop() {
        if (isEmpty() == false) {
            full = false;
            if (++front_idx == _Nm)
                front_idx = 0;
        }
    }

    // Get a copy of the element at the front of the buffer and remove it from the buffer
    // If the queue is empty, returns the element at the front of the queue
    value_type readAndPop() {
        value_type ret = _M_instance[front_idx];
        pop();
        return ret;
    }

    // Write a single element to the end of the buffer (ie the "write index")
    void push(const value_type& x) {
        if (full == false) {
            _M_instance[back_idx] = x;
            if (++back_idx == _Nm)
                back_idx = 0;
            if (back_idx == front_idx)
                full = true;
        }
    }

    // Write a number of elements to the end of the buffer
    // If len is greater than the free space in the buffer, no
    // elements are written
    void push(const value_type* buf, std::size_t len) {
        if (numEmptyElements() >= len) {
            std::size_t i = 0;
            for(; i < len; i++) {
                push(buf[i]);
            }
        }
    }

    bool isFull() const {
        return full;
    }

    bool isEmpty() const {
        if (full == false && front_idx == back_idx)
            return true;
        return false;
    }

    std::size_t numEmptyElements() const {
        if (isEmpty())
            return _Nm;
        else if (isFull())
            return 0;
        else {
            std::size_t ret = front_idx - back_idx;
            if (back_idx > front_idx)
                ret += _Nm;
            return ret;
        }
    }

    // Returns the number of items in the queue
    std::size_t size() const {
        return _Nm - numEmptyElements();
    }

protected:
    // Support zero size queue. Dunno why...probably not
    // needed for a fixed-size queue.
    // Storage of the ring buffer elements is within the
    // class instance - no need to point to an already
    // declared array
    value_type _M_instance[_Nm ? _Nm : 1];

    std::size_t front_idx, back_idx;

    // flag used since get_idx == put_idx could mean the buffer is empty or full
    bool full;
};

} // end namespace ucToolbox

#endif // #ifndef QUEUE_H
