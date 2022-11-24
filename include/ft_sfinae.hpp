#ifndef _FT_SFINAE_H_
# define _FT_SFINAE_H_

namespace ft {
    template<bool, typename T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T>{
        typedef T   type;
    };

    template <class T, T val>
    struct integral_constant {
        static const T value = val;
        typedef T value_type;
        typedef integral_constant<T, val> type;
        operator T() {
            return val;
        }
    };

    template <class T> 
    struct is_integral : public integral_constant<bool, false>{
        static const bool value = false;
    };

    template<>
    struct is_integral<char> : public integral_constant<bool, true> {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned char> : public integral_constant<bool, true> {
        static const bool value = true;
    };

    template<>
    struct is_integral<wchar_t> : public integral_constant<bool, true> {
        static const bool value = true;
    };

    template<>
    struct is_integral<int> : public integral_constant<bool, true> {
        static const bool value = true;
    };

    template<>
    struct is_integral<short int> : public integral_constant<bool, true> {
        static const bool value = true;
    };

    template<>
    struct is_integral<long int> : public integral_constant<bool, true> {
        static const bool value = true;
    };

    template<>
    struct is_integral<long long int> : public integral_constant<bool, true> {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned short int> : public integral_constant<bool, true> {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned long int> : public integral_constant<bool, true> {
        static const bool value = true;
    };
}

#endif