/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:18:42 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/09 12:22:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
PhoneBook::PhoneBook(void)
{
//	std::cout << "Consructeur PhoneBook" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
PhoneBook::~PhoneBook(void)
{
//	std::cout << "Destructeur PhoneBook" << std::endl;
	return ;
}

int	PhoneBook::size_contact(void)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (i < 8)
	{
		if (this->instance_contact[i].get_used())
			size++;
		i++;
	}
	return (size);
}

Contact	*PhoneBook::get_older_contact(void)
{
	int	i;
	int	stock;
	int	stock_min;

	i = 0;
	while (i < 8)
	{
		if (!this->instance_contact[i].get_used())
			return (&this->instance_contact[i]);
		i++;
	}

	i = 0;
	stock_min = 8;
	while (i < 8)
	{
		stock = this->instance_contact[i].get_used();
		if (stock)
			if (stock < stock_min)
				stock_min = stock;
		i++;
	}
	return (&this->instance_contact[stock_min - 1]);
}

void	PhoneBook::add_contact(void)
{
	Contact	*older_contact;

	older_contact = PhoneBook::get_older_contact();

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "first name : ";
	std::cin >> first_name;
	std::getline(std::cin, last_name);
	
	std::cout << "last name : ";
	std::getline(std::cin, last_name);

	std::cout << "nickname : ";
	std::cin >> nickname;
	std::getline(std::cin, phone_number);

	std::cout << "phone_number : ";
	std::cin >> phone_number;
	std::getline(std::cin, phone_number);

	std::cout << "darkest_secret : ";
	std::cin >> darkest_secret;
	std::getline(std::cin, darkest_secret);

	older_contact->add_contact(1, first_name, last_name, nickname, phone_number, darkest_secret);
}

void	PhoneBook::print_contact(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (this->instance_contact[i].get_used())
			this->instance_contact[i].print_content(i + 1);
		i++;
	}
}
