/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/03 22:27:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

static void	wait_return(void);

int main(void)
{
	Animal	*tab_animal[10];

	for (int i = 0; i < 5; i++)
		tab_animal[i] = new Dog();
	std::cout << std::endl;
	for (int i = 5; i < 10; i++)
		tab_animal[i] = new Cat();
	wait_return();
	for (int i = 0; i < 10; i++)
		delete tab_animal[i];
	wait_return();

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;

	return (0);
}

static void	wait_return(void)
{
	std::cout << "\033[00;02;03m"
	<< "Press any key to continue"
	<< "\033[00m" << std::endl;
	std::cin.get();
}
