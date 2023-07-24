/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort_pend.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:33:23 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 21:46:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

void	insert_sort_pend(std::vector<int> &S, std::vector<int> &pend)
{
	std::vector<int>	jacobsthal_stock;

	jacobsthal_stock = jacobsthal(pend.size());

	for (std::vector<int> :: iterator it = jacobsthal_stock.begin(); it != jacobsthal_stock.end(); it++)
	{
		binary_insert(S, 0, S.size(), pend[static_cast<size_t>(*it)] );
		*it = pend[static_cast<size_t>(*it)];	// replace index by value
	}
	for (std::vector<int> :: iterator it = jacobsthal_stock.begin(); it != jacobsthal_stock.end(); it++)
	{
		std::vector<int> :: iterator it_erase = std::find(pend.begin(), pend.end(), *it);
		if (it_erase != pend.end())
			pend.erase(it_erase);
	}
	for (std::vector<int> :: iterator it = pend.begin(); it != pend.end(); it++)
		binary_insert(S, 0, S.size(), *it);
}

void	l_insert_sort_pend(std::list<int> &S, std::list<int> &pend)
{
	std::list<int>	jacobsthal_stock;

	jacobsthal_stock = l_jacobsthal(pend.size());

	for (std::list<int> :: iterator it = jacobsthal_stock.begin(); it != jacobsthal_stock.end(); it++)
	{
		l_binary_insert(S, 0, S.size(), *give_it_list(pend.begin(), *it) );
		*it = *give_it_list(pend.begin(), *it);	// replace index by value
	}
	for (std::list<int> :: iterator it = jacobsthal_stock.begin(); it != jacobsthal_stock.end(); it++)
	{
		std::list<int> :: iterator it_erase = std::find(pend.begin(), pend.end(), *it);
		if (it_erase != pend.end())
			pend.erase(it_erase);
	}
	for (std::list<int> :: iterator it = pend.begin(); it != pend.end(); it++)
		l_binary_insert(S, 0, S.size(), *it);
}
