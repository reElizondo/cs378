// -------
// Stack.h
// -------

// http://www.cplusplus.com/reference/stack/stack/

#ifndef Stack_h
#define Stack_h

#include <cassert> // assert
#include <utility> // !=, <=, >, >=

using namespace std::rel_ops;

template <typename T, typename C = std::deque<T>>
class my_stack {
    public:
        typedef C                                         container_type;

        typedef typename container_type::value_type       value_type;
        typedef typename container_type::size_type        size_type;

        typedef typename container_type::reference        reference;
        typedef typename container_type::const_reference  const_reference;

    public:
        friend bool operator == (const my_stack& lhs, const my_stack& rhs) {
            return lhs._c == rhs._c;}

        friend bool operator < (const my_stack& lhs, const my_stack& rhs) {
            return lhs._c < rhs._c;}

    private:
        container_type _c;

    public:
        explicit my_stack (const container_type& c = container_type()) :
                _c (c)
            {}

        // Default copy, destructor, and copy assignment.
        // my_stack (const my_stack&);
        // ~my_stack ();
        // my_stack& operator = (const my_stack&);

        bool empty () const {
            return _c.empty();}

        void pop () {
            _c.pop_back();}

        void push (const_reference v) {
            _c.push_back(v);}

        size_type size () const {
            return _c.size();}

        reference top () {
            return _c.back();}

        const_reference top () const {
            return _c.back();}};

#endif // Stack_h
