/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/12 22:24:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	check_error(int argc, char **argv);

int	main(int argc, char **argv)
{
	int		N;
	Zombie	*new_zombie_horde;

	if (check_error(argc, argv))
		return (1);
	N = std::atoi(argv[1]);
	new_zombie_horde = zombieHorde(N, std::string(argv[2]));
	delete [] new_zombie_horde;

	return (0);
}

static int	check_error(int argc, char **argv)
{
	std::string	first_arg;

	first_arg = std::string(argv[1]);
	if (argc != 3)
		return (1);
	if (std::atoi(argv[1]) < 2)
		return (1);
	if (!argv[2] || !argv[2][0])
		return (1);
	return (0);
}
