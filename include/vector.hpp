#ifndef _VECTOR_H_
#define _VECTOR_H_

# include <memory>
# include <iostream>
# include "iterators.hpp"
# include "iterator_traits.hpp"

namespace ft
{
    template<class T, class A>
    class Vector_val {
        protected:
        Vector_val(A Al = A()) : Alval(Al) {}
        typedef typename A::template rebind<T>::other Alty;
        Alty Alval;
    };

    template < class T, class Ax = std::allocator<T> >
    class vector : public Vector_val<T, Ax> {
    public:
        typedef vector<T, Ax>               Myt;
        typedef Vector_val<T, Ax>           Mybase;
        typedef typename Mybase::Alty       A;
        typedef A                           allocator_type;
        typedef typename A::size_type       size_type;
        typedef typename A::difference_type difference_type;
        typedef typename A::pointer         Tptr;
        typedef typename A::const_pointer   Ctptr;
        typedef Tptr                        pointer;
        typedef Ctptr                       const_pointer;
        typedef typename A::reference       reference;
        typedef typename A::const_reference const_reference;
        typedef typename A::value_type      value_type;
        typedef Ptrit<value_type, difference_type, Tptr, reference,
            Tptr, reference>                iterator;
        typedef Ptrit<value_type, difference_type, Ctptr, const reference,
            Tptr, reference>                const_iterator;
        typedef ft::reverse_iterator<iterator>  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
        vector() : Mybase(){
            Buy(0);
        }
        explicit vector(const A& Al) : Mybase(Al){
            Buy(0);
        }
        explicit vector(size_type N) : Mybase(){
            if(Buy(N))
                Last = Ufill (First, N, T());
        }
        vector(size_type N, const T& V) : Mybase() {
            if (Buy(N))
                Last = Ufill(First, N, V);
        }
        vector(size_type N, const T& V, const A& Al) : Mybase(Al){
            if (Buy(N))
                Last = Ufill(First, N, V);
        }
        vector(const Myt &X) : Mybase(X.Alval){
            if (Buy(X.size()))
                Last = Ucopy(X.begin(), X.end(), First);
        }
        template<class It>
        vector(It F, It L) : Mybase(){
            Construct(F, L, Iter_cat(F));
        }
        template<class It>
        vector(It F, It L, const A& Al) : Mybase(Al) {
            Construct(F, L, Iter_cat(F));
        }
        template<class It>
        void Construct(It F, It L, Int_iterator_tag){
            size_type N = (size_type)F;
            if (Buy(N))
                Last = ufill(First, N, (T)L);
        }
        template<class It>
        void Construct(It F, It L, input_iterator_tag){
            Buy(0);
            insert(begin(), F, L);
        }
        ~vector (){
            Clear();//Todo: Clear
        }
        Myt&    operator=(const Myt& X){
            if (this == &X)
                ;
            else if (X.size() == 0){
                Clear();
            }
            else if (X.size() <= size()){
                pointer Q = copy(X.begin(), X.end(), First);
                Destroy(Q, Last);
                Last = First + X.size();
            }
            else if (X.size() <= capacity()){
                const_iterator S = X.begin() + size();
                copy(X.begin(), S, First);
                Last = Ucopy(S, X.end(), Last);
            }
            else {
                Destroy(First, Last);
                Mybase::Alval.deallocate(First, End - First);
                if (Buy(X.size()))
                    Last = Ucopy(X.begin(), X.end(), First);
            return (*this);
            }
        }
        void reserve(size_type N){
            if (max_size() < N)
                Xlen(); //TODO Xlen
            else if(capacity() < N){
                pointer Q= Mybase::Alval.allocate(N, (void*)0);
                try {
                    Ucopy(begin(), end(), Q);
                }
                catch (...) {
                    Mybase::Alval.deallocate(Q, N);
                    throw;
                }
                if (First != 0){
                    Destroy(First, Last);
                    Mybase::Alval.deallocate(First, End - First);
                }
            }
        }
        size_type   capacity() const{
            return (First == 0 ? 0 : End - First);
        }
        iterator    begin(){
            return (iterator(First));
        }
        const_iterator  begin() const {
            return (const_iterator(First));
        }
        iterator    end(){
            return (iterator(Last));
        }
        const_iterator  end() const {
            return (const_iterator(Last));
        }
        reverse_iterator    rbegin(){
            return (reverse_iterator(end()));
        }
        const_reverse_iterator  rbegin() const{
            return (const_reverse_iterator(end()));
        }
        reverse_iterator    rend(){
            return (reverse_iterator(begin()));
        }
        const_reverse_iterator  rend() const{
            return (const_reverse_iterator(begin()));
        }
        void    resize(size_type N){
            resize(N, T());
        }
        void    resize(size_type N, T X){
            if (size() < N)
                insert (end(), N - size(), X);
            else if (N < size())
                erase (begin() + N, end());
        }
        size_type   size() const {
            return (First == 0? 0 : Last - First);
        }
        size_type   max_size() const {
            return (Mybase::Alval.max_size());
        }
        bool    empty() const{
            return (size() == 0);
        }
        A   get_allocator() const {
            return (Mybase::Alval);
        }
        const_reference at(size_type P) const{
            if (size() <= P)
                Xran();
            return (*(begin() + P));
        }
        reference   at(size_type P){
            if(size() <=P)
                Xran();
            return (*(begin() + P));
        }
        const_reference operator[](size_type P) const{
            return (*(begin() + P));
        }
        reference operator[](size_type P){
            return (*(begin() + P));
        }
        reference front(){
            return (*begin());
        }
        const_reference front() const{
            return (*begin());
        }
        reference   back(){
            return (*(end() - 1));
        }
        const_reference back() const{
            return (*(end() - 1));
        }
        void    push_back(const T& X){
            insert(end(), X);
        }
        void    pop_back(){
            erase(end() - 1);
        }
        template<class It>
        void    assign(It F, It L){
            Assign(F, L, Iter_cat(F));
        }
        template<class It>
        void    Assign(It F, It L, Int_iterator_tag){
            assign((size_type)F, (T)L);
        }
        template<class It>
        void    Assign(It F, It L, input_iterator_tag){
            erase (begin(), end());
            insert (begin(), F, L);
        }
        void    assign(size_type N, const T& X){
            T   Tx = X;
            erase(begin(), end());
            insert(begin(), N, Tx);
        }
        iterator insert(iterator P, const T& X){
            size_type   Off = size() == 0 ? 0 : P - begin();
            insert(P, (size_type)1, X);
            return (begin() + Off);
        }
        void insert(iterator P,size_type M, const T& X){
            T   Tx = X;
            size_type   N = capacity();
            if (M == 0)
                ;
            else if (max_size() - size() < M)
                Xlen();
            else if (N < size() + M){
                N = max_size() - N / 2 < N
                ? 0
                : N + N / 2;
                if (N < size() + M){
                    N = size() + M;
                }
                pointer S = Mybase::Alval.allocate(N, (void *)0);
                pointer Q;
                try {
                    Q = Ucopy (begin(), P, S);
                    Q = Ufill(Q, M, Tx);
                    Ucopy(P, end(), Q);
                }
                catch (...) {
                    Destroy(S, Q);
                    Mybase::Alval.deallocate(S, N);
                    throw;
                }
                if (First != 0){
                    Destroy(First, Last);
                    Mybase::Alval.deallocate(First, End - First);
                }
                End = S + N;
                Last = S + size() + M;
                First = S;
            }
            else if ((size_type)(end() - P) < M){
                Ucopy(P, end(), P.base() + M);
                try {
                    Ufill(Last, M - (end() - P), Tx);
                }
                catch(...) {
                    Destroy(P.base() + M, Last + M);
                    throw;
                }
                Last += M;
                fill(P, end() - M, Tx);
            }
            else {
                iterator Oend = end();
                Last = Ucopy(Oend - M, Oend, Last);
                copy_backward(P, Oend - M, Oend);
                fill(P, P + M, Tx);
            }
        }
        template<class It>
        void    insert(iterator P, It F, It L){
            Insert(P, F, L, Iter_cat(F));
        }
        template<class It>
        void    Insert(iterator P, It F, It L, Int_iterator_tag){
            insert(P, (size_type)F, (T)L);
        }
        template<class It>
        void    Insert(iterator P, It F, It L, input_iterator_tag){
            for (; F != L; ++F, ++P)
                P = insert (P, *F);
        }
        template<class It>
        void    Insert(iterator P, It F, It L, forward_iterator_tag){
            size_type   M = 0;
            Distance(F, L, M);//TODO: Distance
            size_type N = capacity();
            if (M == 0)
                ;
            else if (max_size() - size() < M)
                Xlen();
            else if( N < size() + M){
                N = max_size() - N / 2 < N
                ? 0
                : N + N / 2;
                if (N < size() + M)
                    N = size() + M;
                pointer S = Mybase::Alval.allocate(N, (void *)0);
                pointer Q;
                try {
                    Q = Ucopy(begin(), P, S);
                    Q = Ucopy(F, L, Q);
                    Ucopy(P, end(), Q);
                }
                catch (...){
                    Destroy(S, Q);
                    Mybase::Alval.deallocate(S, N);
                    throw;
                }
                if (First != 0){
                    Destroy(First, Last);
                    Mybase::Alval.deallocate(First, End - First);
                }
                End = S + N;
                Last = S + size() + M;
                First = S;
            }
            else if ((size_type)(end() - P) < M)
            {
                Ucopy(P, end(), P.base() + M);
                It Mid = F;
                advance(Mid, end() - P);
                try {
                    Ucopy(Mid, L, Last);
                }
                catch (...) {
                    Destroy (P.base() + M, Last + M);
                    throw;
                }
                Last += M;
                copy(F, Mid, P);
            }
            else if (0 < M){
                iterator Oend = end();
                Last = Ucopy(Oend - M, Oend, Last);
                copy_backward(P, Oend - M, Oend);
                copy(F, L, P);
            }
        }
        iterator    erase(iterator P){
            copy(P + 1, end(), P);
            Destroy(Last - 1, Last);
            --Last;
            return (P);
        }
        iterator    erase(iterator F, iterator L){
            if (F != L){
                pointer S = copy(L, end(), F.base());
                Destroy(S, Last);
                Last = S;
            }
            return (F);
        }
        void    clear(){
            erase(begin(), end());
        }
        bool    Eq(const Myt& X) const {
            return (size() == X.size() && equal(begin(), end(), X.begin()));
        }
        bool    Lt(const Myt& X) const {
            return (lexicographical_compare(begin(), end(), X.begin(), X.end()));
        }
        void    swap(Myt& X){
            if (Mybase::Alval == X.Alval){
                std::swap(First, X.First); //TODO: swap
                std::swap(Last, X.Last);
                std::swap(End, X.End);
            }
            else {
                Myt Ts = *this;
                *this = X;
                X = Ts;
            }
        }


    protected:
        pointer First, Last, End;
        allocator_type  Alval;
        bool    Buy(size_type N){
            First = 0, Last = 0, End = 0;
            if (N == 0)
                return(0);
            else {
                First = Mybase::Alval.allocate(N, (void *)0);
                Last = First;
                End = First + N;
                return (1);
            }
        }
        void    Clear(){
            if(First != 0){
                Destroy(First, Last);
                Mybase::Alval.deallocate(First, End - First);
            }
            First = 0, Last = 0, End = 0;
        }
        void    Destroy(pointer F, pointer L){
            for (; F != L; ++F){
                Mybase::Alval.destroy(F);
            }
        }
        template<class It>
        pointer Ucopy(It F, It L, pointer Q){
            pointer Qs = Q;
            try {
                for (; F !=L; ++Q, ++F)
                    Mybase::Alval.construct(Q, *F);
            }
            catch (...){
                Destroy(Qs, Q);
                throw;
            }
            return (Q);
        }
        pointer Ufill(pointer Q, size_type N, const T &X){
            pointer Qs = Q;
            try {
                for (; 0 < N; --N, ++Q){
                    Mybase::Alval.construct(Q,X);
                }
            } catch (...) {
                Destroy(Qs, Q);
                throw;
            }
            return (Q);
        }
        void Xlen() const{
            throw std::length_error("vector<T> too long, Sempai!");
        }
        void Xran() const{
            throw std::out_of_range("vector<T> subscript");
        }
    };

    template<class T, class A> inline
    bool    operator==(const vector<T, A>& X, const vector<T, A>& Y){
        return (X.Eq(Y));
    }
    template<class T, class A> inline
    bool    operator!=(const vector<T, A>& X, const vector<T, A>& Y){
        return (!(X == Y));
    }
    template<class T, class A> inline
    bool    operator<(const vector<T, A>& X, const vector<T, A>& Y){
        return (X.Lt(Y));
    }
    template<class T, class A> inline
    bool    operator>(const vector<T, A>& X, const vector<T, A>& Y){
        return (Y < X);
    }
    template<class T, class A> inline
    bool    operator<=(const vector<T, A>& X, const vector<T, A>& Y){
        return (!(Y < X));
    }
    template<class T, class A> inline
    bool    operator>=(const vector<T, A>& X, const vector<T, A>& Y){
        return (!(X < Y));
    }
    template<class T, class A> inline
    void    swap(vector<T, A>& X, vector<T, A>& Y){
        X.swap(Y);
    }
}

#endif