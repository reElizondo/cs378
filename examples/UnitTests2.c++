// --------------
// UnitTests2.c++
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
    ASSERT_EQ(cycle_length( 5), 5);}

TEST(MyUnitTests, test_3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% g++-4.8 -pedantic -std=c++11 -Wall UnitTests2.c++ -o UnitTests2 -lgtest -lgtest_main -pthread



% UnitTests2
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from MyUnitTests
[ RUN      ] MyUnitTests.test_1
[       OK ] MyUnitTests.test_1 (0 ms)
[ RUN      ] MyUnitTests.test_2
UnitTests2.c++:29: Failure
Value of: 5
Expected: cycle_length( 5)
Which is: 6
[  FAILED  ] MyUnitTests.test_2 (1 ms)
[ RUN      ] MyUnitTests.test_3
[       OK ] MyUnitTests.test_3 (0 ms)
[----------] 3 tests from MyUnitTests (1 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 2 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] MyUnitTests.test_2

 1 FAILED TEST
*/
