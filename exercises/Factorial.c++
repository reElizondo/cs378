// -------------
// Factorial.c++
// -------------

#include <ctime>    // clock, clock_t, CLOCKS_PER_SEC
#include <iomanip>  // setprecision, setw
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "Factorial.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

typedef int (*Factorial_Signature) (int);

struct Factorial_Fixture : TestWithParam<Factorial_Signature> {};

INSTANTIATE_TEST_CASE_P (
    Factorial_Instantiation,
    Factorial_Fixture,
    Values(
        factorial_recursion,
        factorial_tail_recursion,
        factorial_iteration));

TEST_P(Factorial_Fixture, test_0) {
	ASSERT_EQ(GetParam()(0), 1);}

TEST_P(Factorial_Fixture, test_1) {
	ASSERT_EQ(GetParam()(1), 1);}

TEST_P(Factorial_Fixture, test_2) {
	ASSERT_EQ(GetParam()(2), 2);}

TEST_P(Factorial_Fixture, test_3) {
	ASSERT_EQ(GetParam()(3), 6);}

TEST_P(Factorial_Fixture, test_4) {
	ASSERT_EQ(GetParam()(4), 24);}

TEST_P(Factorial_Fixture, test_5) {
	ASSERT_EQ(GetParam()(5), 120);}

TEST_P(Factorial_Fixture, test_6) {
    const clock_t b = clock();
    for (int i = 0; i != 1000; ++i)
        GetParam()(12);
    const clock_t e = clock();
    cout << fixed << setprecision(3) << setw(5);
    cout << ((e - b) * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << endl;
    cout << endl;}

/*
% Factorial
Running main() from gtest_main.cc
[==========] Running 21 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 21 tests from Factorial_Instantiation/Factorial_Fixture
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_0/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_0/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_0/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_0/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_0/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_0/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_1/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_1/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_1/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_1/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_1/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_1/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_2/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_2/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_2/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_2/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_2/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_2/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_3/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_3/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_3/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_3/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_3/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_3/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_4/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_4/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_4/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_4/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_4/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_4/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_5/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_5/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_5/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_5/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_5/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test_5/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_6/0
0.117 milliseconds

[       OK ] Factorial_Instantiation/Factorial_Fixture.test_6/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_6/1
0.131 milliseconds

[       OK ] Factorial_Instantiation/Factorial_Fixture.test_6/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test_6/2
0.048 milliseconds

[       OK ] Factorial_Instantiation/Factorial_Fixture.test_6/2 (0 ms)
[----------] 21 tests from Factorial_Instantiation/Factorial_Fixture (1 ms total)

[----------] Global test environment tear-down
[==========] 21 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 21 tests.
*/
