/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:41:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/11 13:59:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	print_start_title();

int	main(void)
{
	PhoneBook	instance_phone_book;
	std::string	stock;

	print_start_title();
	while (1)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		std::cout << "> ";
		std::getline(std::cin, stock);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		if (!stock.compare("ADD") || !stock.compare("SEARCH") || !stock.compare("EXIT"))
		{
			if (compare_menu(stock, &instance_phone_book))
				return (0);
		}
		else if (stock.size() > 0)
			std::cout << "command not found" << std::endl;
	}
	return (0);
}

static void	print_start_title()
{
	std::cout << "┌───────────────────────────────────────────┐\n";
	std::cout << "│                 Phone Book                │\n";
	std::cout << "├─────────────┬───────────────┬─────────────┤\n";
	std::cout << "│     ADD     │     SEARCH    │     EXIT    │\n";
	std::cout << "└─────────────┴───────────────┴─────────────┘" << std::endl;
}
