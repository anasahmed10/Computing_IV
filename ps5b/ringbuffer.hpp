#ifndef _RING_BUFFER_HPP
#define _RING_BUFFER_HPP

#include <stdint.h>
#include <vector>

class ringBuffer {
 private:
  std::vector<int16_t> buffer;
  int _size;
  int _capacity;
  int first;
  int last;
 public:
  explicit ringBuffer(int capacity);
  int size() const;
  bool isEmpty() const;					// Checks to see if the queue is empty
  bool isFull() const;					// Checks to see if the queue is full
  void enqueue(int16_t arg);			// Adds to the end and throws an exception if the queue is full
  int16_t dequeue();					// Subtracts from the front and throws an exception if the queue is empty
  int16_t peek() const;
  void emptyBuffer();
};

#endif
