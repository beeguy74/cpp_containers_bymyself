#ifndef _STACK_H_
#define _STACK_H_

# include <vector>
namespace ft
{
    template <class T, class Container = std::vector<T> >
    class stack {
    protected:
        Container _cont;
    public:
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        // explicit make constructor closed to implicit conversions
        explicit stack(const container_type& cont = container_type()) : _cont(cont) {};
        bool empty() const { return _cont.empty(); };
        size_type size() const { return _cont.empty(); };
        value_type& top() { return _cont.back(); };
        const value_type& top() const { return _cont.back(); };
        void push(const value_type& x) { _cont.push_back(x); };
        void pop() { _cont.pop_back(); };
        ~stack(void) {};
        inline bool Eq(const stack<T, Container>& other) const { return (_cont == other._cont); };
        inline bool Lt(const stack<T, Container>& other) const { return (_cont < other._cont); };
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
