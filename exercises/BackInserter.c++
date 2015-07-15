// ----------------
// BackInserter.c++
// ----------------

// http://www.cplusplus.com/reference/iterator/back_inserter/

#include <iterator> // back_insert_iterator

#include "gtest/gtest.h"

#include "BackInserter.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Back_Insert_Iterator_Fixture : Test {
    typedef T back_insert_iterator_type;};

typedef Types<
               back_insert_iterator<vector<int>>,
            my_back_insert_iterator<vector<int>>>
        back_insert_iterator_types;

TYPED_TEST_CASE(Back_Insert_Iterator_Fixture, back_insert_iterator_types);

TYPED_TEST(Back_Insert_Iterator_Fixture, test) {
    typedef typename TestFixture::back_insert_iterator_type back_insert_iterator_type;

    const vector<int>               x = {5, 6};
          vector<int>               y = {2, 3, 4};
          back_insert_iterator_type z(y);
    copy(x.begin(), x.end(), z);
    ASSERT_EQ(y, vector<int>({2, 3, 4, 5, 6}));}
