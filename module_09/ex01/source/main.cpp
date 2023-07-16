/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/16 10:44:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

int		main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad numbers of arguments." << COLOR_RESET << std::endl;
		return (1);
	}

	std::string			line(argv[1]);
	std::istringstream	ss(line);
	std::string			stock;

	while (std::getline(ss, stock, ' '))
	{
		std::cout << stock << std::endl;
		for (std::string::iterator it = stock.begin(); it != stock.end(); it++)
		{
			if (!std::isdigit(*it) || *it != '+' || *it != '-' || *it != '/' || )
				return (1);	// Error
		}
	}

	return (0);
}
