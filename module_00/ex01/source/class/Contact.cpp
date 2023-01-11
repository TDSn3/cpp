/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:12 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/11 14:03:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
Contact::Contact(void)
{
//	std::cout << "Consructeur Contact" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
Contact::~Contact(void)
{
//	std::cout << "Destructeur Contact" << std::endl;
	return ;
}

void	Contact::add_contact(
					std::string first_name,
					std::string last_name,
					std::string nickname,
					std::string phone_number,
					std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

void	Contact::print_content(int index)
{
	std::cout << "|" << std::setw(10) << index;

	if (this->first_name.size() > 10)
		std::cout << "|" << std::setw(9) << this->first_name.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << this->first_name;

	if (this->last_name.size() > 10)
		std::cout << "|" << std::setw(9) << this->last_name.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << this->last_name;

	if (this->nickname.size() > 10)
		std::cout << "|" << std::setw(9) << this->nickname.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << this->nickname;

	std::cout << "|" << std::endl;
}

void	Contact::print_all(void)
{
	std::cout << "first name : " << this->first_name << "\n";
	std::cout << "last name : " << this->last_name << "\n";
	std::cout << "nickname : " << this->nickname << "\n";
	std::cout << "phone number : " << this->phone_number << "\n";
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}
