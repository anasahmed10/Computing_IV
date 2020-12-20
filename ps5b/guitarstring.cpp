#include <stdint.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "guitarstring.hpp"
#include "ringbuffer.hpp"

GuitarString::GuitarString(double frequency) : buffer(ceil(44100/frequency)) {
  time = 0;
}

GuitarString::GuitarString(std::vector<int16_t> init) : buffer(init.size()) {
  for (unsigned i = 0; i < init.size(); i++)
    buffer.enqueue(init[i]);

  time = 0;
}

void GuitarString::pluck() {
  buffer.emptyBuffer();

  while (!buffer.isFull())
    buffer.enqueue((int16_t)(rand() & 0xffff));
}

void GuitarString::tic() {
  int n1 = buffer.dequeue();
  int n2 = buffer.peek();

  buffer.enqueue(0.5 * 0.996 * (n1 + n2));

  time++;
}

int16_t GuitarString::sample() const {
  return buffer.peek();
}

int GuitarString::time() const {
  return time;
}
