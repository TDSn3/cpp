/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/03 15:01:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

static void	wait_return(void);

int main(void)
{
	{
		Animal	a;
		Dog		rex;
		Cat		felix;
	
		rex.makeSound();
		felix.makeSound();

		wait_return();
		
		Animal	rex2 = rex;
		Animal	rex3;

		rex3 = rex;
		rex2.makeSound();
		rex3.makeSound();

		wait_return();

		Animal	&rex4 = rex;

		rex4.makeSound();

		wait_return();

		Animal	*rex5 = new Dog(rex);

		rex5->makeSound();
	}
	wait_return();

	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	wait_return();

	const WrongAnimal	*test = new WrongCat();

	test->makeSound();
	delete test;

	return (0);
}

static void	wait_return(void)
{
	std::cout << "\033[00;02;03m"
	<< "Press any key to continue"
	<< "\033[00m" << std::endl;
	std::cin.get();
}
