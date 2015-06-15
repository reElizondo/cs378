// -------------
// Factorial.c++
// -------------

#include <ctime>    // clock, clock_t, CLOCKS_PER_SEC
#include <iomanip>  // setprecision, setw
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "Factorial.h"

using testing::TestWithParam;
using testing::Values;

typedef int (*F) (int);

struct FactorialFixture : TestWithParam<F> {};

INSTANTIATE_TEST_CASE_P (
    FactorialInstantiation,
    FactorialFixture,
    Values(
        factorial_recursion,
        factorial_tail_recursion,
        factorial_iteration));

TEST_P (FactorialFixture, test_0) {
	ASSERT_EQ(GetParam()(0), 1);}

TEST_P (FactorialFixture, test_1) {
	ASSERT_EQ(GetParam()(1), 1);}

TEST_P (FactorialFixture, test_2) {
	ASSERT_EQ(GetParam()(2), 2);}

TEST_P (FactorialFixture, test_3) {
	ASSERT_EQ(GetParam()(3), 6);}

TEST_P (FactorialFixture, test_4) {
	ASSERT_EQ(GetParam()(4), 24);}

TEST_P (FactorialFixture, test_5) {
	ASSERT_EQ(GetParam()(5), 120);}

TEST_P (FactorialFixture, test_6) {
    const clock_t b = clock();
    for (int i = 0; i != 1000; ++i)
        GetParam()(12);
    const clock_t e = clock();
    std::cout << std::fixed << std::setprecision(3) << std::setw(5);
    std::cout << ((e - b) * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << std::endl;
    std::cout << std::endl;}

/*
% Factorial
Running main() from gtest_main.cc
[==========] Running 21 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 21 tests from FactorialInstantiation/FactorialFixture
[ RUN      ] FactorialInstantiation/FactorialFixture.test_0/0
[       OK ] FactorialInstantiation/FactorialFixture.test_0/0 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_0/1
[       OK ] FactorialInstantiation/FactorialFixture.test_0/1 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_0/2
[       OK ] FactorialInstantiation/FactorialFixture.test_0/2 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_1/0
[       OK ] FactorialInstantiation/FactorialFixture.test_1/0 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_1/1
[       OK ] FactorialInstantiation/FactorialFixture.test_1/1 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_1/2
[       OK ] FactorialInstantiation/FactorialFixture.test_1/2 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_2/0
[       OK ] FactorialInstantiation/FactorialFixture.test_2/0 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_2/1
[       OK ] FactorialInstantiation/FactorialFixture.test_2/1 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_2/2
[       OK ] FactorialInstantiation/FactorialFixture.test_2/2 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_3/0
[       OK ] FactorialInstantiation/FactorialFixture.test_3/0 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_3/1
[       OK ] FactorialInstantiation/FactorialFixture.test_3/1 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_3/2
[       OK ] FactorialInstantiation/FactorialFixture.test_3/2 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_4/0
[       OK ] FactorialInstantiation/FactorialFixture.test_4/0 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_4/1
[       OK ] FactorialInstantiation/FactorialFixture.test_4/1 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_4/2
[       OK ] FactorialInstantiation/FactorialFixture.test_4/2 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_5/0
[       OK ] FactorialInstantiation/FactorialFixture.test_5/0 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_5/1
[       OK ] FactorialInstantiation/FactorialFixture.test_5/1 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_5/2
[       OK ] FactorialInstantiation/FactorialFixture.test_5/2 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_6/0
0.117 milliseconds

[       OK ] FactorialInstantiation/FactorialFixture.test_6/0 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_6/1
0.131 milliseconds

[       OK ] FactorialInstantiation/FactorialFixture.test_6/1 (0 ms)
[ RUN      ] FactorialInstantiation/FactorialFixture.test_6/2
0.048 milliseconds

[       OK ] FactorialInstantiation/FactorialFixture.test_6/2 (0 ms)
[----------] 21 tests from FactorialInstantiation/FactorialFixture (1 ms total)

[----------] Global test environment tear-down
[==========] 21 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 21 tests.
*/
