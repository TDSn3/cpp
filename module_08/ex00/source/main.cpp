/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/15 15:51:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>
# include <vector>
# include <array>

//static void	wait_return(void);

int main(void)
{
	std::vector<int>				a;
	std::vector<int>::iterator		it_a;
	std::array<int, 3>				b;
	std::array<int, 3>::iterator	it_b;

	b[0] = 0;
	b[1] = 1;
	b[2] = 2;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);

	it_a = a.begin() + 2;
	it_b = &b[2];

	std::cout << "a : " << *it_a << std::endl;
	std::cout << "b : " << *it_b << std::endl;

	try
	{
		std::cout << "a easyfind 1 : " << *easyfind(a, 0) << std::endl;
		std::cout << "a easyfind 2 : " << *easyfind(a, 1) << std::endl;
		std::cout << "a easyfind 3 : " << *easyfind(a, 2) << std::endl;
		std::cout << "b easyfind 2 : " << *easyfind(b, 2) << std::endl;
		std::cout << "b easyfind 4 : " << *easyfind(b, 4) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception !" << std::endl;
	}

	return (0);
}

//static void	wait_return(void)
//{
//	std::cout << "\033[00;02;03m"
//	<< "Press any key to continue"
//	<< "\033[00m" << std::endl;
//	std::cin.get();
//}
