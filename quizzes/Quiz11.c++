/*
CS378: Quiz #11 (14 pts)
*/

#include <algorithm> // copy
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator

using namespace std;

template <typename II, typename FI>
FI f (II b, II e, int n, FI x) {
    x = copy(b, e, x);
    fill(x, x + n, 0);
    return x + n;}

template <typename II, typename OI>
OI g (II b, II e, int n, OI x) {
    return copy(b, e - n, x);}

int main () {

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (7 pts)

a. 3 0 0 2 3 4
b. 3 2 3 4 0 0
c. 5 0 0 2 3 4
d. 5 2 3 4 0 0

d.
*/
{
const int  a []  = {2, 3, 4};
      int  x [5] = {};
      int* p = f(a, a + 3, 2, x);
cout << (p - x) << " ";
copy(x, x + 5, ostream_iterator<int>(cout, " "));
cout << endl;
}
/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (7 pts)

a. 1 0 0 0 0 2
b. 1 2 0 0 0 0
c. 2 0 0 0 0 2
d. 2 2 0 0 0 0

b.
*/
{
const int  a []  = {2, 3, 4};
      int  x [5] = {};
      int* p = g(a, a + 3, 2, x);
cout << (p - x) << " ";
copy(x, x + 5, ostream_iterator<int>(cout, " "));
cout << endl;
}
return 0;}
