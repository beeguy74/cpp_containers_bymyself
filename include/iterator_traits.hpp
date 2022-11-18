#ifndef _ITERATOR_TRAITS_H_
#define _ITERATOR_TRAITS_H_

# include <iostream>

namespace ft
{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : input_iterator_tag {};
    struct bidirectional_iterator_tag : forward_iterator_tag {};
    struct random_access_iterator_tag : bidirectional_iterator_tag {};

    template<class It>
    struct iterator_traits {
        typedef typename It::iterator_category  iterator_category;
        typedef typename It::value_type         value_type;
        typedef typename It::difference_type    difference_type;
        typedef typename It::pointer            pointer;
        typedef typename It::reference          reference;
    };

    template<class T>
    struct iterator_traits<T *> {
        typedef typename ft::random_access_iterator_tag iterator_category;
        typedef T                                       value_type;
        typedef typename std::ptrdiff_t                 difference_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
    };

    template<class T>
    struct iterator_traits<const T *> {
        typedef typename ft::random_access_iterator_tag iterator_category;
        typedef T                                       value_type;
        typedef typename std::ptrdiff_t                 difference_type;
        typedef const T*                                pointer;
        typedef const T&                                reference;
    };

    template<class C, class T, class D = std::ptrdiff_t, class Pt = T*, class Rt = T&>
    struct iterator {
        typedef C       iterator_category;
        typedef T       value_type;
        typedef D       difference_type;
        typedef Pt      pointer;
        typedef Rt      reference;
    };

    template<class RanIt>
    class reverse_iterator: public iterator<
            typename iterator_traits<RanIt>::iterator_category,
            typename iterator_traits<RanIt>::value_type,
            typename iterator_traits<RanIt>::difference_type,
            typename iterator_traits<RanIt>::pointer,
            typename iterator_traits<RanIt>::reference> {
    public:
        typedef reverse_iterator<RanIt>                             Myt;
        typedef typename iterator_traits<RanIt>::difference_type    D;
        typedef typename iterator_traits<RanIt>::pointer            Ptr;
        typedef typename iterator_traits<RanIt>::reference          Ref;
        typedef RanIt iterator_type;
        reverse_iterator() : current(NULL) {};
        explicit reverse_iterator(RanIt x) : current(x) {};
        template<class U>
        reverse_iterator(const reverse_iterator<U> &x) : current(x.base()) {};
        ~reverse_iterator() {};
        RanIt   base() const {return current;};

        operator reverse_iterator<const RanIt>() const {
            return reverse_iterator<const RanIt>(this);
        }

        Ref                 operator*() const {
            RanIt   Tmp = current;
            return (*--Tmp);
        };
        Ptr                 operator->() const {
            return &(operator*());
        };
        Myt&    operator++() {
            --current;
            return *this;
        };
        Myt     operator++(int) {
            Myt tmp = *this;
            --current;
            return tmp;
        };
        Myt&    operator--() {
            ++current;
            return *this;
        };
        Myt    operator--(int) {
            Myt tmp = *this;
            ++current;
            return tmp;
        };
        Myt    operator+(D n) const {
            return Myt(current - n);
        };
        Myt    &operator+=(D n) {
            current -= n;
            return *this;
        };
        Myt operator-(D n) const {
            return Myt(current + n);
        };
        Myt&    operator-=(D n){
            current += n;
            return *this;
        };
        Ref operator[](D n) const {
            return current[-n-1];
        };
        bool Eq(const Myt& Y) const{
            return (current == Y.current);
        }
        bool Lt(const Myt& Y) const{
            return (Y.current < current);
        }
        D Mi(const Myt& Y) const{
            return (Y.current - current);
        }


        // Ptr                 operator->() const {
        //     return &**this;
        // };
        // Myt operator*(D N){
        //     current -= N;
        //     return *this;
        // }
        // template<class Num>
        // Myt		operator+(Num bias) const{return (Myt(current - bias));}
        // Ref operator[](D n) const {
        //     return *(*this + n);
        // };
		// Myt		operator-(D bias) {return current + bias;}
    protected:
        RanIt current;
    };

    template<class RanIt, class D> inline
    reverse_iterator<RanIt> operator*(D N, const reverse_iterator<RanIt>& Y){
        return (Y + N);
    }
    template<class RanIt> inline
    typename reverse_iterator<RanIt>::D operator-(const reverse_iterator<RanIt>& X,
            const reverse_iterator<RanIt>& Y){
        return (X.Mi(Y));
    }
    template <class IteratorLeft, class IteratorRight>
    typename reverse_iterator<IteratorLeft>::D operator-(
        const reverse_iterator<IteratorLeft>& lhs,
        const reverse_iterator<IteratorRight>& rhs)
    {
        return rhs.base() - lhs.base();
    }
    template <class Iterator>
    reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::D n,
        const reverse_iterator<Iterator>& lhs)
    {
        return reverse_iterator<Iterator> (lhs.base() - n);
    }
    template <class IteratorLeft, class IteratorRight>
    bool    operator==(
        const reverse_iterator<IteratorLeft> & lhs,
        const reverse_iterator<IteratorRight> & rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template<class RanIt> inline
    bool    operator==(const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt>& Y){
        return (X.Eq(Y));
    }
    template<class RanIt> inline
    bool    operator!=(const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt>& Y){
        return (!(X == Y));
    }
    template<class RanIt> inline
    bool    operator<(const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt>& Y){
        return (X.Lt(Y));
    }
    template<class RanIt> inline
    bool    operator>(const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt>& Y){
        return (Y < X);
    }
    template<class RanIt> inline
    bool    operator<=(const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt>& Y){
        return !(Y < X);
    }
    template<class RanIt> inline
    bool    operator>=(const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt>& Y){
        return !(X < Y);
    }

}





#endif