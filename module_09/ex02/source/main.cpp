/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/19 18:32:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

void	next(std::vector<int> *vect);

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad numbers of arguments." << COLOR_RESET << std::endl;
		return (1);
	}

	std::cout << argv[1] << std::endl;

	std::vector<int>	*vect = NULL;
	std::string			line(argv[1]);

	vect = parsing(line);
	if (!vect)
		return (1);

	next(vect);

	delete vect;

	return (0);
}

void	next(std::vector<int> *vect)
{
	std::vector<std::vector<int> >	vect_list(vect->size());
	size_t							i;

	i = 0;
	for (std::vector<int>::iterator it = vect->begin(); it != vect->end(); it++)
	{
		if (i == 0)
		{
			i++;
		}
		else
		{
			if (i < 2)
				i++;
			else
				i = 0;
		}
	}
}
