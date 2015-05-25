// --------------
// UnitTests3.c++
// --------------

// https://code.google.com/p/googletest/
// https://code.google.com/p/googletest/wiki/Primer#Assertions

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "Collatz2.h"

TEST(MyUnitTests, test_1) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(MyUnitTests, test_2) {
    ASSERT_EQ(cycle_length( 5), 6);}

TEST(MyUnitTests, test_3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% g++ -pedantic -std=c++11 -Wall UnitTests3.c++ -o UnitTests3 -lgtest -lgtest_main -pthread



% UnitTests3
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from MyUnitTests
[ RUN      ] MyUnitTests.test_1
[       OK ] MyUnitTests.test_1 (0 ms)
[ RUN      ] MyUnitTests.test_2
[       OK ] MyUnitTests.test_2 (0 ms)
[ RUN      ] MyUnitTests.test_3
[       OK ] MyUnitTests.test_3 (0 ms)
[----------] 3 tests from MyUnitTests (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 3 tests.
*/
