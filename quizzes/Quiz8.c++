/*
CS378: Quiz #8 (14 pts)
*/

#include <algorithm> // copy
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <vector>    // vector

using namespace std;

int main () {

/* -----------------------------------------------------------------------
 1. In the paper, "Mariner 1", what was the software bug?
    (4 pts)

a. the conversion of a 16-bit number to a 64-bit number
b. the conversion of a 64-bit number to a 16-bit number
c. the ommission of a hyphen
d. the presence of a hyphen

c.
*/

/* -----------------------------------------------------------------------
 2. What is the WEAKEST iterator that std::fill() needs?
    (3 pts)

a. input
b. output
c. forward
d. bidirectional
e. random access

c.
*/

/* -----------------------------------------------------------------------
 3. What is the WEAKEST iterator that std::all_of() needs?
    (3 pts)

a. input
b. output
c. forward
d. bidirectional
e. random access

a.
*/

/* -----------------------------------------------------------------------
 4. What is the output of the following?
    (4 pts)

a. 7: 3 4 7 8
b. 7: 5 3 4 8
c. 8: 3 4 7 8
d. 8: 5 3 4 8

d.
*/

const vector<int>     x = {2, 3, 4};
vector<int>           y = {5, 6, 7, 8};
vector<int>::iterator p = copy(x.begin() + 1, x.begin() + 3, y.begin() + 1);
cout << *p << ": ";
copy(y.begin(), y.end(), ostream_iterator<int>(cout, " "));
cout << endl;

return 0;}
