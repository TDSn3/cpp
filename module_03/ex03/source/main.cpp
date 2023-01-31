/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/31 16:57:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

void	wait_return(void);

int main(void)
{
	FragTrap a("Guerrier villageois");

	wait_return();

	for (int i = 0; i < 105; i++)
		a.attack("target");
	a.highFivesGuys();

	wait_return();

	return (0);
}

void	wait_return(void)
{
	std::cout << "\033[00;02;03m"
	<< "Press any key to continue."
	<< "\033[00m" << std::endl;
	std::cin.get();
}