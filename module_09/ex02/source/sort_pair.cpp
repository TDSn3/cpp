/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:29:42 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 21:09:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

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
		it += 2;
	}
}

void	l_sort_pair(std::list<int> :: iterator it, std::list<int> :: iterator end, size_t size)
{
	std::list<int> :: iterator it2;

	if (size % 2)
		end--;
	while (it != end)
	{
		it2 = it;
		it ++;

		if (*it2 > *it)
		{
			int	stock;

			stock = *it2;
			*it2 = *it;
			*it = stock;
		}
		it ++;
	}
}
