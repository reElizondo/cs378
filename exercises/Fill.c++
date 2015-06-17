// --------
// Fill.c++
// --------

#include <algorithm>  // all_of, fill
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list

#include "gtest/gtest.h"

#include "Fill.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

typedef std::function<void (list<int>::iterator, list<int>::iterator, const int&)> Fill_List_Signature;

struct Fill_List_Fixture : TestWithParam<Fill_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Fill_List_Instantiation,
    Fill_List_Fixture,
    Values(
           fill<list<int>::iterator, int>,
        my_fill<list<int>::iterator, int>));

TEST_P(Fill_List_Fixture, test_1) {
    const size_t s = 3;
    const int    v = 5;
    list<int>    x(s);
    GetParam()(x.begin(), x.end(), v);
    ASSERT_TRUE(all_of(x.begin(), x.end(), [v] (int w) -> bool {return v == w;}));}
