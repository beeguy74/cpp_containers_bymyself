#ifndef _VECTOR_H_
#define _VECTOR_H_

# include <memory>
# include <iostream>
# include "iterators.hpp"
# include "iterator_traits.hpp"

namespace ft
{
    template<class T, class A>
    class Vector_val {
        protected:
        Vector_val(A Al = A()) : Alval(Al) {}
        typedef typename A::template rebind<T>::other Alty;
        Alty Alval;
    }

    template <class T, class Ax = allocator<T>>
    class vector : public Vector_val<T, AX> {
    public:
        typedef vector<T, Ax>               Myt;
        typedef Vector<T, Ax>               Mybase;
        typedef typename Mybase::Alty       A;
        typedef A                           allocator_type;
        typedef typename A::size_type       size_type;
        typedef typename A::difference_type difference_type;
        typedef typename A::pointer         Tptr;
        typedef typename A::const_pointer   Ctptr;
        typedef Tptr                        pointer;
        typedef Ctptr                       const_pointer;
        typedef typename A::reference       reference;
        typedef typename A::const_reference const_reference;
        typedef typename A::value_type      value_type;
        typedef Ptrit<value_type, difference_type, Tptr, reference,
            Tptr, reference>                iterator;
        typedef Ptrit<value_type, difference_type, Ctptr, const reference,
            Tptr, reference>                const_iterator;
        typedef reverse_iterator<iterator>  reverse_iterator;
        typedef reverse_iterator<const_iterator>    const_reverse_iterator;
        vector() : Mybase(){
            Buy(0);
        }
        explicit vector(const A& Al) : Mybase(Al){
            Buy(0);
        }
        explicit vector(size_type N) : Mybase(){
            if(Buy(N))
                Last = Ufill (First, N, T());
        }
        vector(size_type N, const T& V) : Mybase() {
            if (Buy(N))
                Last = Ufill(First, N, V);
        }
        vector(size_type N, const T& V, const A& Al) : Mybase(Al){
            if (Buy(N))
                Last = Ufill(First, N, V);
        }
        vector(const Myt &X) : Mybase(X.Alval){
            if (Buy(X.size()))
                Last = Ucopy(X.begin(), X.end(), First);//Utilyti Ucopy is needed
        }
        template<class It>
        vector(It F, It L) : Mybase(){
            Construct(F, L, Iter_cat(F));
        }
        template<class It>
        vector(It F, Itl, const A& Al) : Mybase() {
            Construct(F, L, Iter_cat(F));
        }
        template<class It>
        void Construct(It F, It L, Int_iterator_tag){
            size_type N = (size_type)F;
            if (Buy(N))
                Last = ufill(First, N, (T)L);
        }
        template<class It>
        void Construct(It F, It L, input_iterator_tag){
            Buy(0);
            insert(begin(), F, L);
        }
        ~vector (){
            Clear();//Utility Clear is needed
        }

    protected:
        pointer First, Last, End;
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
        pointer Ufill(pointer Q, size_type N, const T &X){
            pointer Qs = Q;
            try {
                for (; 0 < N; --N, ++Q){
                    Mybase::Alval.construct(Q,X);
                }
            } catch () {
                Destroy(Qs, Q);
                throw;
            }
            return (Q);
        }
    }
}

#endif