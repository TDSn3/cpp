/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/21 13:51:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

void	sort_pair(std::vector<int> :: iterator it, std::vector<int> :: iterator end, size_t size);
void	recursive_sort_biggest_num_pairs(std::vector<int> :: iterator it1, std::vector<int> :: iterator it2, size_t size_it1, size_t size_it2);

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad numbers of arguments." << COLOR_RESET << std::endl;
		return (1);
	}

	std::cout << argv[1] << std::endl;

	std::vector<int>						*vect_line = NULL;
	std::string								line(argv[1]);

	vect_line = parsing(line);
	if (!vect_line)
		return (1);

	std::vector<int> :: iterator			it_vect_line = (*vect_line).begin();
	Pair_it< std::vector<int> :: iterator >	P_it(it_vect_line, 2);

	std::cout << "-> " << it_vect_line[0] << std::endl;

	sort_pair(it_vect_line, (*vect_line).end(), (*vect_line).size());

	std::cout << "\n-----" << std::endl;
	recursive_sort_biggest_num_pairs(it_vect_line, it_vect_line, (*vect_line).size() / 2, 0);

	//std::vector<std::vector<int> * >	*vect_list_pair;

	//vect_list_pair = NULL;
	//vect_list_pair = make_pair(vect_line);
	//if (!vect_list_pair)
	//	return (1);

	//for (std::vector<std::vector<int> * >::iterator it = vect_list_pair->begin(); it != vect_list_pair->end(); it++)
	//{
	//	if (*it)
	//	{
	//		delete *it;
	//		*it = NULL;
	//	}
	//}
	//delete vect_list_pair;
	delete vect_line;

	return (0);
}

void	sort_pair(std::vector<int> :: iterator it, std::vector<int> :: iterator end, size_t size)
{
	if (size % 2)
		end--;
	while (it != end)
	{
		if (it[0] > it[1])
		{
			int	stock;

			stock = it[0];
			it[0] = it[1];
			it[1] = stock;
		}

		std::cout << "[" << it[0] << "]";
		std::cout << "\t[" << it[1] << "]";
		std::cout << std::endl;
		it += 2;
	}	
}

void	recursive_sort_biggest_num_pairs(std::vector<int> :: iterator it1, std::vector<int> :: iterator it2, size_t size_it1, size_t size_it2)
{
	size_t	plus_if_odd1 = 0;
	size_t	plus_if_odd2 = 0;

	if (size_it1 > 2)
		plus_if_odd1 = size_it1 % 2;
	if (size_it2 > 2)
		plus_if_odd2 = size_it2 % 2;


	std::cout << COLOR_DIM_CYAN;
	std::cout << "it1 = " << *it1 << ", it2 = " << *it2 << std::endl;
	std::cout << "size1 = " << size_it1 << ", size2 = " << size_it2 << std::endl;
	std::cout << COLOR_RESET;
	std::cout << "it1 : ";
	for(size_t i = 0; i < size_it1; i++)
	{
		std::cout << it1[static_cast<int>(i * 2 + 1)] << " ";
	}
	std::cout << std::endl;

	std::cout << "it2 : ";
	for(size_t i = 0; i < size_it2; i++)
	{
		std::cout << it2[static_cast<int>(i * 2 + 1)] << " ";
	}
	std::cout << "\n-----" << std::endl;

	if (size_it1 > 2)
		recursive_sort_biggest_num_pairs(
			it1,
			it1 + (static_cast<int>( size_it1 / 2 + plus_if_odd1 ) * 2),
			static_cast<size_t>( size_it1 / 2 + plus_if_odd1 ),
			size_it1 / 2 );
	if (size_it2 > 2)
	{
		recursive_sort_biggest_num_pairs(
			it2,
			it2 + (static_cast<int>( size_it2 / 2 + plus_if_odd2 ) * 2),
			static_cast<size_t>( size_it2 / 2 + plus_if_odd2 ),
			size_it2 / 2 );
	}

	std::cout << "\n______" << std::endl;
	if (size_it1 && size_it2)
	{
		std::vector<int>	stock;
		size_t				i;
		size_t				i1;
		size_t				i2;
		int					stock_it1;
		int					stock_it2;

		i = 0;
		i1 = 0;
		i2 = 0;
		while (i < size_it1 + size_it2)
		{
			stock_it1 = it1[static_cast<int>(i1 * 2 + 1)];
			
//			std::cout << COLOR_CYAN << stock_it1 << COLOR_RESET << " ";
			if (i2 < size_it2)
			{
				stock_it2 = it2[static_cast<int>(i2 * 2 + 1)];

//				std::cout << COLOR_MAGENTA << stock_it2 << COLOR_RESET << " ";
				
				if (stock_it1 < stock_it2)
				{
					stock.push_back(stock_it1);
					i1++;
				}
				else
				{
					stock.push_back(stock_it2);
					i2++;					
				}
			}
			else
			{
				stock.push_back(stock_it1);
				i1++;
			}
			i++;
		}
		for(std::vector<int> :: iterator itX = stock.begin(); itX != stock.end(); itX++)
		{
			std::cout << *itX << " " << std::endl;
//			*it1 = *itX;
//			it1 += 2;
		}


		std::vector<int> :: iterator itX = stock.begin();
		std::cout << "it : " << COLOR_CYAN;
		for(size_t ii = 0; ii < size_it1 + size_it2; ii++)
		{
			std::cout << it1[static_cast<int>(ii * 2 + 1)] << " ";
			it1[static_cast<int>(ii * 2 + 1)] = *itX;
			itX++;
		}
		std::cout << COLOR_RESET << std::endl;

		std::cout << "it : " << COLOR_MAGENTA;
		for(size_t ii = 0; ii < size_it1 + size_it2; ii++)
		{
			std::cout << it1[static_cast<int>(ii * 2 + 1)] << " ";
		}
		std::cout << COLOR_RESET << std::endl;

	}
	std::cout << "\n======" << std::endl;
}
