/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/07 11:56:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

int	read_file(std::ifstream &file);

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		std::cerr << "Error: bad numbers of arguments." << std::endl;
		return (1);
	}

	std::ifstream	file(argv[1]);

	if (!file.is_open() && read_file(file))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	return (0);
}

int	read_file(std::ifstream &file)
{
	return (0);
}
