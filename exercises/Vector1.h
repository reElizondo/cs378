// ---------
// Vector1.h
// ---------

#include <algorithm> // fill
#include <cstddef>   // size_t

template <typename T>
class my_vector {
    private:
        const size_t       _s;
              T*     const _a;

    public:
        my_vector (size_t s = 0, const T& v = T()) :
                _s (s),
                _a (s == 0 ? 0 : new T[s]) {
            std::fill(begin(), end(), v);}

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
