/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/13 15:58:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

//static void	wait_return(void);

int main(void)
{
	Array<int>	new_empty_tab;
	Array<int>	new_tab(3);

	new_tab[0] = 0;
	new_tab[1] = 1;
	new_tab[2] = 2;

	std::cout << new_tab[0] << std::endl;
	std::cout << new_tab[1] << std::endl;
	std::cout << new_tab[2] << std::endl;

	Array<int>	copy_tab(new_tab);

	std::cout << copy_tab[0] << std::endl;
	std::cout << copy_tab[1] << std::endl;
	std::cout << copy_tab[2] << std::endl;
	return (0);
}

//static void	wait_return(void)
//{
//	std::cout << "\033[00;02;03m"
//	<< "Press any key to continue"
//	<< "\033[00m" << std::endl;
//	std::cin.get();
//}
