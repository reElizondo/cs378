// --------
// Copy.c++
// --------

// http://www.cplusplus.com/reference/algorithm/copy/

#include <algorithm> // copy, equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

#include "gtest/gtest.h"

#include "Copy.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

typedef std::function<vector<int>::iterator (list<int>::const_iterator, list<int>::const_iterator, vector<int>::iterator)> Copy_List_Signature;

struct Copy_List_Fixture : TestWithParam<Copy_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Copy_List_Instantiation,
    Copy_List_Fixture,
    Values(
           copy<list<int>::const_iterator, vector<int>::iterator>,
        my_copy<list<int>::const_iterator, vector<int>::iterator>));

TEST_P(Copy_List_Fixture, test) {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    vector<int>::iterator p = GetParam()(x.begin(), x.end(), y.begin() + 1);
    assert(p == y.begin() + 4);
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin() + 1));}
