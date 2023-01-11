/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:18:42 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/11 14:03:52 by tda-silv         ###   ########.fr       */
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

void	PhoneBook::add_contact(void)
{
	Contact	new_contact;

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "first name : ";
	std::getline(std::cin, first_name);
	if (std::cin.eof())
			std::cout << std::endl;
	
	std::cout << "last name : ";
	std::getline(std::cin, last_name);
	if (std::cin.eof())
			std::cout << std::endl;

	std::cout << "nickname : ";
	std::getline(std::cin, nickname);
	if (std::cin.eof())
			std::cout << std::endl;

	std::cout << "phone_number : ";
	std::getline(std::cin, phone_number);
	if (std::cin.eof())
			std::cout << std::endl;

	std::cout << "darkest_secret : ";
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof())
			std::cout << std::endl;

	new_contact.add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	this->list_contact.push_front(new_contact);
	if (this->list_contact.size() > 8)
		while (this->list_contact.size() > 8)
			this->list_contact.pop_back();
}

void	PhoneBook::print_contact(void)
{
	int								i;
	std::list<Contact>::iterator	it;

	i = 1;
	it = this->list_contact.end();
	if (this->list_contact.size() > 0)
	{
		it--;
		while (it != this->list_contact.begin())
		{
			it->print_content(i);
			i++;
			it--;
		}
		it->print_content(i);
	}
}

void	PhoneBook::print_one_contact(int index)
{
	int								i;
	std::list<Contact>::iterator	it;

	i = 1;
	it = this->list_contact.end();
	if (this->list_contact.size() > 0)
	{
		it--;
		while (it != this->list_contact.begin())
		{
			if (i == index)
			{
				it->print_all();
				return ;
			}
			i++;
			it--;
		}
		if (i == index)
		{
			it->print_all();
			return ;
		}
	}	
}

void	PhoneBook::choice_index(void)
{
	std::string	buff;
	int			index;

	index = 0;
	if (this->list_contact.size() > 0)
	{
		std::cout << "choice index : ";
		std::getline(std::cin, buff);
		if (std::cin.eof())
			std::cout << std::endl;
	}
	if (!buff.find_first_not_of("0123456789"))
		std::cout << "numeric argument required" << std::endl;
	else
	{
		index = std::atoi(buff.c_str());
		if (index < 1 || index > (int)this->list_contact.size())
			std::cout << "index not found" << std::endl;
		else
			PhoneBook::print_one_contact(index);
	}
}
