/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:00:39 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/16 08:18:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
HumanB::HumanB(void)
{
	std::cout << "Constructeur HumanB" << std::endl;
	this->_weapon = NULL;
	return ;
}

HumanB::HumanB(std::string name)
{
	std::cout << "Constructeur HumanB" << std::endl;
	this->_name = name;
	this->_weapon = NULL;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
HumanB::~HumanB(void)
{
	return ;
}

/* ************************************************************************** */

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &new_W)
{
	this->_weapon = &new_W;
}
