#ifndef _ITERATOR_TRAITS_H_
#define _ITERATOR_TRAITS_H_

namespace ft
{
    class input_iterator_tag {};
    class output_iterator_tag {};
    class forward_iterator_tag : input_iterator_tag {};
    class bidirectional_iterator_tag : forward_iterator_tag {};
    class random_access_iterator_tag : bidirectional_iterator_tag {};

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
        typedef typename T                              value_type;
        typedef typename std::ptrdiff_t                 distance_type;
        typedef typename T*                             pointer;
        typedef typename T&                             reference;
    };


    template<class T>
    struct iterator_traits<T *> {
        typedef typename ft::random_access_iterator_tag iterator_category;
        typedef typename T                              value_type;
        typedef typename std::ptrdiff_t                 distance_type;
        typedef typename const T*                       pointer;
        typedef typename const T&                       reference;
    }
}



#endif