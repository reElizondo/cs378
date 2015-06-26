// -------------
// Iterators.c++
// -------------

// http://www.cplusplus.com/reference/iterator/

#include <cassert>    // assert
#include <iostream>   // cout, endl

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

    cout << "Done." << endl;
    return 0;}
