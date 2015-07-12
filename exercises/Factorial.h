// -----------
// Factorial.h
// -----------

#ifndef Factorial_h
#define Factorial_h

#include <cassert> // assert

// recursive procedure
// linear recursive process
int factorial_recursion (int n) {
    assert(n >= 0);
    if (n < 2)
        return 1;
    return n * factorial_recursion(n - 1);}

int factorial_tail_recursion_aux (int n, int m) {
    assert(n >= 0);
    assert(m >= 1);
    if (n < 2)
        return m;
    return factorial_tail_recursion_aux(n - 1, n * m);}

// recursive procedure
// linear iterative process
int factorial_tail_recursion (int n) {
    assert(n >= 0);
    return factorial_tail_recursion_aux(n, 1);}

// iterative procedure
// linear iterative process
int factorial_iteration (int n) {
    assert(n >= 0);
    int x = 1;
    while (n > 1) {
        x *= n;
        --n;}
    return x;}

#endif // Factorial_h
