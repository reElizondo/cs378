// -----------
// Vector2.c++
// -----------

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <vector>    // vector

#include "Vector2.h"

using namespace std;

int main () {
    cout << "Vector2.c++" << endl;

    {
    const my_vector<int> x(10, 2);
    const my_vector<int> y = x;
    assert(equal(x.begin(), x.end(), y.begin()) == true);
    }

    {
          my_vector<int> x(10, 2);
    const my_vector<int> y(20, 3);
    x = y;
    assert(equal(x.begin(), x.end(), y.begin()) == true);
    }

    cout << "Done." << endl;
    return 0;}
