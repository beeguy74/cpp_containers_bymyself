/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <tphung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:14:38 by tphung            #+#    #+#             */
/*   Updated: 2022/11/26 12:29:05 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void fill_map(ft::map<char,int> &my, std::string &message){
    for (unsigned int i = 0; i < message.length(); i++){
        my[message[i]] = i; 
    }
}

void fill_map(std::map<char,int> &my, std::string &message){
    for (unsigned int i = 0; i < message.length(); i++){
        my[message[i]] = i; 
    }
}

int compare_map(ft::map<char, int> &my, std::map<char, int> &st, std::string &name){
    ft::map<char, int>::iterator it1 = my.begin();
    std::map<char, int>::iterator it2 = st.begin();
    for ( ; it1 != my.end(); it1++, it2++ ){
        if (    it1->first != it2->first ||
                it1->second != it2->second || 
                my.size() != st.size()){
            std::cout << KO << name << std::endl;
            return 1;
        }
    }
    std::cout << OK << name << std::endl;
    return 0;
}

void insert(ft::map<char, int> &my, std::map<char, int> &st, std::string &message){
    std::string as = "insert by values";
    for (unsigned int i = 0; i < message.length(); i++){
        my.insert(ft::pair<char,int>(message[i],i));
        st.insert(std::pair<char,int>(message[i],i));
    }
    compare_map(my, st, as);
    my.print_tree();

    as = "insert by iterators";
    my.insert(my.begin(), ft::pair<char,int>('\"', 111));
    st.insert(st.begin(), std::pair<char,int>('\"', 111));
    my.insert(my.begin(), ft::pair<char,int>('=', 222));
    st.insert(st.begin(), std::pair<char,int>('=', 222));
    my.insert(my.begin(), ft::pair<char,int>('{', 333));
    st.insert(st.begin(), std::pair<char,int>('{', 333));
    compare_map(my, st, as);
    my.print_tree();

    as = "insert by range";
    std::map<char,int> st_another;
    ft::map<char,int> my_another;
    st_another.insert(st.begin(), st.find(message[0] + 'z'));
    my_another.insert(my.begin(), my.find(message[0] + 'z'));
    compare_map(my_another, st_another, as);

    st.clear();
    my.clear();

}

void swap_test(ft::map<char, int> &my, std::map<char, int> &st, std::string &message){
    fill_map(my, message);
    fill_map(st, message);
    ft::map<char, int> copy_my(my.begin(), my.find(message[4]));
    std::map<char, int> copy_st(st.begin(), st.find(message[4]));
    my.swap(copy_my);
    st.swap(copy_st);

    std::string as = "swap maps";
    compare_map(my, st, as);
    as = "swap copies";
    compare_map(copy_my, copy_st, as);
    st.clear();
    my.clear();
}


void all_methods(ft::map<char,int> &my, std::string &message){
    fill_map(my, message);
    try
    {
        ft::map<char,int> copy_my(my);
        my.begin();
        my.count(message[0]);
        my.empty();
        my.end();
        my.equal_range(message[1]);
        my.erase(my.begin());
        my.find(message[0]);
        my.get_allocator();
        my.insert(ft::make_pair<char, int>(message[0], message[message.length()]));
        my.key_comp();
        my.lower_bound(message[1]);
        my.max_size();
        my.operator[](0);
        my.operator=(copy_my);
        my.rbegin();
        my.rend();
        my.size();
        my.swap(copy_my);
        my.upper_bound(message[1]);
        my.value_comp();
        my.clear();
        std::cout << OK << "all map methods" << std::endl;
    }
    catch(...)
    {
        std::cout << KO << "all map methods" << std::endl;
    }   
}


void equal_range(ft::map<char, int> &my, std::map<char, int> &st, std::string &message){
    fill_map(my, message);
    fill_map(st, message);
    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> st_ret;
    st_ret = st.equal_range(message[2]);
    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> my_ret;
    my_ret = my.equal_range(message[2]);

    std::string name = "equal range lower";
    if ( st_ret.first->first == my_ret.first->first &&
            st_ret.first->second == my_ret.first->second)
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;

    name = "equal range upper";
    if ( st_ret.second->first == my_ret.second->first &&
            st_ret.second->second == my_ret.second->second)
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;
    my.clear();
    st.clear();
    return ;
}

void erase(ft::map<char, int> &my, std::map<char, int> &st, std::string &message){
    fill_map(my, message);
    fill_map(st, message);
    std::map<char,int>::iterator st_ret;
    ft::map<char,int>::iterator my_ret;
    st_ret = st.find(message[1]);
    my_ret = my.find(message[1]);

    std::string name = "find erase by iterator";
    st.erase(st_ret);
    my.erase(my_ret);
    compare_map(my, st, name);

    name = "erase by key";
    st.erase(message[2]);
    my.erase(message[2]);
    compare_map(my, st, name);

    name = "erase by range";
    st_ret = st.find(message[3]);
    my_ret = my.find(message[3]);
    st.erase(st_ret, st.end());
    my.erase(my_ret, my.end());
    compare_map(my, st, name);

    my.clear();
    st.clear();
    return ;
}

void get_alloc(ft::map<char, int> &my, std::map<char, int> &st){
    int st_psize;
    std::pair<const char,int>* p_st;

    int my_psize;
    ft::pair<const char,int>* p_my;

    p_st=st.get_allocator().allocate(5);
    p_my=my.get_allocator().allocate(5);

    std::string name = "get_allocator sizes equal";
    st_psize = sizeof(std::map<char,int>::value_type)*5;
    my_psize = sizeof(ft::map<char,int>::value_type)*5;
    if ( st_psize == my_psize)
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;

    name = "get_allocator sizes empty";
    try {
        my.get_allocator().deallocate(p_my,5);
        st.get_allocator().deallocate(p_st,5);
        std::cout << OK << name << std::endl;
    }
    catch(...){
        std::cout << KO << name << std::endl;
    }
    my.clear();
    st.clear();
    return ;
}

int map_test(std::string &message){
    ft::map<char, int> my;
    std::map<char, int> st;
    std::cout << std::endl << MAP << std::endl;
    all_methods(my, message);
    equal_range(my, st, message);
    erase(my, st, message);
    get_alloc(my, st );
    insert(my, st, message);
    swap_test(my, st, message);
    std::cout << END << std::endl;
    return 0;
}