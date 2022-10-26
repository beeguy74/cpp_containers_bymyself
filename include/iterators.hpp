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
    
    template<class InIt> inline
        typename iterator_traits<InIt>::difference_type distance(InIt F, InIt L){
            typename iterator_traits<InIt>::difference_type N = 0;
            Distance2(F, L, N, Iter_cat(F));
            return (N)
        }
    
    template<class InIt, class D> inline
        void Distance(InIt F, InIt L, D &N){
            Distance2(F, L, N, Iter_cat(F));
        }

    template<class RanIt, class D> inline
        void Distance2(RanIt F, RanIt L, D &N, random_access_iterator_tag){
            N += L - F
        }

    //Distance2 for input_iterator_tag, forward_iterator_tag, bidirectional_iterator_tag

    template<class T, class D, class Pt, class Rt, class Pt2, class Rt2>
        class Ptrit : public iterator<random_access_iterator_tag,
                T, D, Pt, Rt> {
            typedef Ptrit<T, D, Pt, Rt, Pt2, Rt2>   Myt;
            Ptrit() {}
            explicit Ptrit(Pt P) : current(P) {}
            Ptrit(const Ptrit<T, D, Pt, Rt, Pt2, Rt2> &X) : current(X.base()) {}
            Pt  base() const{
                return (current);
            }
            Rt  operator*() const{
                return (*current);
            }
            Pt  operator->() const{
                return (&**this);
            }
            Myt &operator++(){
                ++current;
                return (*this);
            }
            Myt operator++(int){
                Myt tmp = *this;

                ++current;
                return (tmp);
            }
            Myt &operator--(){
                --current;
                return (*this);
            }
            Myt operator--(int){
                Myt tmp = *this;

                --current;
                return (tmp);
            }
            bool operator==(int Y) const {
                return (current == (Pt)Y);
            }
            bool operator==(const Myt& Y) const {
                return (current == Y.current);
            }
            bool operator!=(const Myt& Y) const {
                return (!(*this == Y))l
            }
            Myt& operator+=(D N){
                current += N;
                return (*this);
            }
            Myt operator+(D N) const {
                return (yt (current + N));
            }
            Myt &operator-=(D N) {
                current -= N;
                return (*this);
            }
            Myt operator-(D N) const {
                return (Myt(current - N));
            }
            Myt operator[](D N) const {
                return (*(*this + N));
            }
            bool operator<(const Myt &Y) const{
                return (current < Y.current);
            }
        }
}

#endif /* _ITERATOR_H_ */