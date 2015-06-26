// -------------
// Iterators.c++
// -------------

// http://www.cplusplus.com/reference/iterator/

#include <algorithm> // copy, equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <vector>    // vector

class A {
    public:
        class B {
            private:
                int _i;

            public:
                B (int i) {
                    _i = i;}

                bool operator == (const B& rhs) {
                    return _i == rhs._i;}

                bool operator != (const B& rhs) {
                    return _i != rhs._i;}

                int operator * () {
                    return _i;}

                B& operator ++ () {
                    ++_i;
                    return *this;}};

        B begin () {
            return B(2);}

        B end () {
            return B(5);}};

int main () {
    using namespace std;
    cout << "Iterators.c++" << endl;

    {
    A x;
    A::B b = x.begin();
    A::B e = x.end();
    assert(*b == 2);
    ++b;
    assert(*b == 3);
    ++b;
    assert(*b == 4);
    ++b;
    assert(b == e);
    }

    {
    A x;
    vector<int> y(3);
    copy(x.begin(), x.end(), y.begin());
    vector<int> z = {2, 3, 4};
    assert(equal(y.begin(), y.end(), z.begin()));
    }

    cout << "Done." << endl;
    return 0;}
