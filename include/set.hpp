#ifndef _SET_H_
# define _SET_H_


# include "iterators.hpp"
# include "xtree.hpp"

namespace ft {
    template<class K, class Pr, class Ax, bool Mfl>
    class Tset_traits {
    public:
        typedef K   key_type;
        typedef K   value_type;
        typedef Pr  key_compare;
        typedef typename Ax::template rebind<value_type>::other     
                    allocator_type;
        typedef key_compare     value_compare;
        enum {Multi = Mfl};
        Tset_traits() : comp() {}
        Tset_traits(Pr Parg) : comp(Parg) {}
        struct Kfn {
            const K& operator()(const value_type& X) const {
                return (X);
            };
        };
        Pr  comp;
    };

    template<class K,
            class Pr = std::less<K>,
            class A = std::allocator<K> >
    class set : public ft::Tree<Tset_traits<K, Pr, A, false> > {

    }
}

#endif