/* Fixed-size queue that ensures that the front of the queue is always at element[0]
 * This is useful as a message buffer that can be passed as a pointer to parsing functions,
 * so that the parser doesn't have to worry about wrapping of the queue's buffer.
 *
 * Notes:
 * - Queue buffer can be accessed via begin() and end() iterators
 * - Reading is expensive, each pop() shifts all items in the queue
 *      - You can read without popping using begin() and end()
 * - Doesn't perform element construction & destruction
 * - Onus is on user to check for empty/full conditions before reading/writing
 */

#ifndef CONTIGUOUS_QUEUE_H
#define CONTIGUOUS_QUEUE_H

#include <cstddef>

namespace ucToolbox {

template<typename _Tp, std::size_t _Nm>
class ContiguousQueue {
public:
    typedef _Tp                           value_type;
    typedef _Tp*                          iterator;

    ContiguousQueue() : back_idx(0)
    {
    }

    // Returns a read-only reference to the next (oldest) element in the queue
    // No checking for empty queue is done
    const value_type& front() const {
        return &_M_instance[0];
    }

    // Returns a read-only reference to the last (newest) element in the queue
    // No checking for empty queue is done
    const value_type& back() const {
        return &_M_instance[back_idx];
    }

    // Returns the number of items in the queue
    std::size_t size() const {
        return back_idx;
    }

    bool isFull() const {
        if (back_idx == _Nm)
            return true;
        return false;
    }

    bool isEmpty() const {
        if (back_idx == 0)
            return true;
        return false;
    }

    std::size_t numEmptyElements() const {
        return _Nm - back_idx;
    }

    // Empty the buffer
    void clear() {
        back_idx = 0;
    }

    // Returns a pointer to the front of the queue (read-only)
    const iterator begin() {
        return &_M_instance[0];
    }

    // Returns a pointer to the back of the queue (read-only)
    const iterator end() {
        return &_M_instance[back_idx];
    }

    // Shift elements left, ie element[num_elements] moves to the front
    // of the queue. If num_elements is greater than the current size of
    // the queue then the queue is cleared.
    void shiftLeft(std::size_t num_elements) {
        if (num_elements != 0) {
            if (num_elements >= back_idx) {
                clear();
                return;
            }
            // copy bytes from their old index to their new index
            std::size_t new_index = 0;
            std::size_t old_index = num_elements;
            while (old_index < back_idx) {
                _M_instance[new_index] = _M_instance[old_index];
                new_index++;
                old_index++;
            }

            // Already checked if num_elements > back_idx
            // above, this is safe
            back_idx -= num_elements;
        }
    }

    // Remove the item at the front of the queue
    void pop() {
        if (isEmpty() == false) {
            shiftLeft(1);
        }
    }

    // Get a copy of the element at the front of the buffer and remove it from the buffer
    // If the queue is empty, returns the element at the front of the queue
    value_type readAndPop() {
        value_type ret = _M_instance[0];
        pop();
        return ret;
    }

    // Put a single item on the end of the queue
    void push(const value_type& x) {
        if (isFull() == false) {
            _M_instance[back_idx] = x;
            back_idx++;
        }
    }

    // Write a number of elements to the end of the buffer
    // If len is greater than the free space in the buffer, no
    // elements are written
    void push(const value_type* buf, std::size_t len) {
        if (numEmptyElements() >= len) {
            std::size_t i = 0;
            for(; i < len; i++) {
                // Don't use push() here - we've already checked if
                // all the items will fit. push() checks each time
                _M_instance[back_idx] = buf[i];
                back_idx++;
            }
        }
    }

private:
    // Support zero size queue. Dunno why...probably not
    // needed for a fixed-size queue.
    // Storage of the ring buffer elements is within the
    // class instance - no need to point to an already
    // declared array
    value_type _M_instance[_Nm ? _Nm : 1];

    std::size_t back_idx; // no front_idx, as the front is always at element[0]
};

} // end namespace ucToolbox

#endif // #ifndef CONTIGUOUS_QUEUE_H
