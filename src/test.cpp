#include <iostream>
#include <string>
#include "stack.hpp"
#include <stack>

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test some_data" << std::endl;
		std::cerr << "Provide a some_data please" << std::endl;
		return 1;
	}
    std::string data = argv[1];
    ft::stack<char>     my_stack;
    ft::stack<char>      rhs;
    std::stack<char>    std_stack;
    for (unsigned long i=0; i < data.length(); ++i){
        my_stack.push(data[i]);
        rhs.push(data[i]);
        std_stack.push(data[i]);
    }
    std::cout << "Operator== test\n";
    using namespace ft;
    std::cout << "stacks are equal: " << ((my_stack == rhs) ? "true" : "false") << std::endl;
    rhs.push('!');
    std::cout << "stacks are different after push to right: " << ((my_stack != rhs) ? "true" : "false") << std::endl;
    std::cout << "left is less: " << ((my_stack < rhs) ? "true" : "false") << std::endl;
    std::cout << "right is bigger: " << ((rhs > my_stack) ? "true" : "false") << std::endl;
    std::cout << "left is bigger or equal: " << ((my_stack >= rhs) ? "true" : "false") << std::endl;
    std::cout << "right is less or equal: " << ((rhs <= my_stack) ? "true" : "false") << std::endl;
    std::cout << "My stack:\tStd stack:\n";
    while (!my_stack.empty()) {
        std::cout << "\t" << my_stack.top() << "\t\t" << std_stack.top() << std::endl;
        my_stack.pop();
        std_stack.pop();
    }
    return 0;
}

