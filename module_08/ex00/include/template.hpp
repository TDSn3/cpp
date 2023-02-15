/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:49:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/15 15:50:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cctype>
# include <algorithm>

template<typename T>
typename T::iterator	easyfind(T arg_1, int arg_2)
{
	typename T::iterator	it_T;

	it_T = std::find(arg_1.begin(), arg_1.end(), arg_2);
	if (it_T == arg_1.end())
		throw (std::exception());
	return (it_T);
}

#endif