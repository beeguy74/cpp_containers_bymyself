#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "iterator_traits.hpp"

namespace ft {
    struct Int_iterator_tag {};

    template<class T, class D, class Pt, class Rt>
        struct Bidit : public iterator<bidirectional_iterator_tag,
            T, D, Pt, Rt> {};
    template<class T, class D, class Pt, class Rt>
        struct Ranit: public iterator<random_access_iterator_tag,
            T, D, Pt, Rt> {};
    struct Outit : public iterator<output_iterator_tag,
        void, void, void, void> {};
    
    template<class C, class T, class D, class Pt, class Rt> inline
        C Iter_cat(const iterator<C, T, D, Pt, Rt> &){
            C X;
            return (X);
        }
    template<class T> inline
        random_access_iterator_tag  Iter_cat(const T*){
            random_access_iterator_tag  X;
            return (X);
        }
    
    template<class T, class D, class Pt, class Rt, class Pt2, class Rt2>
        class Ptrit : public iterator<random_access_iterator_tag,
                T, D, Pt, Rt> {
            typedef Ptrit<T, D, Pt, Rt, Pt2, Rt2>   Myt;
            Ptrit() {}
            explicit Ptrit(Pt P) : current(P) {}
            Ptrit(const Ptrit<T, D, Pt, Rt, Pt2, Rt2> &X) : current(X.base()) {}
            Pt base() const{
                return (current);
            }
            Rt operator*() const{
                return (*current);
            }
        }
}

#endif /* _ITERATOR_H_ */