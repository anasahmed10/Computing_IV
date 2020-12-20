//  Copyright 2020 <Copyright Anas Ahmed>
#ifndef _HOME_ANAS_COMP4_PS4A_RINGBUFFER_HPP_
#define _HOME_ANAS_COMP4_PS4A_RINGBUFFER_HPP_
#include <stdint.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

class ringBuffer{
 public:
  explicit ringBuffer(int capacity);
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
  int capacity;
  int size;
  int first;
  int last;
  void rerror(const std::string& s) {
    throw std::runtime_error(s);
  }
  void ierror(const std::string& s) {
    throw std::invalid_argument(s);
  }
 private:
  std::queue<int16_t> ringbuffer;
};

// Originally designed ringBuffer class with Vector, but changed it to queue
/*class ringBuffer{
public:
  ringBuffer(int capacity);
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
  int capacity;
  int size;
  int first;
  int last;*

private:
  vector<int16_t> ringbuffer;
};

ringBuffer::ringBuffer(int capacity){
  ringbuffer.size() = capacity;
  first = 0;
  last = 1;
  size = 0;
}

bool ringBuffer::isEmpty(){
  if(size == 0){return true;}
  return false;
}

bool ringBuffer::isFull(){
  if(size == capacity){return true;}
  return false;
}

void ringBuffer::enqueue(int16_t x){
  if(this.isFull() == true){return;}
  auto spot = ringbuffer.at(last);
  ringbuffer.insert(spot, x);
  ++last;
  ++size;
}

int16_t ringBuffer::dequeue(){
  ringbuffer.pop_back();
  --last;
  --size;
}
*/
#endif  //  _HOME_ANAS_COMP4_PS4A_RINGBUFFER_HPP_
