/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:29:42 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 09:34:53 by tda-silv         ###   ########.fr       */
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

		std::cout << "[" << it[0] << "]";
		std::cout << "\t[" << it[1] << "]";
		std::cout << std::endl;
		it += 2;
	}
	if (size % 2)
		std::cout << "[" << it[0] << "]\n";
}
