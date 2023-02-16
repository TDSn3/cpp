/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:49:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/16 12:36:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cctype>

template<typename T>
void	iter(T *tab, size_t tab_size, void (*function_a)(T const &))
{
	size_t	i = 0;

	while (i < tab_size)
		function_a(tab[i++]);
}

template<typename T>
void	print_one(T arg_1)
{
	std::cout << arg_1 << std::endl;
}

#endif