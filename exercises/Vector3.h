// ---------
// Vector3.h
// ---------

#include <algorithm> // equal, lexicographical_compare
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <memory>    // allocator
#include <stdexcept> // out_of_range
#include <utility>   // !=, <=, >, >=

#include "Memory.h"  // my_destroy, my_uninitialized_copy, my_uninitialized_fill

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
inline bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
inline bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
inline bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

} // rel_ops
} // std;
*/

using namespace std::rel_ops;

template <typename T, typename A = std::allocator<T> >
class my_vector {
    private:
        A                 _x;
        const std::size_t _s;
        T*    const       _a;

    public:
        explicit my_vector (std::size_t s = 0, const T& v = T(), const A& x = A()) :
                _x (x),
                _s (s),
                _a (_x.allocate(s)) {
            my_uninitialized_fill(_x, begin(), end(), v);}

        ~my_vector () {
            my_destroy(_x, begin(), end());
            _x.deallocate(begin(), _s);}

        T& operator [] (std::size_t i) {
            return _a[i];}

        const T& operator [] (std::size_t i) const {
            return (*const_cast<my_vector<T>*>(this))[i];}

        T& at (std::size_t i) {
            if (i >= size())
                throw std::out_of_range("my_vector::at index out of range");
            return (*this)[i];}

        const T& at (std::size_t i) const {
            return const_cast<my_vector<T>*>(this)->at(i);}

        T* begin () {
            return _a;}

        const T* begin () const {
            return const_cast<my_vector<T>*>(this)->begin();}

        T* end () {
            return _a + _s;}

        const T* end () const {
            return const_cast<my_vector<T>*>(this)->end();}

        std::size_t size () const {
            return _s;}};

template <typename T>
bool operator == (const my_vector<T>& lhs, const my_vector<T>& rhs) {
    return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());}

template <typename T>
bool operator < (const my_vector<T>& lhs, const my_vector<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}
