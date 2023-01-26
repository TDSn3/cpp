/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/26 19:50:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

void	wait_return(void);

int main(void)
{
	ClapTrap a("Barbare");
	ClapTrap b("Villageois");

	for (int i = 0; i < 15; i++)
		ClapTrap::fight(a, b, 1);

	wait_return();

	b.beRepaired(10);
	ClapTrap::fight(a, b, 1);

	wait_return();

	for (int i = 0; i < 5; i++)
		ClapTrap::fight(b, a, 2);
		
	return (0);
}

void	wait_return(void)
{
	std::cout << "\033[00;02;03m"
	<< "Press any key to continue."
	<< "\033[00m" << std::endl;
	std::cin.get();
}