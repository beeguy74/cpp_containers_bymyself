#ifndef _ALGORITHM_H_
# define _ALGORITHM_H_

# include <memory>
# include "utility.hpp"

namespace ft {
    template    <class InIt, class OutIt> inline
    OutIt   copy(InIt F, InIt L, OutIt X){
        for (; F != L; ++X, ++F)
            *X = *F;
        return (X);
    }
    template<class BidIt1, class BidIt2> inline
    BidIt2 copy_backward(BidIt1 F, BidIt1 L, BidIt2 X){
        while (F != L)
            *--X = *--L;
        return (X);
    }
    // template<class InIt1, class InIt2> inline
    // bool equal(InIt1 F, InIt1 L, InIt2 X){
    //     return (mismatch(F, L, X).first == L);  //TODO: mismatch
    // }
    template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1++ != *first2++)
				return false;
		}
		return true;
	}
    template<class InIt1, class InIt2, class Pr> inline
    bool equal(InIt1 F, InIt1 L, InIt2 X, Pr P){
        return (mismatch(F, L, X, P).first == L);
    }
    template<class FwdIt, class T> inline
    void fill(FwdIt F, FwdIt L, const T& X){
        for (; F != L; ++F)
            *F = X;
    }
    template<class OutIt, class Sz, class T> inline
    void fill_n(OutIt F, Sz N, const T& X){
        for (; 0 < N; -- N, ++F)
            *F = X;
    }
    template<class InIt1, class InIt2> inline
    bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2){
        for (; F1 != L1 && F2 != L2; ++F1, ++F2)
        {
            if (*F1 < *F2)
               return (true);
            else if (*F2 < *F1)
                return (false);
        }
        return (F1 == L1 && F2 != L2);
    }
    template<class InIt1, class InIt2, class Pr> inline
    bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2, Pr P){
        for (; F1 != L1 && F2 != L2; ++F1, ++F2){
            if (P(*F1, *F2))
                return (true);
            else if (P(*F2, *F1))
                return (false);
        }
        return (F1 == L1 && F2 != L2);
    }
    //TODO:max, min
    template<class InIt1, class InIt2> inline
    pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X){
        for(; F != L && *F == *X; ++F, ++X)
            ;
        return (pair<InIt1, InIt2>(F, X));
    }
    template<class InIt1, class InIt2, class Pr> inline
    pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P){
        for (; F !=L && P(*F, *X); ++F, ++X)
            ;
        return (pair<InIt1, InIt2>(F, X));
    }
    template<class T> inline
    void swap(T& X, T& Y){
        T Tmp = X;
        X = Y, Y = Tmp;
    }

} /* namespace ft */

# endif  /* _ALGORITHM_H_ */