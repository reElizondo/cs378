// -------------
// Coverage2.c++
// -------------

// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

int main () {
    using namespace std;
    cout << "Coverage2.c++" << endl;

    assert(cycle_length(1) == 1);
    assert(cycle_length(2) == 2);

    cout << "Done." << endl;
    return 0;}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Coverage1.c++ -o Coverage1 -lgtest -lgtest_main -pthread
Coverage2
Coverage2.c++
Done.



% gcov -b Coverage2.c++
File 'Coverage2.c++'
Lines executed:93.75% of 16
Branches executed:100.00% of 16
Taken at least once:56.25% of 16
Calls executed:63.64% of 11
Creating 'Coverage2.c++.gcov'
...



% cat Coverage2.c++.gcov
...
*/
