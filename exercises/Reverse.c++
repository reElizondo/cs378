// -----------
// Reverse.c++
// -----------

// http://www.cplusplus.com/reference/algorithm/reverse/

#include <algorithm>  // equal, reverse
#include <functional> // function

#include "gtest/gtest.h"

#include "Reverse.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

using Reverse_Array_Signature = function<void (int*, int*)>;

struct Reverse_Array_Fixture : TestWithParam<Reverse_Array_Signature> {};

INSTANTIATE_TEST_CASE_P(
    Reverse_Array_Instantiation,
    Reverse_Array_Fixture,
    Values(
           reverse<int*>,
        my_reverse<int*>));

TEST_P(Reverse_Array_Fixture, test_0) {
    int a[] = {2, 3, 4};
    int b[] = {2, 3, 4};
    GetParam()(a, a);
	ASSERT_TRUE(equal(a, a, b));}

TEST_P(Reverse_Array_Fixture, test_1) {
    int a[] = {2, 3, 4};
    int b[] = {2, 3, 4};
    GetParam()(a, a + 1);
	ASSERT_TRUE(equal(a, a + 1, b));}

TEST_P(Reverse_Array_Fixture, test_2) {
    int a[] = {2, 3, 4};
    int b[] = {3, 2, 4};
    GetParam()(a, a + 2);
	ASSERT_TRUE(equal(a, a + 2, b));}

TEST_P(Reverse_Array_Fixture, test_3) {
    int a[] = {2, 3, 4};
    int b[] = {4, 3, 2};
    GetParam()(a, a + 3);
	ASSERT_TRUE(equal(a, a + 3, b));}
