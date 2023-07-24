/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:48:27 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 19:27:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

static int	recursive_jacobsthal(int n);

std::vector<int>	jacobsthal(size_t size)
{
	std::vector<int>	ret;
	size_t				i;			

	i = 3;
	for (int stock = 3; stock < static_cast<int>(size); stock = recursive_jacobsthal(static_cast<int>(i) ) )
	{
		ret.push_back(stock);
		i++;
	}
	return (ret);
}

static int	recursive_jacobsthal(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	return (recursive_jacobsthal(n - 1) + 2 * recursive_jacobsthal(n - 2) );
}
