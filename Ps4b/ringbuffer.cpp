// Copyright 2020 <Copyright Anas Ahmed>
#include "ringbuffer.hpp"

ringBuffer::ringBuffer(int qcapacity) {
  try {
    // Checks to make sure capacity is greater than zero
    if (capacity < 1) ierror ("Capacity must greater than zero");
  }
  catch (std::invalid_argument e) {
    std::cout << "Invalid Argument error: " << e.what() << std::endl;
  }

  capacity = qcapacity;
  first = 0;
  last = 0;
  size = 0;
}

bool ringBuffer::isEmpty() {
  if (size == 0) {return true;}
  return false;
}

bool ringBuffer::isFull() {
  if (size == capacity) {return true;}
  return false;
}

void ringBuffer::enqueue(int16_t x) {
  //  Checks to make sure queue is not full
  try {
    if (this->isFull())
      rerror("Cannot enqueue to a full ring");
  }
  catch (std::runtime_error e) {
    std::cout << "Runtime error: " << e.what() << std::endl;
  }
  ringbuffer.push_back(x);
  ++last;
  ++size;
}

int16_t ringBuffer::dequeue() {
  // Checks to make sure queue is empty
  try {
    if (this->isEmpty())
      rerror("Cannot enqueue to a full ring");
  }
  catch (std::runtime_error e) {
    std::cout << "Runtime error: " << e.what() << std::endl;
  }

  int16_t removed_int = ringbuffer.front();
  ringbuffer.pop_back();
  ++first;
  --size;

  return removed_int;
}

int16_t ringBuffer::peek() {
  int16_t peep = ringbuffer.front();
  return peep;
}
