#ifndef _ITERATOR_TRAITS_H_
#define _ITERATOR_TRAITS_H_

# include <iostream>

namespace ft
{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : input_iterator_tag {};
    struct bidirectional_iterator_tag : forward_iterator_tag {};
    struct random_access_iterator_tag : bidirectional_iterator_tag {};

    template<class It>
    struct iterator_traits {
        typedef typename It::iterator_category  iterator_category;
        typedef typename It::value_type          value_type;
        typedef typename It::difference_type       difference_type;
        typedef typename It::pointer            pointer;
        typedef typename It::reference          reference;
    };

    template<class T>
    struct iterator_traits<T *> {
        typedef typename ft::random_access_iterator_tag iterator_category;
        typedef T                                       value_type;
        typedef typename std::ptrdiff_t                 difference_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
    };

    template<class T>
    struct iterator_traits<const T *> {
        typedef typename ft::random_access_iterator_tag iterator_category;
        typedef T                                       value_type;
        typedef typename std::ptrdiff_t                 difference_type;
        typedef const T*                                pointer;
        typedef const T&                                reference;
    };

    template<class C, class T, class Dist = std::ptrdiff_t, class Pt = T*, class Rt = T&>
    struct iterator {
        typedef C       iterator_category;
        typedef T       value_type;
        typedef Dist    difference_type;
        typedef Pt      pointer;
        typedef Rt      reference;
    };

    template<class RanIt>
    class reverse_iterator: public iterator<
            typename iterator_traits<RanIt>::iterator_category,
            typename iterator_traits<RanIt>::value_type,
            typename iterator_traits<RanIt>::difference_type,
            typename iterator_traits<RanIt>::pointer,
            typename iterator_traits<RanIt>::reference> {
        typedef typename iterator_traits<RanIt>::difference_type    Dist;
        typedef typename iterator_traits<RanIt>::pointer            Ptr;
        typedef typename iterator_traits<RanIt>::reference          Ref;
    public:
        typedef RanIt iterator_type;
        reverse_iterator() : current(NULL) {};
        explicit reverse_iterator(RanIt x) : current(x) {};
        template<class U>
            reverse_iterator(const reverse_iterator<U> &x) : current(x.base()) {};
        ~reverse_iterator() {};
        RanIt   base() const {return current;};
        Ref                 operator*() const { return *(current); };
        Ptr                 operator->() const {return &**this;};
        reverse_iterator    &operator++() {
            --current;
            return *this;
        };
        reverse_iterator    operator++(int) {
            reverse_iterator<iterator_type> tmp(*this);
            --current;
            return tmp;
        };
        reverse_iterator    &operator--() {
            current++;
            return *this;
        };
        reverse_iterator    operator--(int) {
            reverse_iterator<iterator_type> tmp(*this);
            ++current;
            return tmp;
        };
        reverse_iterator    &operator+=(Dist n) {
            current -= n;
            return *this;
        };
        reverse_iterator    operator+(Dist n) const { return reverse_iterator(*this) += n; };
        reverse_iterator    &operator-=(Dist n){
            current += n;
            return *this;
        };
        reverse_iterator    operator-(Dist n) const { return reverse_iterator(*this) -= n; };
        Ref                 operator[](Dist n) const {return *(*this + n);};
    protected:
        RanIt current;
    };

}





#endif