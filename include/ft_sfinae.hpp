#ifndef _FT_SFINAE_H_
# define _FT_SFINAE_H_

namespace ft {
    template<bool, typename T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T>{
        typedef T   type;
    };
}

#endif