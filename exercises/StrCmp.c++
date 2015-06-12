// ----------
// StrCmp.c++
// ----------

// http://www.cplusplus.com/reference/cstring/strcmp/

#include <cassert>  // assert
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
