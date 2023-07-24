/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:25:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 21:44:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

void binary_insert(std::vector<int> &S, size_t begin, size_t end, int num)
{	
	if (begin >= end)
	{
		S.insert(S.begin() + static_cast<int>(begin), num);
		return;
	}

	size_t middle = (begin + end) / 2;

	if (num <= S[middle])
	{
		binary_insert(S, begin, middle, num);
	} else
	{
		binary_insert(S, middle + 1, end, num);
	}
}

void l_binary_insert(std::list<int> &S, size_t begin, size_t end, int num)
{	
	if (begin >= end)
	{
		S.insert(give_it_list(S.begin(), static_cast<int>(begin)), num);
		return;
	}

	size_t middle = (begin + end) / 2;

	if (num <= *give_it_list(S.begin(), static_cast<int>(middle)) )
	{
		l_binary_insert(S, begin, middle, num);
	} else
	{
		l_binary_insert(S, middle + 1, end, num);
	}
}
