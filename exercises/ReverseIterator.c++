// -------------------
// ReverseIterator.c++
// -------------------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // iterator, iterator_traits, reverse_iterator
#include <string>    // string

template <typename II, typename OI>
OI my_copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

template <typename I>
class my_reverse_iterator {
    public:
        typedef typename std::iterator_traits<I>::iterator_category iterator_category;
        typedef typename std::iterator_traits<I>::value_type        value_type;
        typedef typename std::iterator_traits<I>::difference_type   difference_type;
        typedef typename std::iterator_traits<I>::pointer           pointer;
        typedef typename std::iterator_traits<I>::reference         reference;

    public:
        friend my_reverse_iterator operator + (my_reverse_iterator lhs, difference_type rhs) {
            return lhs += rhs;}

        friend my_reverse_iterator operator - (my_reverse_iterator lhs, difference_type rhs) {
            return lhs -= rhs;}

        friend difference_type operator - (const my_reverse_iterator& lhs, const my_reverse_iterator& rhs) {
            return rhs._p - lhs._p;}

        friend bool operator == (const my_reverse_iterator& lhs, const my_reverse_iterator& rhs) {
            return rhs._p == lhs._p;}

        friend bool operator != (const my_reverse_iterator& lhs, const my_reverse_iterator& rhs) {
            return rhs._p != lhs._p;}

        friend bool operator < (const my_reverse_iterator& lhs, const my_reverse_iterator& rhs) {
            return rhs._p < lhs._p;}

    private:
        I _p;

    public:
        explicit my_reverse_iterator (I p = I()) :
               _p (p)
            {}

        template <typename U>
        my_reverse_iterator (const my_reverse_iterator<U>& that) :
               _p (that.base())
            {}

        // Default copy, destructor, and copy assignment.
        // my_reverse_iterator (const my_reverse_iterator&);
        // ~my_reverse_iterator ();
        // my_reverse_iterator& operator = (const my_reverse_iterator&);

        reference operator * () const {
            I q = _p;
            return *--q;}

        pointer operator -> () const {
            return &**this;}

        reference operator [] (difference_type d) const {
            return *(*this + d);}

        my_reverse_iterator& operator ++ () {
            --_p;
            return *this;}

        my_reverse_iterator operator ++ (int) {
            my_reverse_iterator x = *this;
            ++(*this);
            return x;}

        my_reverse_iterator& operator -- () {
            ++_p;
            return *this;}

        my_reverse_iterator operator -- (int) {
            my_reverse_iterator x = *this;
            --(*this);
            return x;}

        my_reverse_iterator& operator += (difference_type d) {
            _p -= d;
            return *this;}

        my_reverse_iterator& operator -= (difference_type d) {
            _p += d;
            return *this;}

        I base () const {
            return _p;}};

int main () {
    using namespace std;
    cout << "ReverseIterator.c++" << endl;

    {
    const string s = "Cba";
          string t = "xxxbA";
    my_reverse_iterator<string::const_iterator> b(s.end());
    my_reverse_iterator<string::const_iterator> e(s.begin());
    my_copy(b, e, t.begin());
    assert(t == "abCbA");
    }

    {
    const string s = "Cba";
          string t = "xxxbA";
    my_reverse_iterator<string::const_iterator> b(s.end());
    my_reverse_iterator<string::const_iterator> e(s.begin());
    my_copy(b, e, t.begin());
    assert(t == "abCbA");
    }

    cout << "Done." << endl;
    return 0;}
