/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <tphung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:14:38 by tphung            #+#    #+#             */
/*   Updated: 2022/11/25 17:49:55 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

    // std::cout << RED << "bold red text\n" << GREEN << message<<RESET <<std::endl;
int compare_vectors(ft::vector<char> &my, std::vector<char> &st, std::string &name){
    if (
            ! ft::lexicographical_compare(my.begin(), my.end(), st.begin(), st.end()) &&
            ! ft::lexicographical_compare(st.begin(), st.end(), my.begin(), my.end())
        ){
        std::cout << OK << name << std::endl;
    }
    else {
        std::cout << KO << name << std::endl;
    }
    return 0;
}

void assign(ft::vector<char> &my, std::vector<char> &st, std::string &message){
    my.assign(message.begin(), message.end());
    st.assign(message.begin(), message.end());

    std::string as = "assign by iterators";

    compare_vectors(my, st, as);

    st.clear();
    my.clear();

    my.assign(10, 42) ;
    st.assign(10, 42);

    as = "assign by values";
    
    compare_vectors(my, st, as);

    st.clear();
    my.clear();
    return ;
}

void vec_at(ft::vector<char> &my, std::vector<char> &st, std::string &message){
    my.resize(message.length());
    st.resize(message.length());

	for (unsigned long int i = 0; i < my.size(); i++){
		my.at(i) = message[i];
		st.at(i) = message[i];
	}

    std::string as = "at by values";

    compare_vectors(my, st, as);

    st.clear();
    my.clear();
}


void insert(ft::vector<char> &my, std::vector<char> &st, std::string &message){
    my.insert(my.begin(), message.begin(), message.end());
    st.insert(st.begin(), message.begin(), message.end());

    std::string as = "insert by iterators";

    compare_vectors(my, st, as);

    st.clear();
    my.clear();

    my.insert(my.begin(), 2, 'G');
    st.insert(st.begin(), 2, 'G');
    as = "insert by values";
    
    compare_vectors(my, st, as);

    st.clear();
    my.clear();
    
}

void push_pop(ft::vector<char> &my, std::vector<char> &st, std::string &message){

	for (unsigned long int i = 0; i < message.length(); i++){
		my.push_back(message[i]);
		st.push_back(message[i]);
	}

    std::string as = "push";

    compare_vectors(my, st, as);

	for (unsigned long int i = 0; i < my.size() - 2; i++){
		my.pop_back();
		st.pop_back();
	}

    as = "pop";

    compare_vectors(my, st, as);

    st.clear();
    my.clear();
}

void relation_and_construct(ft::vector<char> &my, std::vector<char> &st, std::string &message){
    my.assign(message.begin(), message.end());
    st.assign(message.begin(), message.end());
    ft::vector<char> copy_my(my);
    std::vector<char> copy_st(st);

    std::string name = "equal";
    if ( (my == copy_my) && (st == copy_st) )
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;

    copy_my.push_back('G');
    copy_st.push_back('G');

    name = "less";
    if ( (my < copy_my) && (st < copy_st) )
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;

    my.insert(my.begin(), 5, 'G');
    st.insert(st.begin(), 5, 'G');

    name = "greater";

    if ( (my > copy_my) && (st > copy_st) )
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;
    st.clear();
    my.clear();
}

void size_test(ft::vector<char> &my, std::vector<char> &st, std::string &message){
    my.assign(message.begin(), message.end());
    st.assign(message.begin(), message.end());

    my.resize(42);
    st.resize(42);

    std::string as = "resize";
    compare_vectors(my, st, as);

    as = "reserve";

    my.reserve(42 * 5);
    st.reserve(42 * 5);
	for (unsigned long int i = 0; i < st.capacity(); i++){
		my[i] = message[0];
		st[i] = message[0];
	}
    compare_vectors(my, st, as);
    st.clear();
    my.clear();
}

void swap_test(ft::vector<char> &my, std::vector<char> &st, std::string &message){
    my.assign(message.begin(), message.end());
    st.assign(message.begin(), message.end());
    ft::vector<char> copy_my(message.begin(), message.end() - 3);
    std::vector<char> copy_st(message.begin(), message.end() - 3);
    my.swap(copy_my);
    st.swap(copy_st);

    std::string as = "swap vectors";
    compare_vectors(my, st, as);
    as = "swap copies";
    compare_vectors(copy_my, copy_st, as);
    st.clear();
    my.clear();
}

void all_methods(ft::vector<char> &my, std::string &message){
    try
    {
        ft::vector<char> copy_my(message.begin(), message.end() - 3);
        my.assign(message.begin(), message.end());
        my.at(4);
        my.back();
        my.begin();
        my.capacity();
        my.empty();
        my.end();
        my.erase(my.end() - 1);
        my.front();
        my.get_allocator();
        my.insert(my.begin(), 's');
        my.max_size();
        my.operator[](0);
        my.operator=(copy_my);
        my.pop_back();
        my.push_back('s');
        my.rbegin();
        my.rend();
        my.reserve(12);
        my.resize(11);
        my.size();
        my.swap(copy_my);
        std::cout << OK << "all vector methods" << std::endl;
    }
    catch(...)
    {
        std::cout << KO << "all vector methods" << std::endl;
    }
    
}

int vector_test(std::string &message){
    ft::vector<char> my;
    std::vector<char> st(2);
    std::cout << std::endl << VECTOR << std::endl;
    all_methods(my, message);
    assign(my, st, message);
    vec_at(my, st, message);
    insert(my, st, message);
    push_pop(my, st, message);
    relation_and_construct(my, st, message);
    size_test(my, st, message);
    swap_test(my, st, message);
    std::cout << END << std::endl;
    return 0;
}