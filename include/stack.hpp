#ifndef _STACK_H_
#define _STACK_H_

# include "vector.hpp"
namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack {
    protected:
        Container c;
    public:
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        // explicit make constructor closed to implicit conversions
        explicit stack(const Container& cont) : c(cont) {};
        stack() : c() {}
        bool empty() const { return c.empty(); };
        size_type size() const { return c.empty(); };
        value_type& top() { return c.back(); };
        const value_type& top() const { return c.back(); };
        void push(const value_type& x) { c.push_back(x); };
        void pop() { c.pop_back(); };
        ~stack(void) {};
        inline bool Eq(const stack<T, Container>& other) const { return (c == other.c); };
        inline bool Lt(const stack<T, Container>& other) const { return (c < other.c); };
    };

    template <class T, class Cont>
    bool operator==(const stack<T, Cont>& lhs, const stack<T, Cont>& rhs){
        return lhs.Eq(rhs);
    }
    template <class T, class Cont>
    bool operator!=(const stack<T, Cont>& lhs, const stack<T, Cont>& rhs){
        return !(lhs.Eq(rhs));
    }
    template <class T, class Cont>
    bool operator<(const stack<T, Cont>& lhs, const stack<T, Cont>& rhs){
        return (lhs.Lt(rhs));
    }
    template <class T, class Cont>
    bool operator>(const stack<T, Cont>& lhs, const stack<T, Cont>& rhs){
        return (rhs < lhs);
    }
    template <class T, class Cont>
    bool operator<=(const stack<T, Cont>& lhs, const stack<T, Cont>& rhs){
        return !(rhs < lhs);
    }
    template <class T, class Cont>
    bool operator>=(const stack<T, Cont>& lhs, const stack<T, Cont>& rhs){
        return !(lhs < rhs);
    }
}
    
#endif
