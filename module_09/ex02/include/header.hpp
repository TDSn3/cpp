/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/25 09:10:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <cstdlib>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cctype>
# include <memory>
# include <vector>
# include <list>
# include <exception>
# include <ctime>
# include <iomanip>
# include <algorithm>

# include "colors.hpp"

int									use_vector(int argc, char **argv);
int									use_list(int argc, char **argv);
std::vector<int>					*parsing(int argc, char **argv);
std::list<int>						*l_parsing(int argc, char **argv);
std::vector<std::vector<int> * >	*make_pair(std::vector<int> *vect);
void								sort_pair(
										std::vector<int> :: iterator it,
										std::vector<int> :: iterator end,
										size_t size);
void								l_sort_pair(std::list<int> :: iterator it, std::list<int> :: iterator end, size_t size);
void								recursive_sort_biggest_num_pairs(
										std::vector<int> :: iterator it1,
										std::vector<int> :: iterator it2,
										size_t size_it1,
										size_t size_it2);
void								l_recursive_sort_biggest_num_pairs(std::list<int> :: iterator it1, std::list<int> :: iterator it2, size_t size_it1, size_t size_it2);
void								build_S_pend(
										std::vector<int> :: iterator it,
										std::vector<int> :: iterator end,
										size_t size,
										std::vector<int> &S,
										std::vector<int> &pend);
void								l_build_S_pend(std::list<int> :: iterator it, std::list<int> :: iterator end, size_t size, std::list<int> &S, std::list<int> &pend);
std::vector<int>					jacobsthal(size_t size);
std::list<int>						l_jacobsthal(size_t size);
void								binary_insert(
										std::vector<int> &S,
										size_t begin,
										size_t end,
										int num);
void								l_binary_insert(std::list<int> &S, size_t begin, size_t end, int num);
void								insert_sort_pend(
										std::vector<int> &S,
										std::vector<int> &pend);
void								l_insert_sort_pend(std::list<int> &S, std::list<int> &pend);
std::list<int> :: iterator			give_it_list(std::list<int> :: iterator it, int index);

template <typename T>
void show_S(T &container)
{
	size_t	i = 0;
	
	for (typename T :: iterator it = container.begin(); it != container.end() && i < 5; it++)
	{
		std::cout << *it << " ";
		i++;
	}
	if (i == 5)
		std::cout << "[...] " << container.back() << " ";
	std::cout << std::endl;
}

#endif
