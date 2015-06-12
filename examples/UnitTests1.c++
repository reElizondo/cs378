// --------------
// UnitTests1.c++
// --------------

// https://code.google.com/p/googletest/
// https://code.google.com/p/googletest/wiki/Primer#Assertions

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "Collatz1.h"

TEST(MyUnitTests, test_1) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(MyUnitTests, test_2) {
    ASSERT_EQ(cycle_length( 5), 6);}

TEST(MyUnitTests, test_3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% g++-4.8 -pedantic -std=c++11 -Wall UnitTests1.c++ -o UnitTests1 -lgtest -lgtest_main -pthread



% UnitTests1
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from MyUnitTests
[ RUN      ] MyUnitTests.test_1
Assertion failed: (c > 0), function cycle_length, file ./Collatz1.h, line 19.
*/
