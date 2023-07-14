/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_ato.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:21:23 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/14 11:13:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

int	check_error_atol(std::string str, long int result)
{
	size_t	i;
	int		count_point;

	i = 0;
	count_point = 0;
	if (result > 2147483647 || result < -2147483648)
		return (1);
	if (str.empty())
		return (1);
	while (str[i])
	{
		if (str[i] == '.')
			count_point++;
		i++;
	}
	if (count_point > 1)
		return (1);
	return (0);
}

int	check_error_atof(std::string str, double result)
{
	size_t	i;
	int		count_point;

	i = 0;
	count_point = 0;
	if (result > 2147483647 || result < -2147483648)
		return (1);
	if (str.empty())
		return (1);
	while (str[i])
	{
		if (str[i] == '.')
			count_point++;
		i++;
	}
	if (count_point > 1)
		return (1);
	if (count_point == 1 && i == 1)
		return (1);
	return (0);
}
