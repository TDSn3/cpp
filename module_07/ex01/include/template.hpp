/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:49:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/13 10:17:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cctype>

template<typename T, size_t, typename U>
void	iter(T *tab, const size_t &tab_size, U (*function_a)())
{
	size_t	i = 0;

	while (i < tab_size)
		(*function_a)(tab[i++]);
}

template<typename T>
void	print_one(const T &arg_1)
{
	std::cout << arg_1 << std::endl;
}

#endif