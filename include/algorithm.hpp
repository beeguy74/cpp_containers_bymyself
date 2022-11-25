/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <tphung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:39:18 by tphung            #+#    #+#             */
/*   Updated: 2022/11/25 13:39:21 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _ALGORITHM_H_
# define _ALGORITHM_H_

# include <memory>
# include "utility.hpp"

namespace out_ft {
    //TODO:max, min
    template<class InIt1, class InIt2> inline
    ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X){
        for(; F != L && *F == *X; ++F, ++X)
            ;
        return (ft::pair<InIt1, InIt2>(F, X));
    }
    template<class InIt1, class InIt2, class Pr> inline
    ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P){
        for (; F !=L && P(*F, *X); ++F, ++X)
            ;
        return (ft::pair<InIt1, InIt2>(F, X));
    }

} /* namespace out_ft */

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
    template<class InIt1, class InIt2> inline
    bool equal(InIt1 F, InIt1 L, InIt2 X){
        return (out_ft::mismatch(F, L, X).first == L);
    }
    template<class InIt1, class InIt2, class Pr> inline
    bool equal(InIt1 F, InIt1 L, InIt2 X, Pr P){
        return (out_ft::mismatch(F, L, X, P).first == L);
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
    template<class T> inline
    void swap(T& X, T& Y){
        T Tmp = X;
        X = Y, Y = Tmp;
    }
} /* namespace ft */


# endif  /* _ALGORITHM_H_ */