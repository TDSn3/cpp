/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_S_pend.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:56:38 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 21:35:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

void	build_S_pend(std::vector<int> :: iterator it, std::vector<int> :: iterator end, size_t size, std::vector<int> &S, std::vector<int> &pend)
{
	if (size % 2)
		end--;
	if (size > 1)
	{
		S.push_back(it[0]);
		S.push_back(it[1]);
		it += 2;
	}
	while (it != end)
	{
		pend.push_back(it[0]);
		S.push_back(it[1]);
		it += 2;
	}
	if (size % 2)
		pend.push_back(it[0]);
}

void	l_build_S_pend(std::list<int> :: iterator it, std::list<int> :: iterator end, size_t size, std::list<int> &S, std::list<int> &pend)
{
	if (size % 2)
		end--;
	if (size > 1)
	{
		S.push_back(*it);
		it++;
		S.push_back(*it);
		it++;
	}
	while (it != end)
	{
		pend.push_back(*it);
		it++;
		S.push_back(*it);
		it++;
	}
	if (size % 2)
		pend.push_back(*it);
}
