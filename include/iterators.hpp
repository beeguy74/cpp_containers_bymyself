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

    inline Int_iterator_tag Iter_cat(bool){
        Int_iterator_tag    X;
        return (X);
    }
    
    inline Int_iterator_tag Iter_cat(char){
        Int_iterator_tag    X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(signed char){
        Int_iterator_tag    X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(unsigned char){
        Int_iterator_tag    X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(wchar_t){
        Int_iterator_tag    X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(short){
        Int_iterator_tag    X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(unsigned short){
        Int_iterator_tag    X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(int){
        Int_iterator_tag    X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(unsigned int){
        Int_iterator_tag    X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(long){
        Int_iterator_tag    X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(unsigned long){
        Int_iterator_tag    X;
        return (X);
    }

    template<class InIt> inline
        typename iterator_traits<InIt>::difference_type distance(InIt F, InIt L){
            typename iterator_traits<InIt>::difference_type N = 0;
            Distance2(F, L, N, Iter_cat(F));
            return (N);
        }
    
    template<class InIt, class D> inline
        void Distance(InIt F, InIt L, D &N){
            Distance2(F, L, N, Iter_cat(F));
        }

    template<class InIt, class D> inline
        void Distance2(InIt F, InIt L, D &N, input_iterator_tag){
            for (; F != L; ++F)
                ++N;
        }

    template<class InIt, class D> inline
        void Distance2(InIt F, InIt L, D &N, forward_iterator_tag){
            for (; F != L; ++F)
                ++N;
        }

    template<class InIt, class D> inline
        void Distance2(InIt F, InIt L, D &N, bidirectional_iterator_tag){
            for (; F != L; ++F)
                ++N;
        }

    template<class RanIt, class D> inline
        void Distance2(RanIt F, RanIt L, D &N, random_access_iterator_tag){
            N += L - F;
        }

    template<class T, class D, class Pt, class Rt, class Pt2, class Rt2>
        class Ptrit : public iterator<random_access_iterator_tag,
                T, D, Pt, Rt> {
        public:
            typedef Ptrit<T, D, Pt, Rt, Pt2, Rt2>   Myt;
            Ptrit() {}
            Ptrit(Pt P) : current(P) {}
            Ptrit(const Ptrit<T, D, Pt, Rt, Pt2, Rt2> &X) : current(X.base()) {}
            Pt  base() const{
                return (current);
            }
            Rt  operator*() const{
                return ((Rt)*current);
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
                return (!(*this == Y));
            }
            Myt& operator+=(D N){
                current += N;
                return (*this);
            }
            Myt operator+(D N) const {
                return (Myt (current + N));
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
            bool operator>(const Myt &Y) const{
                return (Y < *this);
            }
            bool operator<=(const Myt &Y)const{
                return (!(Y < *this));
            }
            bool operator>=(const Myt &Y) const{
                return (!(*this < Y));
            }
            D   operator-(const Myt& Y) const{
                return (current - Y.current);
            }
        protected:
            Pt current;
        };

    template<class T, class D, class Pt, class Rt, class Pt2, class Rt2> inline
    Ptrit<T, D, Pt, Rt, Pt2, Rt2> operator+(D N, const Ptrit<T, D, Pt, Rt, Pt2, Rt2> &Y){
        return (Y + N);
    }
}

#endif /* _ITERATOR_H_ */