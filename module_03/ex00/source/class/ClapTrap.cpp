/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/26 09:02:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>
# include <iostream>
# include <string>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "\033[00;02;03m" << "Default constructor called" << "\033[00m" << std::endl;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

/*   COPY   ***************************************************************** */

ClapTrap::ClapTrap(const ClapTrap &ClapTrap_src)
{
	std::cout << "\033[32;02;03m" << "Copy constructor called" << "\033[00m" << std::endl;
	(void) ClapTrap_src;
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
ClapTrap::~ClapTrap(void)
{
	std::cout << "\033[31;01m" << "Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   Opérateur																  */
/*                                                                            */
/* ************************************************************************** */

/*   INTERNE   *************************************************************** */

ClapTrap	&ClapTrap::operator=(const ClapTrap &right)
{
	std::cout << "\033[33;02;03m" << "Copy assignment operator called" << "\033[00m" << std::endl;
	(void) right;
	return (*this);
}

/*   EXTERNE   ************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   PUBLIC   *************************************************************** */

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0)
	{
		std::cout << "\033[33m"
		<< "ClapTrap "
		<< "\033[33;01m"
			<< this->_name
				<< "\033[00m\033[33m"
		<< " attacks "
		<< "\033[33;01m"
			<< target
				<< "\033[00m\033[33m"
		<< ", causing " << this->_attack_damage << " points of damage!"
		<< "\033[00m" << std::endl;
		this->_energy_points--;
	}
	else
		std::cout << "\033[33m"
		<< "ClapTrap "
		<< "\033[33;01m"
			<< this->_name
				<< "\033[00m\033[33m"
		<< " has no energy to attack"
		<< "\033[00m" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\033[33;02m"
	<< "ClapTrap "
	<< "\033[33;01m"
		<< this->_name
			<< "\033[00m\033[33;02m"
	<< " take " << amount << " damages!" 
	<< "\033[00m" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0)
	{
		std::cout << "\033[34m"
		<< "ClapTrap " << this->_name << " regains " << amount << " energy points."
		<< "\033[00m" << std::endl;
		this->_energy_points--;
	}
	else
		std::cout << "\033[33m"
		<< "ClapTrap " << this->_name << " has no energy to repaire"
		<< "\033[00m" << std::endl;
}

std::string	ClapTrap::get__name(void)
{
	return (this->_name);
}

int	ClapTrap::get__energy_points(void)
{
	return (this->_energy_points);
}

/* static */ void	ClapTrap::fight(ClapTrap &attacker, ClapTrap &victim, int amount)
{
	if (attacker.get__energy_points() > 0)
	{
		attacker.attack(victim.get__name());
		victim.takeDamage(amount);
	}
	else
		attacker.attack(victim.get__name());
}

/*   PRIVATE   ************************************************************** */

/* ************************************************************************** */
