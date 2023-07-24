/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_S.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:07:09 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 20:07:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

void	show_S(std::vector<int> &S)
{
	for (std::vector<int> :: iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
