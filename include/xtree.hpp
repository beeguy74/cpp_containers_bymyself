#ifndef _XTREE_H_
# define _XTREE_H_

# include "iterators.hpp"

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

        class iterator;
        friend class iterator;
        class iterator : public Bidit<value_type, Dift, Tptr, Reft> {
        public:
            typedef Bidit<value_type, Dift, Tptr, Reft>     Mybase;
            typedef typename Mybase::iterator_categoty      iterator_category;
            typedef typename Mybase::value_type             value_type;
            typedef typename Mybase::difference_type        difference_type;
            typedef typename Mybase::pointer                pointer;
            typedef typename Mybase::reference              reference;
            iterator() : Ptr(0) {}
            iterator() : Ptr(P) {}
            reference operator*() const{
                return (Value(Ptr));
            }
            Tptr operator->() const{
                return (&**this);
            }
            iterator operator++(){
                Inc();//TODO:Inc
                return (*this);
            }
            iterator operator++(int){
                iterator Tmp = *this;
                ++*this;
                return (Tp);
            }
            iterator operator--(){
                Dec();
                return (*this);
            }
            iterator operator--(int){
                iterator Tmp = *this;
                --*this;
                return (Tmp);
            }
            bool operator==(const iterator X) const {
                return (Ptr == X.Ptr);
            }
            bool operator!=(const iterator X) const {
                return (!(*this == X));
            }
            void Dec(){
                if (Isnil(Ptr))
                    Ptr = Right(Ptr);
                else if (!Isnil(Left(Ptr)))
                    ptr = Max(Left(Ptr)); //TODO: Max
                else {
                    Nodeptr P;
                    while (!Isnil(P = Parent(Ptr)) && Ptr == Left(P))
                        Ptr = P;
                    if (!Isnil(P))
                        Ptr = P;
                }
            }
            void Inc(){
                if (Isnil(Ptr))
                    ;
                else if (!Isnil(Right(Ptr)))
                    Ptr = Min(Right(Ptr));//TODO: Min
                else {
                    Nodeptr P;
                    while (!Isnil(P = Parent(Ptr)) && Ptr == Right(P))
                        Ptr = P;
                    Ptr = P;
                }
            }
            Nodeptr Mynode() const{
                return (Ptr);
            }
        protected:
            Nodeptr     Ptr;
        };

        class const_iterator;
        friend class const_iterator;
        class const_iterator : public Bidit<value_type, Dift, Ctptr, const_reference> {
        public:
            typedef Bidit<value_type, Dift, Ctptr, const_reference>     Mybase;
            typedef typename Mybase::iterator_category      iterator_category;
            typedef typename Mybase::value_type             value_type;
            typedef typename Mybase::difference_type        difference_type;
            typedef typename Mybase::pointer                pointer;
            typedef typename Mybase::reference              reference;
            const_iterator() : Ptr(0) {}
            const_iterator(Nodeptr P) : Ptr(P) {}
            const_iterator(const typename Tree<Tr>::iterator X) : Ptr(X.Mynode()) {}
            const_reference operator*() const {
                return (Value(Ptr));
            }
            Ctptr operator->() const {
                return(&**this);
            }
            const_iterator& operator++(){ //Mistake?
                Inc();
                return (*this);
            }
            const_iterator operator++(int){
                const_iterator Tmp = *this;
                ++*this;
                return (Tmp);
            }
            const_iterator& operator--(){
                Dec();
                return (*this);
            }
            const_iterator operator--(int){
                const_iterator Tmp = *this;
                --*this;
                return (Tmp);
            }
            bool operator==(const const_iterator& X) const{
                return (Ptr == X.Ptr);
            }
            bool operator!=(const const_iterator& X) const{
                return (!(*this == X));
            }
            void Dec(){
                if(Isnil(Ptr))
                    Ptr = Right(Ptr);
                else if (!Isnil(Left(Ptr)))
                    Ptr = Max(Left(Ptr));
                else {
                    Nodeptr P;
                    while (!Isnil(P = Parent(Ptr)) && Ptr == Left(P))
                        Ptr = P;
                    if (!Isnil(P))
                        Ptr = P;
                }
            }
            void Inc(){
                if (Isnil(Ptr))
                    ;
                else if (!Isnil(Right(Ptr)))
                    Ptr = Min(Right(Ptr));
                else {
                    Nodeptr P;
                    while (!Isnil(P = Parent(Ptr)) && Ptr == Right(P))
                        Ptr = p;
                    Ptr = P;
                }
            }
            Nodeptr Mynode() const{
                return (Ptr);
            }
        protected:
            Nodeptr Ptr;
        };

        typedef ft::reverse_iterator<iterator>
            reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>
            const_reverse_iterator;
        typedef ft::pair<iterator, bool>        Pairib;
        typedef ft::pair<iterator, iterator>    Pairii;
        typedef pair<const_iteratpr, const_iterator> Paircc;

        explicit Tree(const key_compare& Parg, const allocator_type& Al)
            : Mybase(Parg, AL){
                Init();//TODO:Init
            }
        Tree(const value_type *F, const value_type *L, const key_compare& Parg, 
            const allocator_type& Al) : Mybase(Parg, Al) {
            Init();
            insert(F, L); //TODO: insert
        }
        ~Tree(){
            erase(begin(), end());
            Freenode(Head);
            Head = 0, Size = 0;
        }
        Myt&    operator=(const Myt& X){
            if (this != &X){
                erase(begin(), end());
                comp = X.comp;
                Copy(X);
            }
            return (*this);
        }
        iterator begin(){
            return(iterator(Lmose()));
        }
        const_iterator begin() const{
            return(const_iterator(Lmose()));
        }
        iterator end(){
            return (iterator(Head));
        }
        const_iterator end() const{
            return (const_iterator(Head));
        }
        reverse_iterator rbegin(){
            return (reverse_iterator(end()));
        }
        const_reverse_iterator rend() const{
            return (const_reverse_iterator(begin()));
        }
        size_type size() const{
            return(Size);
        }
        size_type max_size() const{
            return (Alval.max_size());
        }
        bool empty() const{
            return(size() == 0);
        }
        allocator_type get_allocator() const{
            return(Alval);
        }
        key_compare key_comp() const{//some shit
            return (comp):
        }
        value_compare value_comp() const{//some shit
            return (value_compare(key_comp()));
        }
        Pairib insert(const value_type& V){
            Nodeptr X = Root();
            Nodeptr Y = Head;
            bool Addleft = true;
            while(!Isnil(X)){
                Y = X;
                Addleft = comp(Kfn()(V), Key(x));//TODO:Kfn
                X = Addleft ? Left(X) : Right(X);
            }
            if (Multi)
                return (Pairlib(Insert(Addleft, Y, V), true));
            else {
                iterator P = iterator(Y);
                if(Addleft)
                    ;
                else if(P == begin())
                    return (Pairib(Insert(true, Y, V), true));
                else
                    --P;
                if (comp(Key(P.Mynode()), Kfn()(V)))
                    return(Pairib(Insert(Addleft, Y, V), true));
                else
                    return(Pairib(P,false));
            }
        }
        iterator insert(iterator P, const value_type& V){
            if (size() == 0)
                return (Insert(true, Head, V));
            else if (P == begin()){
                if (comp(KFN()(V), Key(P.Mynode())))
                    return (Insert(true, P.Mynode(), V))
            }
            else {
                iterator Pb = P;
                if (comp(Key((--Pb)P.Mynode(), Kfn()(V)))) //shit?
                    && comp(Kfn()(V), Key(P.Mynode())){
                    if (Isnil(Right(Pb.Mynode())))
                        return(Insert(true, P.Mynode(), V))
                    else
                        return(Insert(true, P.Mynode(), V))
                }
                return(insert(V).first);
            }
        }
        template<class It>
        void insert(It F, It L){
            for (; F != L; ++F)
                insert(*F);
        }
        iterator erase(iterator P){
            if (Isnil(P.Mynode()))
                throw out_of_range("tree iterator");
            Nodeptr X, Xpar;
            Nodeptr Y = (P++).Mynode();
            Nodeptr Z = Y;
            if (Isnil(Left(Y)))
                X = Right(Y);
            else if (Isnil(Right(Y)))
                X = Left(Y);
            else
                Y = Min(Right(Y)), X = Right(Y);
            if (Y == Z){
                Xpar = Parent(Z);
                if (!Isnil(X))
                    Parent(X) = Xpar;
                if (Root() == Z)
                    Root() = X;
                else if(Left(Xpar) == Z)
                    Left(Xpar) = X;
                else
                    Right(Xpar) = X;
                if (Lmost() != Z)
                    ;
                else if (Isnil(Right(Z)))
                    Lmost() = Xpar;
                else
                    Lmost() = Mix(X);
                if(Rmost() != Z)
                    ;
                else if (Isnil(left(Z)))
                    Rmost() = Xpar;
                else
                    Rmost() = Max(X);
            }
            else {
                Parent(Left(Z)) = Y;
                Left(Y) = Left(Z);
                if(Y == Right(Z))
                    Xpar = Y;
                else{
                    Xpar = Parent(Y);
                    if (!Isnil(X))
                        Parent(X) = Xpar;
                    Left(Xpar) = X;
                    Right(Y) = Right(Z);
                    Parent(Right(Z)) = Y;
                }
                if (Root() == Z)
                    Root() = Y;
                else if(Left(Parent(Z)) == Z)
                    Left(Parent(Z)) = Y;
                else
                    Right(Parent(Z)) = Y;
                Parent(Y) = Parent(Z);
                ft::swap(Color(Y), Color(Z));
            }
            if (Color(Z) == Black){
                for (;X != Root() && Color(X) == Black; Xpar = Parent(X)){
                    if (X == Left(Xpar)){
                        Nodeptr W = Right(Xpar);
                        if(Color(W) == Red){
                            Color(W) == Black;
                            Color(Xpar) = Red;
                            Lrotate(Xpar);
                            W = Right(Xpar);
                        }
                        if (Isnil(W))
                            X = Xpar; //shit?
                        else if (Color(Left(W)) == Black && Color(Right(W)) == Black){
                            Color(w) = Red;
                            X = Xpar;
                        }
                        else {
                            if (Color(Right(W)) == Black){
                                Color(Left(W)) = Black;
                                Color(W) = Red;
                                Rrotate(W);
                                W = Right(Xpar);
                                Color(W) = Color(Xpar);
                                Color(Xpar) = Black;
                                Color(Right(W)) = Black;
                                Lrotate(Xpar);
                                break;
                            }
                        }
                        else {
                            Nodeptr W = Left(Xpar);
                            if(Color(W) == Red){
                                Color(W) = Black;
                                Color(Xpar) = Red;
                                Rrotate(Xpar);
                                W = Left(Xpar);
                            }
                            if (Isnil(W))
                                X = Xpar; //shit
                            else if(Color(Right(W)) == Black && Color(Left(W)) == Black){
                                Color(W) = Red;
                                X = Xpar;
                            }
                            else {
                                if(Color(Left(W)) == Black){
                                    Color(Right(W)) = Black;
                                    Color(W) = Red;
                                    Lrotate(W);
                                    W = Left(Xpar);
                                }
                                Color(W) = Color(Xpar);
                                Color(Xpar) = Black;
                                Color(Left(W)) = Black;
                                Rrotate(Xpar);
                                break;
                            }
                        }
                    }
                }
                Color(X) = Black;
            }
            Destval(&Value(Z));
            Freenode(Z);
            if(0 < Size)
                --Size;
            return (P);
        }//shit
}

#endif /* _XTREE_H_ */