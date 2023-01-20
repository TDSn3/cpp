/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/20 09:47:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

static int	check_error(int argc, char **argv);
static void	init_index(char **argv, int &index);

int main(int argc, char **argv)
{
	Harl	class_harl;
	int		index;

	if (check_error(argc, argv))
		return (1);
	init_index(argv, index);
	class_harl.complain(index);
	return (0);
}

static int	check_error(int argc, char **argv)
{
	std::string	argv_1;
	int			conv_argv;
	
	if (argc != 2 || !argv[1] || !argv[1][0])
		return (1);
	argv_1 = std::string(argv[1]);
	if (argv_1.find_first_not_of("0123456789") != std::string::npos
		&& argv_1.compare("DEBUG")
		&& argv_1.compare("INFO")
		&& argv_1.compare("WARNING")
		&& argv_1.compare("ERROR"))
		return (1);
	if (argv_1.find_first_not_of("0123456789") == std::string::npos)
	{
		conv_argv = std::atoi(argv[1]);
		if (conv_argv < 1 || conv_argv > 4)
			return (1);
	}
	return (0);
}

static void	init_index(char **argv, int &index)
{
	std::string	argv_1;

	argv_1 = std::string(argv[1]);
	if (!argv_1.compare("DEBUG"))
		index = 1;
	else if (!argv_1.compare("INFO"))
		index = 2;
	else if (!argv_1.compare("WARNING"))
		index = 3;
	else if (!argv_1.compare("ERROR"))
		index = 4;
	else if (argv_1.find_first_not_of("0123456789") == std::string::npos)
		index = std::atoi(argv[1]);
}
