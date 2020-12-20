#include "stringsound.hpp"

StringSound::StringSound(double frequency) {
  int n = int(44100 / frequency);
  rb->capacity = n;
  rb->first = 0;
  rb->last = 0;
  rb->size = 0;
  for(int i = 0; i < n; i++) {
    rb->enqueue(0);
  }
}

StringSound::StringSound(std::vector<int16_t> init) {
  rb->capacity = init.size();
  for(int i = 0; i < init.size(); i++) {
    rb->enqueue(init.at(i));
  }
}

int StringSound::length() {
  return rb->size;
}

void StringSound::pluck() {
  int16_t newNum;
  int max = rb->size;
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(-1.5, 1.5);
  for(int i = 0; i < max; i++) {rb->dequeue();}
  for(int i = 0; i < max; i++) {
    rb->enqueue((int16_t)distribution(generator));
  }
}

void StringSound::tic() {
  int16_t first, second, average;
  first = rb->peek();
  rb->dequeue();
  second = rb->peek();
  average = .994 * ((first + second) / 2);
  rb->enqueue(average);
  ++time;
}

int16_t StringSound::sample() {
  return rb->peek();
}

int StringSound::getTime() {
  return time;
}
