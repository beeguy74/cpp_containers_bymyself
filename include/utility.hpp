#ifndef _UTILITY_H_
#define _UTILITY_H_

namespace ft
{
    template<class T1, class T2>
    struct pair {
        typedef T1  first_type;
        typedef T2  second_type;
        T1          first;
        T2          second;
        pair() : first(T1()), second(T2()) {}
        pair(const T1 &V1, const T2 &V2) : first(V1), second(V2) {}
        template<class U1, class U2>
            pair(const pair<U1, U2> &X) : first(X.first), second(X.second) {}
    };

    template<class T1, class T2> inline 
        bool    operator==(const pair<T1,T2> &X, const pair<T1, T2> &Y){
            return (X.first == Y.first && X.econd == Y.second);
        }
    template<class T1, class T2> inline
        bool    operator!=(const pair<T1,T2> &X, const pair<T1, T2> &Y){
            return (!(X == Y));
        }
    template<class T1, class T2> inline
        bool    operator<(const pair<T1,T2> &X, const pair<T1, T2> &Y){
            return (X.first < Y.first || 
                (!(Y.first < X.first) && X.second < Y.second));
        }
    template<class T1, class T2> inline
        bool    operator>(const pair<T1,T2> &X, const pair<T1, T2> &Y){
            return (Y < X);
        }
    template<class T1, class T2> inline
        bool    operator<=(const pair<T1,T2> &X, const pair<T1, T2> &Y){
            return (!(Y < X));
        }
    template<class T1, class T2> inline
        bool    operator>=(const pair<T1,T2> &X, const pair<T1, T2> &Y){
            return (!(X < Y));
        }
    template<class T1, class T2> inline
        pair<T1, T2>    make_pair(const T1 &X, const T2 &Y){
            return (pair<T1, T2>(X, Y));
        }

    template<class InIt, class D> inline
    void    advance(InIt& I, D N){
        Advance(I, N, Iter_cat(I));
    }
    template<class InIt, class D> inline
    void    Advance(InIt& I, D N, input_iterator_tag){
        for (; 0 < N; --N)
            ++I;
    }
    template<class FwdIt, class D> inline
    void    Advance(FwdIt& I, D N, forward_iterator_tag){
        for (; 0 < N; --N)
            ++I;
    }
    template<class BidIt, class D> inline
    void    Advance(BidIt& I, D N, bidirectional_iterator_tag){
        for (; 0 < N; --N)
            ++I;
        for (; N > 0; ++N)
            --I;
    }
    template<class RanIt, class D> inline
    void Advance(RanIt& I, D N, random_access_iterator_tag)
        {I += N;}
} /* namespace ft */

#endif /* _UTILITY_H_ */