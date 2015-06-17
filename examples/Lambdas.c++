// -----------
// Lambdas.c++
// -----------

// http://en.cppreference.com/w/cpp/utility/functional/function
// http://en.cppreference.com/w/cpp/language/lambda

#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl

int add (int i, int j) {
    return i + j;}

typedef std::function<int (int, int)> BF;

int f (BF bf, int i, int j, int k) {
    return bf(bf(i, j), k);}

BF g () {
    return [] (int i, int j) -> int {return i + j;};}

typedef std::function<int (int)> UF;

UF h (int i) {
    return [i] (int j) -> int {return i + j;};}

int main () {
    using namespace std;
    cout << "Lambdas.c++" << endl;

    {
    BF   x = add;
    auto y = add;

    assert(add(2, 3) == 5);
    assert(x  (2, 3) == 5);
    assert(y  (2, 3) == 5);

    assert(f(add, 2, 3, 4) == 9);
    assert(f(x,   2, 3, 4) == 9);
    assert(f(y,   2, 3, 4) == 9);
    }

    {
    BF   x = [] (int i, int j) -> int {return i + j;};
    auto y = [] (int i, int j) -> int {return i + j;};

    assert([] (int i, int j) -> int {return i + j;}(2, 3) == 5);
    assert(x                                       (2, 3) == 5);
    assert(y                                       (2, 3) == 5);

    assert(f([] (int i, int j) -> int {return i + j;}, 2, 3, 4) == 9);
    assert(f(x,                                        2, 3, 4) == 9);
    assert(f(y,                                        2, 3, 4) == 9);
    }

    {
    BF   x = g();
    auto y = g();

    assert(g()(2, 3) == 5);
    assert(x  (2, 3) == 5);
    assert(y  (2, 3) == 5);

    assert(f(g(), 2, 3, 4) == 9);
    assert(f(x,   2, 3, 4) == 9);
    assert(f(y,   2, 3, 4) == 9);
    }

    {
    const int i = 2;
    UF   x = [i] (int j) -> int {return i + j;};
    auto y = [i] (int j) -> int {return i + j;};

    assert([i] (int j) -> int {return i + j;}(3) == 5);
    assert(x                                 (3) == 5);
    assert(y                                 (3) == 5);
    }

    {
    UF   x = h(2);
    auto y = h(2);

    assert(h(2)(3) == 5);
    assert(x   (3) == 5);
    assert(y   (3) == 5);
    }

    cout << "Done." << endl;
    return 0;}
