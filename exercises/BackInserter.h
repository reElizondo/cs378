// --------------
// BackInserter.h
// --------------

#ifndef BackInserter_h
#define BackInserter_h

template <typename C>
class my_back_insert_iterator {
    public:
        typedef std::output_iterator_tag iterator_category;
        typedef void                     value_type;
        typedef void                     difference_type;
        typedef void                     pointer;
        typedef void                     reference;

    private:
        C& _c;

    public:
        explicit my_back_insert_iterator (C& c) :
              _c (c)
            {}

        // Default copy, destructor, and copy assignment.
        // my_back_insert_iterator (const my_back_insert_iterator&);
        // ~my_back_insert_iterator ();
        // my_back_insert_iterator& operator = (const my_back_insert_iterator&);

        my_back_insert_iterator& operator = (typename C::const_reference v) {
            _c.push_back(v);
            return *this;}

        my_back_insert_iterator& operator * () {
            return *this;}

        my_back_insert_iterator& operator ++ () {
            return *this;}

        my_back_insert_iterator operator ++ (int) {
            return *this;}};

template <typename C>
my_back_insert_iterator<C> my_back_inserter (C& x) {
    return my_back_insert_iterator<C>(x);}

#endif // BackInserter_h
