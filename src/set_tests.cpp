/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <tphung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:14:38 by tphung            #+#    #+#             */
/*   Updated: 2022/11/25 21:53:04 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void fill_set(ft::set<char> &my, std::string &message){
    for (unsigned int i = 0; i < message.length(); i++){
        my.insert(message[i]); 
    }
}

void fill_set(std::set<char> &my, std::string &message){
    for (unsigned int i = 0; i < message.length(); i++){
        my.insert(message[i]); 
    }
}

int compare_set(ft::set<char> &my, std::set<char> &st, std::string &name){
    ft::set<char>::iterator it1 = my.begin();
    std::set<char>::iterator it2 = st.begin();
    for ( ; it1 != my.end(); it1++, it2++ ){
        if (    *it1 != *it2 ||
                my.size() != st.size()){
            std::cout << KO << name << std::endl;
            return 1;
        }
    }
    std::cout << OK << name << std::endl;
    return 0;
}

void insert(ft::set<char> &my, std::set<char> &st, std::string &message){
    std::string as = "insert by values";
    for (unsigned int i = 0; i < message.length(); i++){
        my.insert(message[i]);
        st.insert(message[i]);
    }
    compare_set(my, st, as);

    as = "insert by iterators";
    my.insert(my.begin(), message[0] + 'z');
    st.insert(st.begin(), message[0] + 'z');
    compare_set(my, st, as);

    as = "insert by range";
    std::set<char> st_another;
    ft::set<char> my_another;
    st_another.insert(st.begin(), st.find(message[0] + 'z'));
    my_another.insert(my.begin(), my.find(message[0] + 'z'));
    compare_set(my_another, st_another, as);

    st.clear();
    my.clear();

}

void swap_test(ft::set<char> &my, std::set<char> &st, std::string &message){
    fill_set(my, message);
    fill_set(st, message);
    ft::set<char> copy_my(my.begin(), my.find(message[4]));
    std::set<char> copy_st(st.begin(), st.find(message[4]));
    my.swap(copy_my);
    st.swap(copy_st);

    std::string as = "swap sets";
    compare_set(my, st, as);
    as = "swap copies";
    compare_set(copy_my, copy_st, as);
    st.clear();
    my.clear();
}


void all_methods(ft::set<char> &my, std::string &message){
    fill_set(my, message);
    try
    {
        ft::set<char> copy_my(my);
        my.begin();
        my.count(message[0]);
        my.empty();
        my.end();
        my.equal_range(message[1]);
        my.erase(my.begin());
        my.find(message[0]);
        my.get_allocator();
        my.insert(message[0]);
        my.key_comp();
        my.lower_bound(message[1]);
        my.max_size();
        my.operator=(copy_my);
        my.rbegin();
        my.rend();
        my.size();
        my.swap(copy_my);
        my.upper_bound(message[1]);
        my.value_comp();
        my.clear();
        std::cout << OK << "all set methods" << std::endl;
    }
    catch(...)
    {
        std::cout << KO << "all set methods" << std::endl;
    }   
}


void equal_range(ft::set<char> &my, std::set<char> &st, std::string &message){
    fill_set(my, message);
    fill_set(st, message);
    std::pair<std::set<char>::iterator,std::set<char>::iterator> st_ret;
    st_ret = st.equal_range(message[2]);
    ft::pair<ft::set<char>::iterator,ft::set<char>::iterator> my_ret;
    my_ret = my.equal_range(message[2]);

    std::string name = "equal range lower";
    if ( *st_ret.first == *my_ret.first )
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;

    name = "equal range upper";
    if ( *st_ret.second == *my_ret.second)
        std::cout << OK << name << std::endl;
    else std::cout << KO << name << std::endl;
    my.clear();
    st.clear();
    return ;
}

void erase(ft::set<char> &my, std::set<char> &st, std::string &message){
    fill_set(my, message);
    fill_set(st, message);
    std::set<char>::iterator st_ret;
    ft::set<char>::iterator my_ret;
    st_ret = st.find(message[1]);
    my_ret = my.find(message[1]);

    std::string name = "find erase by iterator";
    st.erase(st_ret);
    my.erase(my_ret);
    compare_set(my, st, name);

    name = "erase by key";
    st.erase(message[2]);
    my.erase(message[2]);
    compare_set(my, st, name);

    name = "erase by range";
    st_ret = st.find(message[3]);
    my_ret = my.find(message[3]);
    st.erase(st_ret, st.end());
    my.erase(my_ret, my.end());
    compare_set(my, st, name);

    my.clear();
    st.clear();
    return ;
}

void get_alloc(ft::set<char> &my, std::set<char> &st){
    int st_psize;
    char *p_st;

    int my_psize;
    char *p_my;

    p_st=st.get_allocator().allocate(5);
    p_my=my.get_allocator().allocate(5);

    std::string name = "get_allocator sizes equal";
    st_psize = sizeof(std::set<char>::value_type)*5;
    my_psize = sizeof(ft::set<char>::value_type)*5;
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

int set_test(std::string &message){
    ft::set<char> my;
    std::set<char> st;
    std::cout << std::endl << SET << std::endl;
    all_methods(my, message);
    equal_range(my, st, message);
    erase(my, st, message);
    get_alloc(my, st );
    insert(my, st, message);
    swap_test(my, st, message);
    std::cout << END << std::endl;
    return 0;
}