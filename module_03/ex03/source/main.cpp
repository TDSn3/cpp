/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/02 19:09:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

void	wait_return(void);

int main(void)
{
	DiamondTrap a("Paladin");

	wait_return();

	a.whoAmI();

	wait_return();

	a.attack("Ennemi");
	return (0);
}

void	wait_return(void)
{
	std::cout << "\033[00;02;03m"
	<< "Press any key to continue."
	<< "\033[00m" << std::endl;
	std::cin.get();
}