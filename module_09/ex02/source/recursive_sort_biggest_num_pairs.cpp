/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort_biggest_num_pairs.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:31:38 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 21:39:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

static void					divide_by_two(std::vector<int> :: iterator it1, std::vector<int> :: iterator it2, size_t size_it1, size_t size_it2);
static void					l_divide_by_two(std::list<int> :: iterator it1, std::list<int> :: iterator it2, size_t size_it1, size_t size_it2);

void	recursive_sort_biggest_num_pairs(std::vector<int> :: iterator it1, std::vector<int> :: iterator it2, size_t size_it1, size_t size_it2)
{
	divide_by_two(it1, it2, size_it1, size_it2);

	if (size_it1 && size_it2)
	{
		std::vector<int>	stock;
		std::vector<int>	stock_smallest;
		size_t				i;
		size_t				i1;
		size_t				i2;
		int					stock_it1;
		int					stock_it2;
		int					stock_smallest_it1;
		int					stock_smallest_it2;

		i = 0;
		i1 = 0;
		i2 = 0;
		while (i < size_it1 + size_it2)
		{
			stock_it1 = it1[static_cast<int>(i1 * 2 + 1)];
			stock_smallest_it1 = it1[static_cast<int>(i1 * 2)];

			if (i2 < size_it2)
			{
				stock_it2 = it2[static_cast<int>(i2 * 2 + 1)];
				stock_smallest_it2 = it2[static_cast<int>(i2 * 2)];
				
				if (stock_it1 < stock_it2 && i1 < size_it1)
				{
					stock.push_back(stock_it1);
					stock_smallest.push_back(stock_smallest_it1);
					i1++;
				}
				else
				{
					stock.push_back(stock_it2);
					stock_smallest.push_back(stock_smallest_it2);
					i2++;					
				}
			}
			else
			{
				stock.push_back(stock_it1);
				stock_smallest.push_back(stock_smallest_it1);
				i1++;
			}
			i++;
		}

		std::vector<int> :: iterator it_stock = stock.begin();
		std::vector<int> :: iterator it_stock_smallest = stock_smallest.begin();

		while (it_stock != stock.end())
		{
			it1[0] = *it_stock_smallest;
			it1[1] = *it_stock;

			it_stock++;
			it_stock_smallest++;
			it1 += 2;
		}
	}
}

static void	divide_by_two(std::vector<int> :: iterator it1, std::vector<int> :: iterator it2, size_t size_it1, size_t size_it2)
{
	size_t	plus_if_odd1 = 0;
	size_t	plus_if_odd2 = 0;

	if (size_it1 > 2)
		plus_if_odd1 = size_it1 % 2;
	if (size_it2 > 2)
		plus_if_odd2 = size_it2 % 2;

	if (size_it1 > 1)
		recursive_sort_biggest_num_pairs(
			it1,
			it1 + (static_cast<int>( size_it1 / 2 + plus_if_odd1 ) * 2),
			static_cast<size_t>( size_it1 / 2 + plus_if_odd1 ),
			size_it1 / 2 );
	if (size_it2 > 1)
	{
		recursive_sort_biggest_num_pairs(
			it2,
			it2 + (static_cast<int>( size_it2 / 2 + plus_if_odd2 ) * 2),
			static_cast<size_t>( size_it2 / 2 + plus_if_odd2 ),
			size_it2 / 2 );
	}
}

void	l_recursive_sort_biggest_num_pairs(std::list<int> :: iterator it1, std::list<int> :: iterator it2, size_t size_it1, size_t size_it2)
{
	l_divide_by_two(it1, it2, size_it1, size_it2);

	if (size_it1 && size_it2)
	{
		std::vector<int>	stock;
		std::vector<int>	stock_smallest;
		size_t				i;
		size_t				i1;
		size_t				i2;
		int					stock_it1;
		int					stock_it2;
		int					stock_smallest_it1;
		int					stock_smallest_it2;

		i = 0;
		i1 = 0;
		i2 = 0;
		while (i < size_it1 + size_it2)
		{
			stock_it1 = *give_it_list(it1, static_cast<int>(i1 * 2 + 1));
			stock_smallest_it1 = *give_it_list(it1, static_cast<int>(i1 * 2));

			if (i2 < size_it2)
			{
				stock_it2 = *give_it_list(it2, static_cast<int>(i2 * 2 + 1));
				stock_smallest_it2 = *give_it_list(it2, static_cast<int>(i2 * 2));
				
				if (stock_it1 < stock_it2 && i1 < size_it1)
				{
					stock.push_back(stock_it1);
					stock_smallest.push_back(stock_smallest_it1);
					i1++;
				}
				else
				{
					stock.push_back(stock_it2);
					stock_smallest.push_back(stock_smallest_it2);
					i2++;					
				}
			}
			else
			{
				stock.push_back(stock_it1);
				stock_smallest.push_back(stock_smallest_it1);
				i1++;
			}
			i++;
		}

		std::vector<int> :: iterator it_stock = stock.begin();
		std::vector<int> :: iterator it_stock_smallest = stock_smallest.begin();

		while (it_stock != stock.end())
		{
			*it1 = *it_stock_smallest;
			it1++;
			*it1 = *it_stock;
			it1++;
			it_stock++;
			it_stock_smallest++;
		}
	}
}

static void	l_divide_by_two(std::list<int> :: iterator it1, std::list<int> :: iterator it2, size_t size_it1, size_t size_it2)
{
	std::list<int> :: iterator	it3;
	int							i;
	size_t						plus_if_odd1 = 0;
	size_t						plus_if_odd2 = 0;

	if (size_it1 > 2)
		plus_if_odd1 = size_it1 % 2;
	if (size_it2 > 2)
		plus_if_odd2 = size_it2 % 2;

	if (size_it1 > 1)
	{
		it3 = it1;
		i = (static_cast<int>( size_it1 / 2 + plus_if_odd1 ) * 2);

		for (int j = 0; j < i; j++)
			it3++;

		l_recursive_sort_biggest_num_pairs(
			it1,
			it3,
			static_cast<size_t>( size_it1 / 2 + plus_if_odd1 ),
			size_it1 / 2 );
	}
	if (size_it2 > 1)
	{
		it3 = it2;
		i = (static_cast<int>( size_it2 / 2 + plus_if_odd2 ) * 2);

		for (int j = 0; j < i; j++)
			it3++;

		l_recursive_sort_biggest_num_pairs(
			it2,
			it3,
			static_cast<size_t>( size_it2 / 2 + plus_if_odd2 ),
			size_it2 / 2 );
	}
}
