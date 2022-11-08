#ifndef _XTREE_H_
# define _XTREE_H_

namespace ft {
    template<class Tr>
    class Tree_nod : public Tr {
    protected:
        typedef typename Tr::alloctor_type  allocator_type;
        typedef typename Tr::key_compare    key_compare;
        typedef typename Tr::value_type     value_type;
        typedef typename allocator_type::template 
            rebind<void>::other::pointer    Genptr;
        struct          Node;
        friend struct   Node;
        struct Node {
            Genptr      Left, Parent, Right;
            value_type  Value;
            char        Color;
            char        Isnil;
        };
        Tree_nod(const key_compare& Parg, allocator_type Al)
            : Tr(Parg), Alnod(Al) {}
        typename allocator_type::template
            rebind<Node>::other     Alnod;
    };

    template<class Tr>
    class Tree_ptr : public Tree_nod<Tr> {
    protected:
        typedef typename Tree_nod<Tr>::Node     Node;
        typedef typename Tr::allocator_type     allocator_type;
        typedef typename Tr::key_compare        key_compare;
        typedef typename allocator_type::template
            rebind<Nodeptr>::other::pointer     Nodeptr;
        Tree_ptr(const key_compare& Parg, allocator_type Al)
            : Tree_nod<Tr>(Parg, Al) , Alptr(Al) {}
        typename allocator_type::template
            rebind<Nodeptr>::other              Alptr;
    };

    template<class Tr>
    class Tree_val : public Tree_ptr<Tr> {
    protected:
        typedef typename Tr::allocator_type     allocator_type;
        typedef typename Tr::key_compare        key_compare;
        Tree_val(const key_compare Parg, allocator_type Al)
            : Tree_ptr<Tr>(Parg, Al), Alval(Al) {}
        allocator_type  Alval;
    };

    template<Class Tr>
    class Tree : public Tree_val<Tr> {
    public:
        typedef Tree<Tr>        Myt;
        typedef Tree_val<Tr>    Mybase;
        typedef typename Tr::key_type       key_type;
        typedef typename Tr::key_compare    key_compare;
        typedef typename Tr::value_compare  value_compare;
        typedef typename Tr::value_type     value_type;
        typedef typename Tr::allocator_type allocator_type;
    protected:
        typedef typename Tree_nod<Tr>::Genptr   Genptr;
        typedef typename Tree_nod<Tr>::Node     Node;
        enum Redbl {Red, Black};
        typedef typename allocator_type::template
            rebind::<Node>::other::pointer      Nodeptr;
        typedef typename allocator_type::template
            rebind::<Nodeptr>::other::reference Nodepref;
        typedef typename allocator_type::template
            rebind::<key_type>::other::const_reference  Keyref;
        typedef typename allocator_type::template
            rebind::<char>::other::reference    Charref;
        typedef typename allocator_type::template
            rebind::<value_type>::other::reference  Vref

        static Charref Color(Nodeptr P) {
            return ((Charref)(*P).Color);
        }
        static CharrefIsnil(Nodeptr P) {
            return((Charref)(*P).Isnil);
        }
        static Keyref Key(Nodeptr P){
            return (Kfn()(Value(P)));
        }
        static Nodepref Left(Nodeptr P){
            return((Nodepref)(*P).Left);
        }
        static Nodepref Parent(Nodeptr P){
            return ((Nodepref)(*P).Parent);
        }
        static Nodepref Right(Nodeptr p){
            return ((Nodepref)(*P).Right);
        }
        static Vref Value(Nodeptr P){
            return ((Vref)(*P).Value);
        }
    public:
        typedef typename allocator_type::size_type  size_type;
        typedef typename allocator_type::difference_type    Dift;
        typedef Dift    difference_type;
        typedef typename allocator_type::template
            rebind::<value_type>::other::pointer        Tptr;
        typedef typename allocator_type::template
            rebind::<value_type>::other::const_pointer  Ctptr;
        typedef typename allocator_type::template
            rebind::<value_type>::other::reference      Reft;
        typedef Tptr    pointer;
        typedef Ctptr   const_pointer;
        typedef Reft    reference;
        typedef typename allocator_type::template
            rebind::<value_type>::other::const_reference    const_reference;       
    }

}

#endif /* _XTREE_H_ */