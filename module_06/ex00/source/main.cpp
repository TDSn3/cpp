/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/09 12:29:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

//static void	wait_return(void);
static std::string	check_error(int argc, char **argv);

int main(int argc, char **argv)
{
	// char || int || float || double	

	try
	{
		std::string	arg = check_error(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception!" << std::endl;
		return (1);
	}
	return (0);
}

static std::string	check_error(int argc, char **argv)
{
	if (argc != 2)
		throw (std::exception());
	std::string	return_string = argv[1];
	return (return_string);
}

//static void	wait_return(void)
//{
//	std::cout << "\033[00;02;03m"
//	<< "Press any key to continue"
//	<< "\033[00m" << std::endl;
//	std::cin.get();
//}
