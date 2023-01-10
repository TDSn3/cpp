/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:12 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/10 12:42:13 by tda-silv         ###   ########.fr       */
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
	this->used = 0;
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

int	Contact::get_used(void)
{
	if (this->used)
		return (this->used);
	else
		return (0);
}

void	Contact::add_contact(
					int index,
					std::string first_name,
					std::string last_name,
					std::string nickname,
					std::string phone_number,
					std::string darkest_secret)
{
	this->used = index;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

void	Contact::print_content(int index)
{
/*	std::cout << "|" << std::setw(10) << index;

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

	if (this->phone_number.size() > 10)
		std::cout << "|" << std::setw(9) << this->phone_number.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << this->phone_number;

	if (this->darkest_secret.size() > 10)
		std::cout << "|" << std::setw(9) << this->darkest_secret.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << this->darkest_secret;
*/
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