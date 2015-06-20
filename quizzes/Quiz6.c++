/*
CS378: Quiz #6 (14 pts)
*/

/* -----------------------------------------------------------------------
 1. Which of the following practices demonstrates effective pair programming?
    [All I Really Needed to Know about Pair Programming I Learned in Kindergarten]
    (3 pts)

a. Each partner writing separate parts.
b. Each partner writing both parts and then submitting the best.
c. Each partner writing both parts and then submitting the best combination.
d. Sharing a monitor and keyboard while coding.
e. One partner writing the interface and tests, the other the implementation.
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (3 pts)

a. false false
b. false true
c. true false
d. true true

d.
*/

#include <iostream> // boolalpha, cout, endl
using namespace std;
int main () {
    int a[] = {2, 3, 4, 2, 3};
    cout << equal(a + 1, a + 3, a + 1) << " ";
    cout << equal(a,     a + 2, a + 3) << endl;
    return 0;}

/* -----------------------------------------------------------------------
 3. What is the WEAKEST iterator that the algorithm std::equal() can demand?
    (4 pts)

a. input
b. output
c. forward
d. bidirectional
e. random access

a.
*/

/* -----------------------------------------------------------------------
 4. What is the STRONGEST iterator that the container std::set can provide?
    std::set is a red-black binary search tree.
    (4 pts)

a. input
b. output
c. forward
d. bidirectional
e. random access

d.
*/
