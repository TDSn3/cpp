/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:49:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/13 08:39:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cctype>

template<typename T>
void	swap(T &arg_1, T &arg_2)
{
	T	stock;

	stock = arg_1;
	arg_1 = arg_2;
	arg_2 = stock;
}

template<typename T>
const T	&min(const T &arg_1, const T &arg_2)
{
	return (arg_1 >= arg_2 ? arg_2 : arg_1);
}

template<typename T>
const T	&max(const T &arg_1, const T &arg_2)
{
	return (arg_1 <= arg_2 ? arg_2 : arg_1);
}

#endif