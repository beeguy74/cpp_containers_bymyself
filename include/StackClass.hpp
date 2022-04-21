#ifndef _STACK_H_
#define _STACK_H_

# include <vector>

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
    value_type& top() { return _cont.back() };
    const value_type& top() cosnt { return _cont.back() };
    void push(const value_type& x) { _cont.push_back(x); };
    void pop() { _cont.pop_back() };
    ~stack(void) {};
};
    
#endif
