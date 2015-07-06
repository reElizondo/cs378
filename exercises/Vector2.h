// ---------
// Vector2.h
// ---------

#include <algorithm> // copy, fill, swap
#include <cstddef>   // size_t

template <typename T>
class my_vector {
    private:
        size_t _s;
        T*     _a;

    public:
        my_vector (size_t s = 0, const T& v = T()) :
                _s (s),
                _a (s == 0 ? 0 : new T[s]) {
            std::fill(begin(), end(), v);}

        my_vector (const my_vector& rhs) :
                _s (rhs._s),
                _a (new T[rhs._s]) {
            std::copy(rhs.begin(), rhs.end(), begin());}

        my_vector& operator = (my_vector rhs) {
            std::swap(_s, rhs._s);
            std::swap(_a, rhs._a);
            return *this;}

        ~my_vector () {
            delete [] _a;}

       T& operator [] (size_t i) {
            return _a[i];}

        const T& operator [] (size_t i) const {
            return const_cast<my_vector<T>*>(this)->operator[](i);}

        T* begin () {
            return _a;}

        const T* begin () const {
            return const_cast<my_vector<T>*>(this)->begin();}

        T* end () {
            return _a + _s;}

        const T* end () const {
            return const_cast<my_vector<T>*>(this)->end();}

        size_t size () const {
            return _s;}};
