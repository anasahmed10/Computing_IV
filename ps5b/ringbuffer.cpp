#include "ringbuffer.hpp"
#include <stdint.h>
#include <iostream>
#include <stdexcept>

ringBuffer::ringBuffer(int capacity) {
  try {												// Throws an exception if the capacity given is less than 1
    if (capacity < 1)
      throw std::invalid_argument("Capacity must be greater than zero");
  } catch(std::invalid_argument& ia) {
    std::cerr << "RB constructor: capacity must be greater than zero.";
    std::cerr << std::endl;
    throw ia;
  }

  buffer.reserve(capacity);
  for (int i = 0; i < capacity; i++)
    buffer.push_back(0);

  first = 0;
  last = 0;
  _size = 0;
  _capacity = capacity;
}

int ringBuffer::size() const {
  return _size;
}

bool ringBuffer::isEmpty() const {
  return _size > 0 ? false : true;
}

bool ringBuffer::isFull() const {
  return _size < _capacity ? false : true;
}

void ringBuffer::enqueue(int16_t arg) {
  try {												// Throws an exception when the queue is full
    if (isFull())
      throw std::runtime_error("Buffer is full");
  } catch(std::runtime_error& re) {
    std::cerr << "Enqueue Error: Buffer is full" << std::endl;
    throw re;
  }

  buffer[last] = arg;

  if (last == _capacity - 1)
    last = 0;
  else
    last++;

  _size++;
}

int16_t ringBuffer::dequeue() {
  try {												// Throws an exception when the queue is empty
    if (isEmpty())
      throw std::runtime_error("Buffer is empty");
  } catch(std::runtime_error& re) {
    std::cerr << "Dequeue Error: Buffer is empty" << std::endl;
    throw re;
  }

  int16_t temp = peek();

  if (first == _capacity - 1)
    first = 0;
  else
    first++;

  _size--;

  return temp;
}

int16_t ringBuffer::peek() const {
  try {												// Throws an exception when the queue is empty
    if (isEmpty())
      throw std::runtime_error("Buffer is empty");
  } catch(std::runtime_error& re) {
    std::cerr << "Peek Error: Buffer is empty" << std::endl;
    throw re;
  }

  return buffer[first];
}

void ringBuffer::emptyBuffer() {
  first = 0;
  last = 0;
  _size = 0;
}
