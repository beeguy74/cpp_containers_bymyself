/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2022/11/21 13:59:27 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "test_utils.hpp"
#include "map.hpp"
#include <map>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;


template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  std::cout<< "test starts here\n";
  map<char,int> mymap;
  map<char,int>::iterator it;

  // insert some values:
  std::cout<< "insert starts here\n";
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  std::cout<< "find starts here\n";
  it=mymap.find('b');
  std::cout << it->first << std::endl;
  std::cout << "found b\n";
  std::cout<< "erase starts here\n";
  mymap.erase (it);                   // erasing by iterator
  std::cout << "erased iterator to b\n";
  it=mymap.find('c');
  std::cout << it->first << '\n' <<"found 'c'\n";
  mymap.erase ('c');                  // erasing by key
  std::cout << "erase by key 'c'\n";
  it=mymap.find ('e');
  std::cout << "erase by range 'e' to end\n";
  mymap.erase ( it, mymap.end() );    // erasing by range

  std::cout << " display :\n";
  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
