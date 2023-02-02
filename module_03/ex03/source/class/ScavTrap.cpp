/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:35:04 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/02 11:03:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[00;02;03m" << "ScavTrap : Default constructor called" << "\033[00m" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

/*   COPY   ***************************************************************** */

ScavTrap::ScavTrap(const ScavTrap &ScavTrap_src) : ClapTrap(ScavTrap_src.get__name())
{
	std::cout << "\033[32;02;03m" << "ScavTrap : Copy constructor called" << "\033[00m" << std::endl;
	(void) ScavTrap_src;
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
ScavTrap::~ScavTrap(void)
{
	std::cout << "\033[31;01m" << "ScavTrap : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   Opérateur																  */
/*                                                                            */
/* ************************************************************************** */

/*   INTERNE   *************************************************************** */

ScavTrap	&ScavTrap::operator=(const ScavTrap &right)
{
	std::cout << "\033[33;02;03m" << "ScavTrap : Copy assignment operator called" << "\033[00m" << std::endl;
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

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0)
	{
		std::cout << "\033[33m"
		<< "ScavTrap "
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
		<< "ScavTrap "
		<< "\033[33;01m"
			<< this->_name
				<< "\033[00m\033[33m"
		<< " has no energy to attack."
		<< "\033[00m" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "\033[33m"
	<< "ScavTrap "
	<< "\033[33;01m"
			<< this->_name
				<< "\033[00m\033[33m"
	<< " is in Gate keeper mode."
	<< "\033[00m" << std::endl;
}

/*   PRIVATE   ************************************************************** */

/* ************************************************************************** */
