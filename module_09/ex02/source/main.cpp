/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 16:11:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"

void	recursive_sort_biggest_num_pairs(std::vector<int> :: iterator it1, std::vector<int> :: iterator it2, size_t size_it1, size_t size_it2);
void	show_pair(std::vector<int> :: iterator it, std::vector<int> :: iterator end, size_t size);
void	binary_insert(std::vector<int> &S, size_t begin, size_t end, int num);

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad numbers of arguments." << COLOR_RESET << std::endl;
		return (1);
	}

	std::vector<int>						*vect_line = NULL;
	std::vector<int>						S;
	std::vector<int>						pend;
	std::string								line(argv[1]);

	vect_line = parsing(line);
	if (!vect_line)
		return (1);
	if ( (*vect_line).size() == 1)	//	<---
	{
		std::cout << (*vect_line)[0] << std::endl;
		return (0);
	}

	std::vector<int> :: iterator			it_vect_line = (*vect_line).begin();
	Pair_it< std::vector<int> :: iterator >	P_it(it_vect_line, 2);

	sort_pair(it_vect_line, (*vect_line).end(), (*vect_line).size() );
	show_pair(it_vect_line, (*vect_line).end(), (*vect_line).size() );

	std::cout << "\n-----\n" << std::endl;

	recursive_sort_biggest_num_pairs(it_vect_line, it_vect_line, (*vect_line).size() / 2, 0);
	show_pair(it_vect_line, (*vect_line).end(), (*vect_line).size() );

	std::cout << "\n-----\n" << std::endl;

	build_S_pend(it_vect_line, (*vect_line).end(), (*vect_line).size(), S, pend);

	std::cout << "S :\t";
	for (std::vector<int> :: iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "pend :\t";
	for (std::vector<int> :: iterator it = pend.begin(); it != pend.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::vector<int>	jacobsthal_stock;

	jacobsthal_stock = jacobsthal(pend.size());
	std::cout << "jacobsthal_stock :\t";
	for (std::vector<int> :: iterator it = jacobsthal_stock.begin(); it != jacobsthal_stock.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (std::vector<int> :: iterator it = jacobsthal_stock.begin(); it != jacobsthal_stock.end(); it++)
	{
		std::cout << "insert : " << pend[static_cast<size_t>(*it)] << "\n";
		binary_insert(S, 0, S.size(), pend[static_cast<size_t>(*it)] );
		*it = pend[static_cast<size_t>(*it)];	// replace index by value
	}


	// for (std::vector<int> :: iterator it = jacobsthal_stock.begin(); it != jacobsthal_stock.end(); it++)
	// {
	// 	std::vector<int> :: iterator it_erase = std::find(pend.begin(), pend.end(), pend[static_cast<size_t>(*it)]);
	// 	if (it_erase != pend.end())
	// 		pend.erase(it_erase);
	// }

	std::cout << "S :\t";
	for (std::vector<int> :: iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "pend :\t";
	for (std::vector<int> :: iterator it = pend.begin(); it != pend.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;



	for (std::vector<int> :: iterator it = jacobsthal_stock.begin(); it != jacobsthal_stock.end(); it++)
	{
		std::vector<int> :: iterator it_erase = std::find(pend.begin(), pend.end(), *it);
		std::cout << "erase : " << *it_erase << "\n";
		pend.erase(it_erase);
	}

	for (std::vector<int> :: iterator it = pend.begin(); it != pend.end(); it++)
		binary_insert(S, 0, S.size(), *it);

	std::cout << "S :\t";
	for (std::vector<int> :: iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	delete vect_line;

	return (0);
}

void	show_pair(std::vector<int> :: iterator it, std::vector<int> :: iterator end, size_t size)
{
	if (size % 2)
		end--;
	while (it != end)
	{
		std::cout << "[" << it[0] << "]";
		std::cout << "\t[" << it[1] << "]";
		std::cout << std::endl;
		it += 2;
	}
	if (size % 2)
		std::cout << "[" << it[0] << "]\n";
}
