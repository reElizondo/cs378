// -----------
// Vector3.c++
// -----------

#include <algorithm> // equal, fill
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <vector>    // vector

#include "Vector3.h"

using namespace std;

int main () {
    cout << "Vector3.c++" << endl;

    {
    my_vector<int> x;
    assert(x.size() == 0);
    }

    {
    my_vector<int> x(3);
    assert(x.size() == 3);
    assert(x[1] == 0);
    x[1] = 2;
    assert(x[1] == 2);
    fill(x.begin(), x.end(), 4);
    assert(x[1] == 4);
    }

    {
    const my_vector<int> x(3, 4);
    const my_vector<int> y(6, 4);
    assert(equal(x.begin(), x.end(), y.begin()));
    }

    {
    const my_vector<int> x(10, 2);
    const my_vector<int> y(10, 2);
    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(!(x != y));
    assert(!(x <  y));
    assert(!(x >  y));
    }

    cout << "Done." << endl;
    return 0;}
