// -----------
// Vector2.c++
// -----------

// http://www.cplusplus.com/reference/vector/vector/

#include <vector> // vector

#include "gtest/gtest.h"

#include "Vector2.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Vector_Fixture : Test {
    typedef T vector_type;};

typedef Types<
               vector<int>,
            my_vector<int>>
        vector_types;

TYPED_TEST_CASE(Vector_Fixture, vector_types);

TYPED_TEST(Vector_Fixture, test_1) {
    typedef typename TestFixture::vector_type vector_type;

    const vector_type x(10, 2);
    const vector_type y = x;
    assert(equal(x.begin(), x.end(), y.begin()) == true);}

TYPED_TEST(Vector_Fixture, test_2) {
    typedef typename TestFixture::vector_type vector_type;

          vector_type x(10, 2);
    const vector_type y(20, 3);
    x = y;
    assert(equal(x.begin(), x.end(), y.begin()) == true);}
