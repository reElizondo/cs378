// -------------------
// IStreamIterator.c++
// -------------------

#include <algorithm> // copy,
#include <cassert>   // assert
#include <iostream>  // cout, endl, istream
#include <iterator>  // input_iterator_tag, istream_iterator, iterator
#include <sstream>   // istringstream
#include <utility>   // !=
#include <vector>    // vector

using std::rel_ops::operator!=;

template <typename T>
class my_istream_iterator : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t , T*, T&> {
    public:
/*
        typedef std::input_iterator_tag iterator_category;
        typedef T                       value_type;
        typedef std::ptrdiff_t          difference_type;
        typedef T*                      pointer;
        typedef T&                      reference;
*/
        friend bool operator == (const my_istream_iterator& lhs, const my_istream_iterator& rhs) {
            return (lhs._is == rhs._is);}

    private:
        std::istream* _is;
        T             _v;

    public:
        my_istream_iterator () :
                _is (0),
                _v  ()
            {}

        my_istream_iterator (std::istream& is) :
                _is (&is),
                _v  () {
            ++*this;}

        // Default copy, destructor, and copy assignment.
        // my_istream_iterator (const my_istream_iterator&);
        // ~my_istream_iterator ();
        // my_istream_iterator& operator = (const my_istream_iterator&);

        const T& operator * () const {
            return _v;}

        my_istream_iterator& operator ++ () {
            if (_is && !(*_is >> _v))
                _is = 0;
            return *this;}

        my_istream_iterator operator ++ (int) {
            my_istream_iterator x = *this;
            ++*this;
            return x;}};

int main () {
    using namespace std;
    cout << "IStreamIterator.c++." << endl;

    {
    const string        s = "2 3 4";
          istringstream in(s);
          vector<int>   x = {5, 6, 7, 8, 9};
    copy(my_istream_iterator<int>(in), my_istream_iterator<int>(), x.begin());
    assert(x == vector<int>({2, 3, 4, 8, 9}));
    }

    {
    const string        s = "2 3 4";
          istringstream in(s);
          vector<int>   x = {5, 6, 7, 8, 9};
    copy(istream_iterator<int>(in), istream_iterator<int>(), x.begin());
    assert(x == vector<int>({2, 3, 4, 8, 9}));
    }

    {
    istringstream in("2 3 4");
//  vector<int> x(my_istream_iterator<int>(in),   my_istream_iterator<int>());
    vector<int> x((my_istream_iterator<int>(in)), my_istream_iterator<int>());
    assert(x == vector<int>({2, 3, 4}));
    }

    {
    istringstream in("2 3 4");
//  vector<int> x(istream_iterator<int>(in),   istream_iterator<int>());
    vector<int> x((istream_iterator<int>(in)), istream_iterator<int>());
    assert(x == vector<int>({2, 3, 4}));
    }

    {
    istringstream in("2 3 4");
    my_istream_iterator<int> b(in);
    my_istream_iterator<int> e;
    vector<int> x(b, e);
    assert(x == vector<int>({2, 3, 4}));
    }

    {
    istringstream in("2 3 4");
    istream_iterator<int> b(in);
    istream_iterator<int> e;
    vector<int> x(b, e);
    assert(x == vector<int>({2, 3, 4}));
    }

    cout << "Done." << endl;
    return 0;}
