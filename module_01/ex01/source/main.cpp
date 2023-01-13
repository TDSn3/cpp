/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/13 09:43:03 by tda-silv         ###   ########.fr       */
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

	for (int i = 0; i < N; i++)
	{
		std::cout << std::setw(2) << i + 1 << " ";
		new_zombie_horde[i].announce();
	}
	
	delete [] new_zombie_horde;

	return (0);
}

static int	check_error(int argc, char **argv)
{
	std::string	argv_1;

	if (argc != 3 || !argv[1] || !argv[1][0] ||!argv[2] || !argv[2][0] )
		return (1);
	argv_1 = std::string(argv[1]);
	if (argv_1.find_first_not_of("0123456789") != std::string::npos)
		return (1);
	if (std::atoi(argv[1]) < 2)
		return (1);
	return (0);
}
