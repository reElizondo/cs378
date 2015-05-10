// -------------
// Coverage1.c++
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
    cout << "Coverage1.c++" << endl;

    assert(cycle_length(1) == 1);

    cout << "Done." << endl;
    return 0;}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Coverage1.c++ -o Coverage1 -lgtest -lgtest_main -pthread
Coverage1
Coverage1.c++
Done.



% gcov -b Coverage1.c++
File 'Coverage1.c++'
Lines executed:73.33% of 15
Branches executed:85.71% of 14
Taken at least once:42.86% of 14
Calls executed:66.67% of 9
Creating 'Coverage1.c++.gcov'
...



% cat Coverage1.c++.gcov
...
*/
