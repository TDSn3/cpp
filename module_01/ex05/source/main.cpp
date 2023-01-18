/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/18 14:46:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

int main(void)
{
	Harl	class_harl;

	class_harl.complain("1");
	class_harl.complain("2");
	class_harl.complain("3");
	class_harl.complain("4");
	
	std::cout << "------------" << std::endl;

	class_harl.complain("5");
	class_harl.complain("10000000");
	class_harl.complain("100000000000000000000000000");
	class_harl.complain("coucou");
	class_harl.complain("");

	std::cout << "------------" << std::endl;
	return (0);
}