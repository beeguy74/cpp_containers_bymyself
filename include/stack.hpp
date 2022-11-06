#ifndef _STACK_H_
#define _STACK_H_

# include "vector.hpp"
namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack {
    // protected:
    //     Container _cont;
    public:
        Container _cont;
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        // explicit make constructor closed to implicit conversions
        explicit stack(const Container& cont) : _cont(cont) {};
        stack() : _cont() {}
        bool empty() const { return _cont.empty(); };
        size_type size() const { return _cont.empty(); };
        value_type& top() { return _cont.back(); };
        const value_type& top() const { return _cont.back(); };
        void push(const value_type& x) { _cont.push_back(x); };
        void pop() { _cont.pop_back(); };
        ~stack(void) {};
        // Container   base() const{ return (this._cont); }
        inline bool Eq(const stack<T, Container>& other) const { return (_cont == other._cont); };
        inline bool Lt(const stack<T, Container>& other) const { return (_cont < other._cont); };
    };

    // template <class T, class Cont>
    // bool operator==(const stack<T, Cont>& lhs, const stack<T, Cont>& rhs){
    //     return lhs.Eq(rhs);
    // }
    template <class T, class Alloc>
	bool				operator==(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs._cont.begin(), lhs._cont.end(), rhs._cont.begin());
	};
    template <class T, class Alloc>
	bool				operator!=(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
	{
		return lhs.size() != rhs.size() || !ft::equal(lhs._cont.begin(), lhs._cont.end(), rhs._cont.begin());
	};
    // template <class T, class Cont>
    // bool operator!=(const stack<T, Cont>& lhs, const stack<T, Cont>& rhs){
    //     return !(lhs.Eq(rhs));
    // }
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
