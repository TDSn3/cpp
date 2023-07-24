/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 22:05:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1] || !argv[1][0])
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad numbers of arguments." << COLOR_RESET << std::endl;
		return (1);
	}

	std::string			line(argv[1]);

	if (use_vector(line) || use_list(line))
		return (1);

	return (0);
}
