/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/20 18:42:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

int	next(std::vector<int> *vect);

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad numbers of arguments." << COLOR_RESET << std::endl;
		return (1);
	}

	std::cout << argv[1] << std::endl;

	std::vector<int>					*vect_line = NULL;
	std::string							line(argv[1]);

	vect_line = parsing(line);
	if (!vect_line)
		return (1);

	std::vector<std::vector<int> * >	*vect_list_pair;

	vect_list_pair = NULL;
	vect_list_pair = make_pair(vect_line);
	if (!vect_list_pair)
		return (1);

	for (std::vector<std::vector<int> * >::iterator it = vect_list_pair->begin(); it != vect_list_pair->end(); it++)
	{
		if (*it)
		{
			delete *it;
			*it = NULL;
		}
	}
	delete vect_list_pair;
	delete vect_line;

	return (0);
}
