/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_menu.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:57:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/11 13:58:15 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

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
		std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n";
		std::cout << "│    INDEX │    FIRST │     LAST │ NICKNAME │\n";
		std::cout << "│          │     NAME │     NAME │          │\n";
		std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;

		instance_phone_book->print_contact();

		std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n";
		std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;

		instance_phone_book->choice_index();

		std::cout << "┌───────────────────────────────────────────┐\n";
		std::cout << "└───────────────────────────────────────────┘" << std::endl;
	}
	else if (!str.compare("EXIT"))
	{
		std::cout << "┌───────────────────────────────────────────┐\n";
		std::cout << "│                    EXIT                   │\n";
		std::cout << "└───────────────────────────────────────────┘" << std::endl;
		return (1);
	}
	return (0);
}
