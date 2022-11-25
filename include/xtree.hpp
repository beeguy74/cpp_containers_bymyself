/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <tphung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:48:10 by tphung            #+#    #+#             */
/*   Updated: 2022/11/25 13:57:23 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _XTREE_H_
# define _XTREE_H_

# include "iterators.hpp"
# include "algorithm.hpp"

namespace ft {
    template<class Tr>
    class Tree_nod : public Tr {
    protected:
        typedef typename Tr::allocator_type     allocator_type;
        typedef typename Tr::key_compare        key_compare;
        typedef typename Tr::value_type         value_type;
        typedef typename allocator_type::template 
            rebind<void>::other::pointer        Genptr;
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
    };//class Tree_nod

    template<class Tr>
    class Tree_ptr : public Tree_nod<Tr> {
    protected:
        typedef typename Tree_nod<Tr>::Node     Node;
        typedef typename Tr::allocator_type     allocator_type;
        typedef typename Tr::key_compare        key_compare;
        typedef typename allocator_type::template
            rebind<Node>::other::pointer        Nodeptr;
        Tree_ptr(const key_compare& Parg, allocator_type Al)
            : Tree_nod<Tr>(Parg, Al) , Alptr(Al) {}
        typename allocator_type::template
            rebind<Nodeptr>::other              Alptr;
    };//class Tree_ptr

    template<class Tr>
    class Tree_val : public Tree_ptr<Tr> {
    protected:
        typedef typename Tr::allocator_type     allocator_type;
        typedef typename Tr::key_compare        key_compare;
        Tree_val(const key_compare Parg, allocator_type Al)
            : Tree_ptr<Tr>(Parg, Al), Alval(Al) {}
        allocator_type  Alval;
    };//class Tree_val


    template<class Tr>
    class Tree;

    template<class Tr> inline
    void swap(Tree<Tr>& X, Tree<Tr>& Y){
        X.swap(Y);
    }

    template<class Tr>inline
    bool operator==(const Tree<Tr>& X, const Tree<Tr>& Y){
        return (X.size() == Y.size() && ft::equal(X.begin(), X.end(), Y.begin()));
    }

    template<class Tr> inline
    bool operator!=(const Tree<Tr>& X, const Tree<Tr>& Y){
        return (!(X == Y));
    }

    template<class Tr> inline
    bool operator<(const Tree<Tr>& X, const Tree<Tr>& Y){
        return (ft::lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end()));
    }

    template<class Tr> inline
    bool operator>(const Tree<Tr>& X, const Tree<Tr>& Y){
        return (Y < X);
    }

    template<class Tr> inline
    bool operator<=(const Tree<Tr>& X, const Tree<Tr>& Y){
        return (!(Y < X));
    }

    template<class Tr> inline
    bool operator>=(const Tree<Tr>& X, const Tree<Tr>& Y){
        return (!(X < Y));
    }

    template<class Tr>
    class Tree : public Tree_val<Tr> {
    public:
        typedef Tree<Tr>        Myt;
        typedef Tree_val<Tr>    Mybase;
        typedef typename Tr::key_type                   key_type;
        typedef typename Tr::key_compare                key_compare;
        typedef typename Tr::value_compare              value_compare;
        typedef typename Tr::value_type                 value_type;
        typedef typename Tr::allocator_type             allocator_type;
    protected:
        typedef typename Tree_nod<Tr>::Genptr           Genptr;
        typedef typename Tree_nod<Tr>::Node             Node;
        typedef typename Tr::Kfn                        Kfn;
        typedef typename allocator_type::template
            rebind<Node>::other::pointer                Nodeptr;
        typedef typename allocator_type::template
            rebind<Nodeptr>::other::reference           Nodepref;
        typedef typename allocator_type::template
            rebind<key_type>::other::const_reference    Keyref;
        typedef typename allocator_type::template
            rebind<char>::other::reference              Charref;
        typedef typename allocator_type::template
            rebind<value_type>::other::reference        Vref;
        enum Redbl {Red, Black};

        static Charref Color(Nodeptr P) {
            return ((Charref)(*P).Color);
        }
        static Charref Isnil(Nodeptr P) {
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
        static Nodepref Right(Nodeptr P){
            return ((Nodepref)(*P).Right);
        }
        static Vref Value(Nodeptr P){
            return ((Vref)(*P).Value);
        }
    public:
        typedef typename allocator_type::size_type      size_type;
        typedef typename allocator_type::difference_type
                                                        Dift;
        typedef Dift                                    difference_type;
        typedef typename allocator_type::template
            rebind<value_type>::other::pointer          Tptr;
        typedef typename allocator_type::template
            rebind<value_type>::other::const_pointer    Ctptr;
        typedef typename allocator_type::template
            rebind<value_type>::other::reference        Reft;
        typedef Tptr                                    pointer;
        typedef Ctptr                                   const_pointer;
        typedef Reft                                    reference;
        typedef typename allocator_type::template
            rebind<value_type>::other::const_reference  const_reference;

        template<class itTptr,class itReft, bool IsConst>
        class map_iterator : public Bidit<value_type, Dift, itTptr, itReft> {
        public:
            typedef Bidit<value_type, Dift, itTptr, itReft>     Mybase;
            typedef typename Mybase::iterator_category      iterator_category;
            typedef typename Mybase::difference_type        difference_type;
            typedef typename Mybase::pointer                pointer;
            typedef typename Mybase::reference              reference;
            map_iterator() : Ptr(0) {}
            map_iterator(Nodeptr P) : Ptr(P) {}
            map_iterator(const map_iterator& it) : Ptr(it.Ptr) {}
            template<class point, class refer, bool WasConst>
            map_iterator(const map_iterator<point, refer, WasConst> &it,
                        typename ft::enable_if<IsConst || !WasConst, bool>::type = 0)
                        : Ptr(it.base())
                {}
            Nodeptr base() const{
                return Ptr;
            }
            reference operator*() const{
                return (Value(Ptr));
            }
            itTptr operator->() const{
                return (&**this);
            }
            map_iterator& operator++(){
                Inc();
                return (*this);
            }
            map_iterator operator++(int){
                map_iterator Tmp = *this;
                ++*this;
                return (Tmp);
            }
            map_iterator& operator--(){
                Dec();
                return *this;
            }
            map_iterator operator--(int){
                map_iterator Tmp = *this;
                --*this;
                return (Tmp);
            }
            bool operator==(const map_iterator X) const {
                return (Ptr == X.Ptr);
            }
            bool operator!=(const map_iterator X) const {
                return (!(*this == X));
            }
            void Dec(){
                if (Isnil(Ptr))
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
                        Ptr = P;
                    Ptr = P;
                }
            }
            Nodeptr Mynode() const{
                return (Ptr);
            }
        protected:
            Nodeptr     Ptr;
        };//class map_iterator

        typedef map_iterator<Tptr, Reft, false>             iterator;
        typedef map_iterator<Ctptr, const_reference, true>  const_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
        typedef ft::pair<iterator, bool>                    Pairib;
        typedef ft::pair<iterator, iterator>                Pairii;
        typedef pair<const_iterator, const_iterator>        Paircc;

        explicit Tree(const key_compare& Parg, const allocator_type& Al)
            : Mybase(Parg, Al){
                Init();
        }
        Tree(const value_type *F, const value_type *L, const key_compare& Parg, 
            const allocator_type& Al) : Mybase(Parg, Al) {
            Init();
            insert(F, L);
        }
        Tree(const Myt& X) : Mybase(X.key_comp(), X.get_allocator()){
            Init();
            Copy(X);
        }
        ~Tree(){
            erase(begin(), end());
            Freenode(Head);
            Head = 0, Size = 0;
        }
        Myt&    operator=(const Myt& X){
            if (this != &X){
                erase(begin(), end());
                this->comp = X.comp;
                Copy(X);
            }
            return (*this);
        }
        iterator begin(){
            return(iterator(Lmost()));
        }
        const_iterator begin() const{
            return(const_iterator(Lmost()));
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
        const_reverse_iterator rbegin() const{
            return (const_reverse_iterator(end()));
        }
        reverse_iterator rend(){
            return (reverse_iterator(begin()));
        }
        const_reverse_iterator rend() const{
            return (const_reverse_iterator(begin()));
        }
        size_type size() const{
            return(Size);
        }
        size_type max_size() const{
            return (this->Alnod.max_size());
        }
        bool empty() const{
            return(size() == 0);
        }
        allocator_type get_allocator() const{
            return(this->Alnod);
        }
        key_compare key_comp() const{
            return (this->comp);
        }
        value_compare value_comp() const{
            return (value_compare(key_comp()));
        }
        Pairib insert(const value_type& V){
            Nodeptr X = Root();
            Nodeptr Y = Head;
            bool Addleft = true;
            while(!Isnil(X)){
                Y = X;
                Addleft = this->comp(Kfn()(V), Key(X));
                X = Addleft ? Left(X) : Right(X);
            }
            if (Tr::Multi)
                return (Pairib(Insert(Addleft, Y, V), true));
            else {
                iterator P = iterator(Y);
                if(!Addleft)
                    ;
                else if(P == begin())
                    return (Pairib(Insert(true, Y, V), true));
                else
                    --P;
                if (this->comp(Key(P.Mynode()), Kfn()(V)))
                    return(Pairib(Insert(Addleft, Y, V), true));
                else
                    return(Pairib(P,false));
            }
        }//function insert
        template<class itTptr,class itReft, bool IsConst>
        map_iterator<itTptr, itReft, IsConst>   insert(map_iterator<itTptr, itReft, IsConst> P, const value_type &V){
            if (size() == 0)
                return (Insert(true, Head, V));
            else if (P == begin()){
                if (this->comp(Kfn()(V), Key(P.Mynode())))
                    return (Insert(true, P.Mynode(), V));
            }
            else if (P == end()){
                if (this->comp(Key(Rmost()), Kfn()(V)))
                    return(Insert(false, Rmost(), V));
            }
            else {
                map_iterator<itTptr, itReft, IsConst> Pb = P;
                if (this->comp(Key((--Pb).Mynode()), Kfn()(V)) && this->comp(Kfn()(V), Key(P.Mynode()))){
                    if (Isnil(Right(Pb.Mynode())))
                        return(Insert(false, Pb.Mynode(), V));
                    else
                        return(Insert(true, P.Mynode(), V));
                }
            }
            return(insert(V).first);
        }//function insert
        template<class It>
        void insert(It F, It L, typename ft::enable_if<!is_integral<It>::value, bool>::type = 0){
            for (; F != L; ++F)
                insert(*F);
        }

        template<class itTptr,class itReft, bool IsConst>
        map_iterator<itTptr, itReft, IsConst>   erase(map_iterator<itTptr, itReft, IsConst> P){
            if (Isnil(P.Mynode()))
                throw std::out_of_range("tree iterator");
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
                    Lmost() = Min(X);
                if(Rmost() != Z)
                    ;
                else if (Isnil(Left(Z)))
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
                for (;X != Root() && Color(X) == Black; Xpar = Parent(X))
                    if (X == Left(Xpar)){
                        Nodeptr W = Right(Xpar);
                        if(Color(W) == Red){
                            Color(W) = Black;
                            Color(Xpar) = Red;
                            Lrotate(Xpar);
                            W = Right(Xpar);
                        }
                        if (Isnil(W))
                            X = Xpar;
                        else if (Color(Left(W)) == Black && Color(Right(W)) == Black){
                            Color(W) = Red;
                            X = Xpar;
                        }
                        else {
                            if (Color(Right(W)) == Black){
                                Color(Left(W)) = Black;
                                Color(W) = Red;
                                Rrotate(W);
                                W = Right(Xpar);
                            }
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
                            X = Xpar;
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
                Color(X) = Black;
            }
            Destval(&Value(Z));
            Freenode(Z);
            if(0 < Size)
                --Size;
            return (P);
        }//function erase

        template<class itTptr,class itReft, bool IsConst, class secPtr,class secReft, bool secConst>
        map_iterator<itTptr, itReft, IsConst>   erase(
                map_iterator<itTptr, itReft, IsConst> F,
                map_iterator<secPtr, secReft, secConst> L
            ){
            if (size() == 0 || F != begin() || L != end()){
                while (F != L)
                    erase(F++);
                return (F);
            }
            else {
                Erase(Root());
                Root() = Head, Size = 0;
                Lmost() = Head, Rmost() = Head;
                return (begin());
            }
        }
        size_type erase(const key_type& X){
            Pairii P = equal_range(X);
            size_type N = 0;
            Distance(P.first, P.second, N);
            erase(P.first, P.second);
            return (N);
        }
        void erase(const key_type *F, const key_type *L){
            while (F != L)
                erase(*F++);
        }
        void clear(){
            erase(begin(), end());
        }
        iterator find(const key_type& Kv){
            iterator P = lower_bound(Kv);
            return (P == end() || this->comp(Kv, Key(P.Mynode())) ? end() : P);
        }
        const_iterator find(const key_type& Kv) const{
            const_iterator P = lower_bound(Kv);
            return (P == end() || this->comp(Kv, Key(P.Mynode())) ? end() : P);
        }
        size_type count(const key_type& Kv) const{
            Paircc Ans = equal_range(Kv);
            size_type N = 0;
            Distance(Ans.first, Ans.second, N);
            return (N);
        }
        iterator lower_bound(const key_type&Kv){
            return (iterator(Lbound(Kv)));
        }
        const_iterator lower_bound(const key_type& Kv) const{
            return(const_iterator(Lbound(Kv)));
        }
        iterator upper_bound(const key_type& Kv) {
            return (iterator(Ubound(Kv)));
        }
        const_iterator upper_bound(const key_type&Kv) const{
            return (const_iterator(Ubound(Kv)));
        }
        Pairii equal_range(const key_type& Kv){
            return (Pairii(lower_bound(Kv), upper_bound(Kv)));
        }
        Paircc equal_range(const key_type& Kv) const{
            return (Paircc(lower_bound(Kv), upper_bound(Kv)));
        }
        void swap(Myt& X){
            if(get_allocator() == X.get_allocator()){
                ft::swap(this->comp, X.comp);
                ft::swap(Head, X.Head);
                ft::swap(Size, X.Size);
            }
            else {
                Myt Ts = *this;
                *this = X,
                X = Ts;
            }
        }
    protected:
        void Copy(const Myt& X){
            Root() = Copy(X.Root(), Head);
            Size = X.size();
            if (!Isnil(Root())){
                Lmost() = Min(Root());
                Rmost() = Max(Root());
            }
            else
                Lmost() = Head, Rmost() = Head;
        }
        Nodeptr Copy(Nodeptr X, Nodeptr P){
            Nodeptr R = Head;
            if (!Isnil(X)){
                Nodeptr Y = Buynode(P, Color(X));
                try{
                    Consval(&Value(Y), Value(X));
                }
                catch (...) {
                    Freenode(Y);
                    Erase(R);
                    throw;
                }
                Left(Y) = Head, Right(Y) = Head;
                if (Isnil(R))
                    R = Y;
                try {
                    Left(Y) = Copy(Left(X), Y);
                    Right(Y) = Copy(Right(X), Y);
                }
                catch (...) {
                    Erase(R);
                    throw;
                }
            }
            return (R);
        }//function Copy

        void Erase(Nodeptr X){
            for(Nodeptr Y = X; !Isnil(Y); X = Y){
                Erase(Right(Y));
                Y = Left(Y);
                Destval(&Value(X));
                Freenode(X);
            }
        }
        void Init(){
            Head = Buynode(0, Black);
            Isnil(Head) = true;
            Root() = Head;
            Lmost() = Head, Rmost() = Head;
            Size = 0;
        }
        iterator Insert(bool Addleft, Nodeptr Y, const value_type& V){
            if (max_size() - 1 <= Size)
                throw std::length_error("tree mao/set too long");
            Nodeptr Z = Buynode(Y, Red);
            Left(Z) = Head, Right(Z) = Head;
            try {
                Consval(&Value(Z), V);
            }
            catch(...) {
                Freenode(Z);
                throw;
            }
            ++Size;
            if (Y == Head){
                Root() = Z;
                Lmost() = Z, Rmost() = Z;
            }
            else if (Addleft){
                Left(Y) = Z;
                if (Y == Lmost())
                    Lmost() = Z;
            }
            else {
                Right(Y) = Z;
                if (Y == Rmost())
                    Rmost () = Z;
            }
            for (Nodeptr X = Z; Color(Parent(X)) == Red;){
                if (Parent(X) == Left(Parent(Parent(X)))){
                    Y = Right(Parent(Parent(X)));
                    if (Color(Y) == Red){
                        Color(Parent(X)) = Black;
                        Color(Y) = Black;
                        Color(Parent(Parent(X))) = Red;
                        X= Parent(Parent(X));
                    }
                    else {
                        if ( X == Right(Parent(X))){
                            X = Parent(X);
                            Lrotate(X);
                        }
                        Color(Parent(X)) = Black;
                        Color(Parent(Parent(X))) = Red;
                        Rrotate(Parent(Parent(X)));
                    }
                }
                else {
                    Y = Left(Parent(Parent(X)));
                    if (Color(Y) == Red){
                        Color(Parent(X)) = Black;
                        Color(Y) = Black;
                        Color(Parent(Parent(X))) = Red;
                        X = Parent(Parent(X));
                    }
                    else {
                        if (X == Left(Parent(X))) {
                            X = Parent(X);
                            Rrotate(X);
                        }
                        Color(Parent(X)) = Black;
                        Color(Parent(Parent(X))) = Red;
                        Lrotate(Parent(Parent(X)));
                    }
                }
            }
            Color(Root()) = Black;
            return (iterator(Z));
        }//function Insert

        Nodeptr Lbound(const key_type& Kv) const{
            Nodeptr X = Root();
            Nodeptr Y = Head;
            while (!(Isnil(X))){
                if (this->comp(Key(X), Kv))
                    X =Right(X);
                else
                    Y = X, X = Left(X);
            }
            return(Y);
        }
        Nodeptr& Lmost(){
            return (Left(Head));
        }
        Nodeptr& Lmost() const{
            return (Left(Head));
        }
        void Lrotate(Nodeptr X){
            Nodeptr Y = Right(X);
            Right(X) = Left(Y);
            if (!Isnil(Left(Y)))
                Parent(Left(Y)) = X;
            Parent(Y) = Parent(X);
            if (X == Root())
                Root() = Y;
            else if (X == Left(Parent(X)))
                Left(Parent(X)) = Y;
            else
                Right(Parent(X)) = Y;
            Left(Y) = X;
            Parent(X) = Y;
        }
        static Nodeptr Max(Nodeptr P){
            while (!Isnil(Right(P)))
                P = Right(P);
            return (P);
        }
        static Nodeptr Min(Nodeptr P){
            while (!Isnil(Left(P)))
                P = Left(P);
            return (P);
        }
        Nodeptr& Rmost(){
            return (Right(Head));
        }
        Nodeptr& Rmost() const{
            return (Right(Head));
        }
        Nodeptr& Root(){
            return (Parent(Head));
        }
        Nodeptr& Root() const {
            return (Parent(Head));
        }
        void Rrotate(Nodeptr X){
            Nodeptr Y = Left(X);
            Left(X) = Right(Y);
            if (!Isnil(Right(Y)))
                Parent(Right(Y)) = X;
            Parent(Y) = Parent(X);
            if (X == Root())
                Root() = Y;
            else if (X == Right(Parent(X)))
                Right(Parent(X)) = Y;
            else
                Left(Parent(X)) = Y;
            Right(Y) = X;
            Parent(X) = Y;
        }
        Nodeptr Ubound(const key_type& Kv) const{
            Nodeptr X = Root();
            Nodeptr Y = Head;
            while(!Isnil(X)){
                if (this->comp(Kv, Key(X)))
                    Y= X, X = Left(X);
                else
                    X = Right(X);
            }
            return (Y);
        }
        Nodeptr Buynode(Nodeptr Parg, char Carg){
            Nodeptr S = this->Alnod.allocate(1, (void *)0);
            this->Alptr.construct(&Left(S), 0);
            this->Alptr.construct(&Right(S), 0);
            this->Alptr.construct(&Parent(S), Parg);
            Color(S) = Carg;
            Isnil(S) = false;
            return (S);
        }
        void Consval(Tptr P, const value_type& V){
            this->Alval.construct(P, V);
        }
        void Destval(Tptr P){
            this->Alval.destroy(P);
        }
        void Freenode(Nodeptr S){
            this->Alptr.destroy(&Parent(S));
            this->Alptr.destroy(&Right(S));
            this->Alptr.destroy(&Left(S));
            this->Alnod.deallocate(S, 1);
        }

        Nodeptr Head;
        size_type Size;
    };//class tree
}//namespace ft

#endif /* _XTREE_H_ */