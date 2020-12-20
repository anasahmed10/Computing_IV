//  Copyright 2020 <Copyright Anas Ahmed>                                                                                                             
#ifndef _HOME_ANAS_COMP4_PS4B_STRINGSOUND_HPP_
#define _HOME_ANAS_COMP4_PS4B_STRINGSOUND_HPP_
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <random>
#include <vector>
#include <queue>
#include <string>
#include "ringbuffer.hpp"

class StringSound {
 public:
  explicit StringSound(double frequency);
  explicit StringSound(std::vector<int16_t> init);
  StringSound (const StringSound &obj){};
  int length();
  void pluck();
  void tic();
  int16_t sample();
  int getTime();
 private:
  ringBuffer* rb;
  int time;
};

#endif
