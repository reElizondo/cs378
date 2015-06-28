/*
CS378: Quiz #9 (14 pts)
*/

#include <algorithm> // copy
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <vector>    // vector

using namespace std;

int main () {

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (7 pts)

a. 6
b. 7

a.
*/

{
int  i = 2;
auto f = [i] (int j) -> int {return i + j;};
i = 3;
cout << f(4) << endl;
}

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (7 pts)

a. 6
b. 7

b.
*/

{
int  i = 2;
auto f = [&i] (int j) -> int {return i + j;};
i = 3;
cout << f(4) << endl;
}

return 0;}
