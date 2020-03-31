// Lab3 EOOP. Please do not modify signatures in this file.
// You can add some private methods if you feel they are necessary.
#import <cstdlib>
#include <stdexcept>
#include <iostream>

#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP


/*
 Ring buffer is a 1-D buffer that is circular.
 There are two indices, one for writing (head) and one for reading (tail).
 Each time a value is written into the full buffer the oldest value is overwritten and
 tail is moved appropriately to point at the oldest value after overwrite.
 */
class RingBuffer {

public:
    explicit RingBuffer(unsigned int capacity);

    // Copy constructor
    // Allocates memory and copies buffer data from other
    RingBuffer(const RingBuffer &other);;

    // Copies buffer data from other
    // If capacities don't match throws exception std::invalid_argument
    RingBuffer &operator=(const RingBuffer &other); // assignment operator
    ~RingBuffer();

    unsigned int size() const { return size_; }

    unsigned int capacity() const { return capacity_; }

    bool isFull() const { return size_ == capacity_; }

    bool isEmpty() const { return size_ == 0; }

    // Reads the value underneath tail_ and move it by one
    // If buffer is empty throws exception
    int &read();

    // Write value underneath head_ index and move it by one
    // It can possibly overwrite 'oldest' data, in which case tail_ should be moved
    // as well.
    void write(int value);
private:
    const unsigned int capacity_; // capacity of the buffer cannot be changed after initialization
    unsigned int size_; // number of elements in the buffer
    unsigned int head_; // index of the head
    unsigned int tail_; // index of the tail
    int *data_; // buffer representation as 1-D array of ints

    //circular increment of index, if index is equal to last valid index of data, it turns it back to zero.
    void increment(unsigned int &parameter); //should be used on head_ or tail_ only.
};

RingBuffer::RingBuffer(unsigned int capacity) : capacity_(capacity) {
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    data_ = new int[capacity_];
}

RingBuffer::RingBuffer(const RingBuffer &other) : capacity_(other.capacity()) {
    data_ = new int[other.capacity()];
    *this = other;
}

RingBuffer::~RingBuffer() {
    delete[] data_;
}

int &RingBuffer::read() {
    if (size_ == 0) throw std::logic_error("Reading from empty buffer");

    int &result = (int &) data_[tail_];
    size_--;

    increment(tail_);
    return result;
}

void RingBuffer::write(int value) {
    data_[head_] = value;
    if (!isFull()) {
        size_++;
    } else {
        tail_ = head_;
        increment(tail_);
    }
    increment(head_);
}

RingBuffer &RingBuffer::operator=(const RingBuffer &other) {
    if (this == &other) return *this;
    if (capacity_ != other.capacity_) {
        throw std::invalid_argument("Capacities differ");
    }

    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;

    for (unsigned int i = 0; i < size(); i++) {
        data_[i] = other.data_[i];
    }
    return *this;
}

void RingBuffer::increment(unsigned int &parameter) {
    if (parameter == capacity_ - 1) {
        parameter = 0;
    } else {
        parameter++;
    }
}


#endif  // RINGBUFFER_HPP
