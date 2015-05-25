// -------------
// Coverage2.c++
// -------------

// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "Collatz2.h"

TEST(CoverageFixture, test_1) {
    ASSERT_EQ(cycle_length(1), 1);}

TEST(CoverageFixture, test_2) {
    ASSERT_EQ(cycle_length(2), 2);}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Coverage2.c++ -o Coverage2 /usr/local/lib/gtest_main.a



% Coverage2
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from CoverageFixture
[ RUN      ] CoverageFixture.test_1
[       OK ] CoverageFixture.test_1 (0 ms)
[ RUN      ] CoverageFixture.test_2
[       OK ] CoverageFixture.test_2 (0 ms)
[----------] 2 tests from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 2 tests.



% gcov -b Coverage2.c++ | grep -A 5 "File 'Coverage2.c++'"
File 'Coverage2.c++'
Lines executed:92.31% of 13
Branches executed:61.90% of 42
Taken at least once:30.95% of 42
No calls
Coverage2.c++:creating 'Coverage2.c++.gcov'
*/
