// ----------
// StrCmp.c++
// ----------

// http://www.cplusplus.com/reference/cstring/strcmp/

#include <cstring>  // strcmp
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "StrCmp.h"

using testing::TestWithParam;
using testing::Values;

typedef int (*F) (const char*, const char*);

struct StrCmpFixture : TestWithParam<F> {};

INSTANTIATE_TEST_CASE_P (
    StrCmpInstantiation,
    StrCmpFixture,
    Values(
        my_strcmp,
           strcmp));

TEST_P (StrCmpFixture, test_1) {
	ASSERT_EQ(GetParam()("abc", "abc"), 0);}

TEST_P (StrCmpFixture, test_2) {
	ASSERT_EQ(GetParam()("abb", "abc"), 'b' - 'c');}

TEST_P (StrCmpFixture, test_3) {
	ASSERT_EQ(GetParam()("aba", "abc"), 'a' - 'c');}

TEST_P (StrCmpFixture, test_4) {
	ASSERT_EQ(GetParam()("abd", "abc"), 'd' - 'c');}

TEST_P (StrCmpFixture, test_5) {
	ASSERT_EQ(GetParam()("abe", "abc"), 'e' - 'c');}

TEST_P (StrCmpFixture, test_6) {
	ASSERT_EQ(GetParam()("ab", "abc"), 0 - 'c');}

TEST_P (StrCmpFixture, test_7) {
	ASSERT_EQ(GetParam()("abc", "ab"), 'c' - 0);}

TEST_P (StrCmpFixture, test_8) {
	ASSERT_EQ(GetParam()("", ""), 0);}

TEST_P (StrCmpFixture, test_9) {
	ASSERT_EQ(GetParam()("a", ""), 'a' - 0);}

TEST_P (StrCmpFixture, test_10) {
	ASSERT_EQ(GetParam()("", "a"), 0 - 'a');}

/*
% StrCmp
Running main() from gtest_main.cc
[==========] Running 20 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 20 tests from StrCmpInstantiation/StrCmpFixture
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_1/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_1/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_1/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_1/1 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_2/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_2/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_2/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_2/1 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_3/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_3/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_3/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_3/1 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_4/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_4/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_4/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_4/1 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_5/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_5/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_5/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_5/1 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_6/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_6/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_6/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_6/1 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_7/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_7/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_7/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_7/1 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_8/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_8/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_8/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_8/1 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_9/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_9/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_9/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_9/1 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_10/0
[       OK ] StrCmpInstantiation/StrCmpFixture.test_10/0 (0 ms)
[ RUN      ] StrCmpInstantiation/StrCmpFixture.test_10/1
[       OK ] StrCmpInstantiation/StrCmpFixture.test_10/1 (0 ms)
[----------] 20 tests from StrCmpInstantiation/StrCmpFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 20 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 20 tests.
*/
