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
    public:
        typedef set<K, Pr, A>   Myt;
        typedef ft::Tree<Tset_traits<K, Pr, A, false> >     Mybase;
        typedef K   key_type;
        typedef Pr  key_compare;
        typedef typename Mybase::value_compare  value_compare;
        typedef typename Mybase::allocator_type allocator_type;
        typedef typenae Mybase::size_type       size_type;
        typedef typename Mybase::difference_type    difference_type;
        typedef typename Mybase::pointer        pointer;
        typedef typename Mybase::const_pointer  const_pointer;
        typedef typename Mybase::reference      reference;
        typedef typename Mybase::const_reference    const_reference;
        typedef typename Mybase::iterator       iterator;
        typedef typename Mybase::const_iterator const_iterator;
        typedef typename Mybase::reverse_iterator   reverse_iterator;
        typedef typename Mybase::const_reverse_iterator const_reverse_iterator;
        typedef typename Mybase::value_type     value_type;

        set() : Mybase(key_compare(), allocator_type()) {}
        explicit set(const key_compare& Pred) : Mybase(Pred, allocator_type()) {}
        set(const key_compare& Pred, const allocator_type& Al) : Mybase(Pred, Al) {}
        template<class It>
        set(It F, It L) : Mybase(key_compare(), allocator_type()){
            for (; F != L; ++F)
                insert (*F);
        }
        template<class It>
        set(it F, It L, const key_compare& Pred): Mybase(Pred, allocator_type()){
            for (; F != L; ++F)
                insert (*F);
        }
        template<class It>
        set(it F, It L, const key_compare& Pred, const allocator_type& Al) 
            : Mybase(Pred, Al){
            for (; F != L; ++F)
                insert (*F);
        }

    }
}

#endif