/*
CS378: Quiz #7 (14 pts)
*/

#include <functional> // greater
#include <iostream>   // cout, endl
#include <queue>      // priority_queue
#include <vector>     // vector

using namespace std;

int main () {

/* -----------------------------------------------------------------------
 1. What is the complexity of inserting an element into std::priority_queue<T>?
    (3 pts)

a. O(1)
b. O(log n)
c. O(n)
d. O(n log n)

b.
*/

/* -----------------------------------------------------------------------
 2. Which of the following can NOT be a backing container for std::priority_queue<T>?
    (3 pts)

a. deque
b. list
c. vector

b.
*/

/* -----------------------------------------------------------------------
 3. What is the output of the following?
    (4 pts)

a. 2
b. 3
c. 4
d. 5

d.
*/

priority_queue<int> p;
p.push(4);
p.push(2);
p.push(5);
p.push(3);
cout << p.top() << endl;

/* -----------------------------------------------------------------------
 4. What is the output of the following?
    (4 pts)

a. 2
b. 3
c. 4
d. 5

a.
*/

priority_queue<int, vector<int>, greater<int>> q;
q.push(4);
q.push(2);
q.push(5);
q.push(3);
cout << q.top() << endl;

return 0;}
