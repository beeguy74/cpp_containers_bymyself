#ifndef _ITERATOR_TRAITS_H_
#define _ITERATOR_TRAITS_H_

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
        typedef typename It:value_type          value_type;
        typedef typename It:distance_type       distance_type;
        typedef typename It::pointer            pointer;
        typedef typename It::reference          reference;
    };

    template<class T>
    struct iterator_traits<T *> {
        typedef typename ft::random_access_iterator_tag iterator_category;
        typedef T                                       value_type;
        typedef typename std::ptrdiff_t                 distance_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
    };


    template<class T>
    struct iterator_traits<const T *> {
        typedef typename ft::random_access_iterator_tag iterator_category;
        typedef T                                       value_type;
        typedef typename std::ptrdiff_t                 distance_type;
        typedef const T*                                pointer;
        typedef const T&                                reference;
    };
}





#endif