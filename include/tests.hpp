/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <tphung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:16:08 by tphung            #+#    #+#             */
/*   Updated: 2022/11/25 16:40:17 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define FIRST "[  "
#define OK "[  \033[1;32mOK\033[0m  ] "
#define KO "[  \033[1;31mKO\033[0m  ] "
#define LAST "  ]"
#define VECTOR "\033[1;34m########## \033[1;33mVECTOR\033[1;34m ##########\033[0m"
#define STACK "\033[1;34m##########  \033[1;33mSTACK\033[1;34m ##########\033[0m"
#define MAP "\033[1;34m##########   \033[1;33mMAP\033[1;34m  ##########\033[0m"
#define SET "\033[1;34m##########   \033[1;33mSET\033[1;34m  ##########\033[0m"
#define END "\033[1;34m############################\033[0m"

int vector_test(std::string &message);
