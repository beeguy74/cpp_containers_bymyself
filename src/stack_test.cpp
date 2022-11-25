/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <tphung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:14:38 by tphung            #+#    #+#             */
/*   Updated: 2022/11/25 18:25:16 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int compare_stacks(ft::stack<char> &my, std::stack<char> &st, std::string &name){
    if ( my.size() == st.size() && my.top() == st.top()){
        std::cout << OK << name << std::endl;
    }
    else {
        std::cout << KO << name << std::endl;
    }
    return 0;
}

void push_pop(ft::stack<char> &my, std::stack<char> &st, std::string &message){

	for (unsigned long int i = 0; i < message.length(); i++){
		my.push(message[i]);
		st.push(message[i]);
	}

    std::string as = "push";

    compare_stacks(my, st, as);

	for (unsigned long int i = 0; i < my.size() - 2; i++){
		my.pop();
		st.pop();
	}

    as = "pop";

    compare_stacks(my, st, as);

}

void relation_and_construct(ft::stack<char> &my, std::stack<char> &st, std::string &message){
    ft::stack<char> copy_my(my);
    std::stack<char> copy_st(st);

    std::string name = "equal";
    if ( (my == copy_my) && (st == copy_st) )
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;

	for (unsigned long int i = 0; i < message.length() - 2; i++){
		copy_my.push(message[i]);
		copy_st.push(message[i]);
	}

    name = "less";
    if ( (my < copy_my) && (st < copy_st) )
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;


	for (unsigned long int i = 0; i < message.length(); i++){
		my.push(message[i]);
		st.push(message[i]);
	}

    name = "greater";

    if ( (my > copy_my) && (st > copy_st) )
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;
}


void all_methods(ft::stack<char> &my){
    try
    {
        ft::stack<char> copy_my;
        my.empty();
        my.push('s');
        copy_my.push('f');
        my.push('s');
        my.pop();
        my.pop();
        my.size();
        my.top();
        std::cout << OK << "all stack methods" << std::endl;
    }
    catch(...)
    {
        std::cout << KO << "all stack methods" << std::endl;
    }
    
}

int stack_test(std::string &message){
    ft::stack<char> my;
    std::stack<char> st;
    std::cout << std::endl << STACK <<  std::endl;
    all_methods(my);
    push_pop(my, st, message);
    relation_and_construct(my, st, message);
    std::cout << END << std::endl;
    return 0;
}