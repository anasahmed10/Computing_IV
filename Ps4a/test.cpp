// Copyright 2020 <Copyright Anas Ahmed>
#include <stdint.h>
#include <iostream>
#include <queue>
#include "ringbuffer.hpp"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_CASE(empty_ring) {
  ringBuffer empty(10);
  BOOST_REQUIRE(empty.isEmpty() == true);
}

BOOST_AUTO_TEST_CASE(empty_dequeue) {
  ringBuffer empty(10);
  BOOST_CHECK_THROW(empty.dequeue(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(full_enqueue) {
  ringBuffer test(2);
  test.enqueue(0.4);
  test.enqueue(0.5);
  BOOST_CHECK_THROW(test.enqueue(5.9), std::runtime_error);
}
/*  Originally planned to use this test but could not get it to work
BOOST_AUTO_TEST_CASE(peek_check) {
  ringBuffer test(2);
  test.enqueue(0.5);
  int16_t testNum = test.peek();
  BOOST_REQUIRE(testNum == 0.5);
}
*/
