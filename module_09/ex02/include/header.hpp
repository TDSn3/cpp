/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 15:25:49 by tda-silv         ###   ########.fr       */
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
# include <exception>

# include "colors.hpp"
# include "./class/Pair_it.hpp"

std::vector<int>					*parsing(std::string &line);
std::vector<std::vector<int> * >	*make_pair(std::vector<int> *vect);
void								sort_pair(
										std::vector<int> :: iterator it,
										std::vector<int> :: iterator end,
										size_t size);
void								recursive_sort_biggest_num_pairs(
										std::vector<int> :: iterator it1,
										std::vector<int> :: iterator it2,
										size_t size_it1,
										size_t size_it2);
void								build_S_pend(std::vector<int> :: iterator it,
										std::vector<int> :: iterator end,
										size_t size,
										std::vector<int> &S,
										std::vector<int> &pend);
std::vector<int>					jacobsthal(size_t size);
void								binary_insert(std::vector<int> &S,
										size_t begin,
										size_t end,
										int num);

#endif
