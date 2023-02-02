/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/02 17:19:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

void	wait_return(void);

int main(void)
{
	ScavTrap z("Chef villageois");
	ScavTrap y("Voleur");

	wait_return();

	for (int i = 0; i < 55; i++)
		z.attack("target");
	y.takeDamage(20 * 50);
	z.guardGate();

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