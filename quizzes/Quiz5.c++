/*
CS378: Quiz #5 (14 pts)
*/

#include <iostream> // boolalpha, cout, endl
using namespace std;
int main () {
    cout << boolalpha;

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (2 pts)

a. 2 3 4
b. 3 4 5

a.
*/
    {
    int a[] = {2, 3, 4};
    for (int v : a)
        ++v;
    for (int v : a)
        cout << v << " ";
    cout << endl;
    }

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (3 pts)

a. 2 false
b. 2 true
c. 3 false
d. 3 true

a.
*/
    {
    int  i = 2;
    int* p = &i;
    ++p;
    cout << i         << " ";
    cout << (p == &i) << endl;
    }

/* -----------------------------------------------------------------------
 3. What is the output of the following?
    (3 pts)

a. 2 false
b. 2 true
c. 3 false
d. 3 true

d.
*/
    {
    int  i = 2;
    int* p = &i;
    ++*p;
    cout << i         << " ";
    cout << (p == &i) << endl;
    }

/* -----------------------------------------------------------------------
 4. What is the output of the following?
    (3 pts)

a. 2 false
b. 2 true
c. 3 false
d. 3 true

d.
*/
    {
    int  i = 2;
    int& r = i;
    ++r;
    cout << i          << " ";
    cout << (&r == &i) << endl;
    }

    return 0;}
