/*
CS378: Quiz #3 (14 pts)
*/

/* -----------------------------------------------------------------------
 1. For the '<<' operator that is defined on 'ostream', what is the
    l-value / r-value nature of
    the return, the left argument, and the right argument?
    (5 pts)

a. l-value, l-value, l-value
b. l-value, l-value, r-value
c. r-value, l-value, l-value
d. r-value, l-value, r-value
e. r-value, r-value, r-value

b.
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (5 pts)

a. 10
b. 11
c. 21
d. 22

b.

For odd n it's computing (3n + 1) / 2.
(3n + 1) / 2
3n/2 + 1/2
n + n/2 + 1/2
n + n/2 + 1, because n is odd
n + (n >> 1) + 1
*/

#include <iostream> // cout, endl
using namespace std;
int f (int n) {
    return n + (n >> 1) + 1;}
int main () {
    cout << f(7) << endl;
    return 0;}

/* -----------------------------------------------------------------------
 3. Given positive integers, [math]b[/math] and [math]e[/math],
    let [math]m = (e / 2) + 1[/math].
    If [math]b < m[/math], then
    [math]max\_cycle\_length(b, e) = max\_cycle\_length(m, e)[/math].
    [Collatz]
    (4 pts)

a. False
b. True

Consider b = 10, e = 100.
Then m = (100 / 2) + 1 = 51.
max_cycle_length(10, 100) = max_cycle_length(51, 100)
All the numbers in the range [10, 50] can be mapped to numbers in the
range [51, 100] by one or more doublings, so none of the numbers in the
range [10, 50] could have a larger cycle length than the numbers in the
range [51, 100].
*/
