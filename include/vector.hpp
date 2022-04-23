#ifndef _VECTOR_H_
#define _VECTOR_H_

# include <memory>
# include <iostream>

namespace ft
{
    template<class T, class A = std::allocator<T> >
    class vector{
    public:
        typedef vector<T, A>                My_v;
        typedef size_t                      size_type;
        typedef A                           allocator_type;
        typedef typename A::ponter          Tptr;
        typedef typename A::const_pointer   Ctptr;
        typedef typename A::reference       reference;
        typedef typename A::const_reference const_reference;
        typedef typename A::value_type      value_type;
        // The container may have an internal need to allocate objects of a different type, 
        // and tempalte rebind<T>::other::difference_type holds allocator of that type 
        // https://eel.is/c++draft/allocator.requirements
        typedef typename A::template rebind<T>::other::difference_type
            difference_type;
        typedef Ptrit<value_type, difference_type, Tptr, reference, Tptr, reference>
            iterator;
        typedef Ptrit<value_type, difference_type, Ctptr, const_reference, Tptr, reference>
            const_iterator;


    };

    // template<class A>
    // class vector<bool>;
}

#endif