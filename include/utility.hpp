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
                    !(Y.first < X.first) && X.second < Y.second);
            }
        template<class T1, class T2> inline
            bool    operator>(const pair<T1,T2> &X, const pair<T1, T2> &Y){
                return (Y < X);
            }
    };
} /* namespace ft */

#endif