#ifndef _VECTOR_H_
#define _VECTOR_H_

# include <memory>
# include <iostream>

namespace ft
{
    template <class T, class Ax = allocator<T>>
    class vector {
        typedef vector<T, Ax>   Myt;
        typedef typename Ax::template rebind<T>::other  A;
        typedef A   allocator_type;
        typedef typename A::size_type   size_type;
        typedef typename A::difference_type difference_type;
        typedef typename A::pointer         Tptr;
        typedef typename A::const_pointer   Ctptr;
        typedef Tptr                        pointer;
        typedef Ctptr                       const_pointer;
        typedef typename A::reference       reference;
        typedef typename A::const_reference const_reference;
        typedef typename A::value_type      value_type;

    protected:
        allocator_type  Alval;
        bool    Buy(size_type N){
            if (N == 0)
                return(0);
            else {
                First = Alval.allocate(N, (void *)0);
                Last = First;
                End = First + N;
                return (1);
            }
        }
    }
}

#endif