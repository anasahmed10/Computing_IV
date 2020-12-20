// Based on the test.cpp file given on blackboard

#include <iostream>
#include <string>
#include "fiblsfr.hpp"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/included/unit_test.hpp>

// This test is based off of the first test and is meant to test multiple instances of the step test on one string
BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps){
	FibLSFR test1("1011011000110110");
	BOOST_REQUIRE(test1.step() == 0);
	BOOST_REQUIRE(test1.step() == 0);
        BOOST_REQUIRE(test1.step() == 0);
        BOOST_REQUIRE(test1.step() == 1);
        BOOST_REQUIRE(test1.step() == 1);
        BOOST_REQUIRE(test1.step() == 0);
        BOOST_REQUIRE(test1.step() == 0);
        BOOST_REQUIRE(test1.step() == 1);
}

// This test is meant to test the generate function
BOOST_AUTO_TEST_CASE(generateTest){
	FibLSFR test3("1100011011000011");
	BOOST_REQUIRE(test3.generate(5) == 6);
}

// This test uses a smaller string and ensures the step and generate function still work
BOOST_AUTO_TEST_CASE(smallBits){
	FibLSFR test4("0110010");
	BOOST_REQUIRE(test4.step() == 0);
	BOOST_REQUIRE(test4.generate(7) == 2);
}

