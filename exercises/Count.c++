// ---------
// Count.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/count/

#include <algorithm>  // equal, count
#include <cstddef>    // ptrdiff_t
#include <functional> // function

#include "gtest/gtest.h"

#include "Count.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

using Count_Array_Signature = function<ptrdiff_t (const int*, const int*, const int&)>;

struct Count_Array_Fixture : TestWithParam<Count_Array_Signature> {
    const int _a[4];

    Count_Array_Fixture () :
            _a {2, 3, 4, 3}
        {}};

INSTANTIATE_TEST_CASE_P(
    Count_Array_Instantiation,
    Count_Array_Fixture,
    Values(
           count  <const int*, const int&>,
        my_count_1<const int*, const int&>,
        my_count_2<const int*, const int&>));

TEST_P(Count_Array_Fixture, test_1) {
	ASSERT_EQ(0, GetParam()(_a, _a + 4, 1));}

TEST_P(Count_Array_Fixture, test_2) {
	ASSERT_EQ(1, GetParam()(_a, _a + 4, 2));}

TEST_P(Count_Array_Fixture, test_3) {
	ASSERT_EQ(2, GetParam()(_a, _a + 4, 3));}

TEST_P(Count_Array_Fixture, test_4) {
	ASSERT_EQ(1, GetParam()(_a, _a + 4, 4));}

TEST_P(Count_Array_Fixture, test_5) {
	ASSERT_EQ(0, GetParam()(_a, _a + 4, 5));}
