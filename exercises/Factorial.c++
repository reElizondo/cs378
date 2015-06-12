// -------------
// Factorial.c++
// -------------

#include <cassert>  // assert
#include <ctime>    // clock, clock_t, CLOCKS_PER_SEC
#include <iomanip>  // setprecision, setw
#include <iostream> // cout, endl
#include <string>   // string

#include "Factorial.h"

template <typename F>
void test (F f, const std::string& s) {
    std::cout << s << std::endl;
    assert(f(0) ==   1);
    assert(f(1) ==   1);
    assert(f(2) ==   2);
    assert(f(3) ==   6);
    assert(f(4) ==  24);
    assert(f(5) == 120);

    const clock_t b = clock();
    for (int i = 0; i != 1000; ++i)
        f(12);
    const clock_t e = clock();
    std::cout << std::fixed << std::setprecision(3) << std::setw(5);
    std::cout << ((e - b) * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << std::endl;
    std::cout << std::endl;}

int main () {
    using namespace std;
    cout << "Factorial.c++" << endl << endl;

    test(factorial_recursion,      "factorial_recursion");
    test(factorial_tail_recursion, "factorial_tail_recursion");
    test(factorial_iteration,      "factorial_iteration");

    cout << "Done." << endl;
    return 0;}

/*
Factorial.c++

factorial_recursion
0.114 milliseconds

factorial_tail_recursion
0.154 milliseconds

factorial_iteration
0.059 milliseconds

Done.
*/
