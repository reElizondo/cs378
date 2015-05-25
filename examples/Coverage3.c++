// -------------
// Coverage3.c++
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

TEST(CoverageFixture, test_3) {
    ASSERT_EQ(cycle_length(3), 8);}


/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Coverage3.c++ -o Coverage3 /usr/local/lib/gtest_main.a



% Coverage3
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from CoverageFixture
[ RUN      ] CoverageFixture.test_1
[       OK ] CoverageFixture.test_1 (0 ms)
[ RUN      ] CoverageFixture.test_2
[       OK ] CoverageFixture.test_2 (0 ms)
[ RUN      ] CoverageFixture.test_3
[       OK ] CoverageFixture.test_3 (0 ms)
[----------] 3 tests from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 3 tests.



% gcov -b Coverage3.c++ | grep -A 5 "File 'Coverage3.c++'"
File 'Coverage3.c++'
Lines executed:100.00% of 15
Branches executed:59.32% of 59
Taken at least once:30.51% of 59
No calls
Coverage3.c++:creating 'Coverage3.c++.gcov'
*/
