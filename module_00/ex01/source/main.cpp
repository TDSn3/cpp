/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:41:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/10 13:26:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	print_one_line(std::string str);
int		compare_menu(std::string str, PhoneBook *instance_phone_book);
void	print_start_title();

int	main(void)
{
	PhoneBook	instance_phone_book;
	std::string	stock;

	print_start_title();
	while (1)
	{
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

void	print_one_line(std::string str)
{
	if (str.size() > 10)
		std::cout << "|" << std::setw(9) << str.substr(0, 9) << "." << std::endl;
	else
		std::cout << "|" << std::setw(10) << str << std::endl;
}

int	compare_menu(std::string str, PhoneBook *instance_phone_book)
{
	if (!str.compare("ADD"))
	{
		std::cout << "┌───────────────────────────────────────────┐\n";
		std::cout << "│              ADD NEW CONTACT              │\n";
		std::cout << "└───────────────────────────────────────────┘" << std::endl;
		instance_phone_book->add_contact();
		std::cout << "┌───────────────────────────────────────────┐\n";
		std::cout << "└───────────────────────────────────────────┘" << std::endl;
	}
	else if (!str.compare("SEARCH"))
	{
//		std::cout << "size instance_contact : " << instance_phone_book->size_contact() << std::endl;
//		std::cout << "size older_contact : " << instance_phone_book->get_older_contact()->get_used() << std::endl;
		instance_phone_book->print_contact();
		instance_phone_book->choice_index();
	}
	else if (!str.compare("EXIT"))
	{
		std::cout << "┌───────────────────────────────────────────┐\n";
		std::cout << "│                    EXIT                   │\n";
		std::cout << "└───────────────────────────────────────────┘" << std::endl;
		return (1);
	}
//	print_one_line(str);
	return (0);
}

void	print_start_title()
{
	std::cout << "┌───────────────────────────────────────────┐\n";
	std::cout << "│                 Phone Book                │\n";
	std::cout << "├─────────────┬───────────────┬─────────────┤\n";
	std::cout << "│     ADD     │     SEARCH    │     EXIT    │\n";
	std::cout << "└─────────────┴───────────────┴─────────────┘" << std::endl;
}
