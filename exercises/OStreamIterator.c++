// -------------------
// OStreamIterator.c++
// -------------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl, ostream
#include <iterator>  // iterator, ostream_iterator, output_iterator_tag
#include <sstream>   // ostringstream
#include <vector>    // vector

template <typename T, typename C = char>
class my_ostream_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void> {
    public:
/*
        typedef std::output_iterator_tag iterator_category;
        typedef void                     value_type;
        typedef void                     difference_type;
        typedef void                     pointer;
        typedef void                     reference;
*/

    private:
              std::ostream& _o;
        const C*            _d;

    public:
        my_ostream_iterator (std::ostream& o, const C* d = 0) :
                _o (o),
                _d (d)
            {}

        // Default copy, destructor, and copy assignment.
        // my_ostream_iterator (const my_ostream_iterator&);
        // ~my_ostream_iterator ();
        // my_ostream_iterator& operator = (const my_ostream_iterator&);

        my_ostream_iterator& operator = (const T& v) {
            _o << v;
            if (_d)
                _o << _d;
            return *this;}

        my_ostream_iterator& operator * () {
            return *this;}

        my_ostream_iterator& operator ++ () {
            return *this;}

        my_ostream_iterator operator ++ (int) {
            return *this;}};

int main () {
    using namespace std;
    cout << "OStreamIterator.c++." << endl;

    vector<int> x = {2, 3, 4};

    {
    ostringstream out;
    copy(x.begin(), x.end(), my_ostream_iterator<int>(out, " "));
    assert(out.str() == "2 3 4 ");
    }

    {
    ostringstream out;
    copy(x.begin(), x.end(), ostream_iterator<int>(out, " "));
    assert(out.str() == "2 3 4 ");
    }

    cout << "Done." << endl;
    return 0;}
